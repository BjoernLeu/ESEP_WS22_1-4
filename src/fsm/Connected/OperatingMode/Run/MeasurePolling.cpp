/*
 * MeasurePolling.cpp
 *
 *  Created on: 19.12.2022
 *      Author: acx191
 */

#include "MeasurePolling.h"

// TODO needs clean up
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/dispatch.h>
#include <sys/neutrino.h>
#include <sys/procmgr.h>
#include <iostream>
#include <thread>
#include <chrono>

//#include "simqnxgpioapi.h"
//#include "simqnxirqapi.h"

#include <sys/mman.h>
#include <hw/inout.h>

/* Code configuration */
#define DEMO false			//true for demo time, false to spin forever.
#define DEMO_DURATION 60		//Duration of demo time in seconds.


/* GPIO port addresses (spruh73l.pdf S.177 ff.) */
#define GPIO_PORT0 0x44E07000
#define GPIO_PORT1 0x4804C000
#define GPIO_PORT2 0x481AC000
#define ADC_BASE 0x44E0D000

/* GPIO port registers length */
#define GPIO_REGISTER_LENGHT 0x1000
#define ADC_LENGTH 0x2000

/* GPIO register offsets (spruh73l.pdf S.4877) */
#define GPIO_DATAIN 0x138
#define GPIO_SETDATAOUT 0x194

/* TSC_ADC register offsets (spruh73l.pdf S.1747) */
#define ADC_IRQ_ENABLE_SET 0x2c
#define ADC_IRQ_ENABLE_CLR 0x30
#define ADC_IRQ_STATUS 0x28
#define ADC_CTRL 0x40
#define ADC_DATA 0x100

/* ADC irq pin mask */
#define ADC_IRQ_PIN_MASK 0x2

/* Actuators pin mapping (Aufgabenbeschreibung o. Schaltplan) */
#define MOTOR_RIGHT_PIN 12
#define MOTOR_SLOW_PIN 14
#define MOTOR_STOP_PIN 15

/* Helper macros */
#define BIT_MASK(x) (0x1 << (x))

/* My pulse codes */
#define PULSE_STOP_THREAD _PULSE_CODE_MINAVAIL + 1
#define PULSE_ADC_SAMLING_DONE _PULSE_CODE_MINAVAIL + 2

using namespace std;

/* Varialbes */
bool receivingRunning = false;
bool sampling = false;
ADC* adc;
//int adcValue;
thread receivingThread;
int chanID;
int chanID2;
int conID;
int conID2;
TSCADC tsc;

std::condition_variable adc_v;
std::mutex adc_m;

/* Function declaration */
//void receivingRoutine(int channelID,ADC* adc);

MeasurePolling::MeasurePolling(const char* nameSend) {
	if ((coid = name_open(nameSend, 0)) == -1) {
		perror("name_open failed");	//loglevel replace
		exit(EXIT_FAILURE);
	}
}


//maybe
void MeasurePolling::setZero() {
	adc->sample();
	std::unique_lock<std::mutex> lk(adc_m);
	adc_v.wait(lk);
	zero = adcValue;
	std::cout << "Zero set at: " << zero << std::endl;
}

void MeasurePolling::setHigh() {
	adc->sample();
	std::unique_lock<std::mutex> lk(adc_m);
	adc_v.wait(lk);
	high = zero - adcValue;
	binaryZero = high * 0.85;
	binaryOne = high * 0.75;
	hole = high * 0.3;
	factor = 25.0 / high;
	std::cout << "High set at: " << high << std::endl;
	sampling = true;
	adc->sample();
}

void MeasurePolling::init() {		//start in construcotr maybe

	/* ### Create channel ### */
	chanID = ChannelCreate(0); //Create channel to receive interrupt pulse messages.
	if (chanID < 0) {
		perror("Could not create a channel!\n");
		//return EXIT_FAILURE;
	}

	conID = ConnectAttach(0, 0, chanID, _NTO_SIDE_CHANNEL, 0); //Connect to channel.
	if (conID < 0) {
		perror("Could not connect to channel!");
		//return EXIT_FAILURE;
	}

	adc = new ADC(tsc);

	adc->registerAdcISR(conID, PULSE_ADC_SAMLING_DONE);

	/* ### Start thread for handling interrupt messages. */
	receivingThread = thread(&MeasurePolling::receivingRoutine, this, chanID, adc);	//start this somewhere else maybe
}

/* ### Cleaning up ### */
int cleanUp() {

	// Detach interrupts.
	adc->adcDisable();
	adc->unregisterAdcISR();

	// Stop receiving thread.
	MsgSendPulse(conID, -1, PULSE_STOP_THREAD, 0); //using prio of calling thread.
	receivingThread.join();

	// Close channel
	int detach_status = ConnectDetach(conID);
	if (detach_status != EOK) {
		perror("Detaching channel failed!");
		exit(EXIT_FAILURE);
	}

	int destroy_status = ChannelDestroy(chanID);
	if (destroy_status != EOK) {
		perror("Destroying channel failed!");
		exit(EXIT_FAILURE);
	}
	//cout << "clean up successful" << endl;
	return EXIT_SUCCESS;
}

void MeasurePolling::receivingRoutine(int channelID, ADC* adc) {

	ThreadCtl( _NTO_TCTL_IO, 0);	//Request IO privileges for this thread.

	_pulse msg;
	receivingRunning = true;
	int diff = 0;
	int olddiff = 0;
//	bool typeNotDef = true;
	float height = 0;
	int type = 0;
	bool highFlag = false;
	bool drillFlag = false;
	bool codeFlag = false;
	bool slowFlag = false;

	printf("Message thread started.\n");

	while (receivingRunning) {
		int recvid = MsgReceivePulse(channelID, &msg, sizeof(_pulse), nullptr);
		if (recvid < 0) {
			perror("MsgReceivePulse failed!");
			exit(EXIT_FAILURE);
		}

		if (recvid == 0) {	//pulse received.

			//Stop thread while it blocks.
			if (msg.code == PULSE_STOP_THREAD) {
				printf("Thread kill code received!\n");
				receivingRunning = false;
				continue;
			}

			//ADC interrupt value.
			if (msg.code == PULSE_ADC_SAMLING_DONE) {
				//printf("Value from adc with value %d!\n", msg.value);
				adcValue = msg.value.sival_int;
				adc_v.notify_all();
				//MsgSendPulse(coid, -1, PULSE_ADC_SAMLING_DONE, adcValue);

			}
			if(sampling) {
				//TODO do evaluation shit here
				diff = std::floor((zero - adcValue) * factor + 0.5);
				if(diff != olddiff) {
					// std::cout << diff << std::endl;
					olddiff = diff;
				}
				if(slowFlag) {
					height = (height + diff) / 2.0;
				}


				switch(diff) {
				case -5 ... 5:
					//TODO WPList add type and height if existing
					if(type != 0) {
						std::cout << "WS is: " << type << " and " << height << " mm high" << std::endl;
						if (MsgSendPulse(coid, -1, type, (int)height) == -1) {
							perror("MsgSendPulse failed");
						}
						if (MsgSendPulse(coid, -1, HS_BELT, 0) == -1) {
							perror("MsgSendPulse failed");
						}
						height = 0;
						type = 0;
						drillFlag = false;
						highFlag = false;
						codeFlag = false;
						slowFlag = false;
					}
					break;
				case 6 ...10:
					if(highFlag) {
						drillFlag = true;
					}
					break;
				case 19 ... 23:
					if(highFlag) {
						type = WP_CODE;
						codeFlag = true;
					}else {
						if(!slowFlag) {
							std::cout << "HS_WP" << std::endl;
							if (MsgSendPulse(coid, -1, HS_WP, 0) == -1) {
								perror("MsgSendPulse failed");
							}
							slowFlag = true;
							height = diff;
						}
						type = WP_FLAT;
//						height = diff;
					}
					break;
				case 24 ... 26:
					if(drillFlag) {
						type = WP_DRILLING;
//						height = diff;
					}else if(codeFlag) {
//						height = diff;
					}else {
						if(!slowFlag) {
							std::cout << "HS_WP" << std::endl;
							if (MsgSendPulse(coid, -1, HS_WP, 0) == -1) {
								perror("MsgSendPulse failed");
							}
							slowFlag = true;
							height = diff;
						}
						highFlag = true;
						type = WP_HIGH;
//						height = diff;
					}
					break;
				}

			// Do not ignore OS pulses!
			usleep(50000);
			adc->sample();
			}
		}
	}

	printf("Message thread stops...\n");
}

MeasurePolling::~MeasurePolling() {
	cleanUp();
}
