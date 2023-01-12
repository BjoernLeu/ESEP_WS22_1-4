/*
 * MeasurePolling.h
 *
 *  Created on: 19.12.2022
 *      Author: acx191
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREPOLLING_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREPOLLING_H_

#include <chrono>
#include <condition_variable>
#include <list>
#include <mutex>
#include <cmath>

#include "../../../../com/Communication.h"
#include "../../../../hal/adc/ADC_Sources/ADC.h"
#include "../../../../hal/adc/ADC_Sources/TSCADC.h"

class MeasurePolling {
public:
	MeasurePolling(const char* nameSend);
	~MeasurePolling();
	void init();
	void sample();
	int getHeight();
	int getConID();
	int getChanID();
	void setZero();
	void setHigh();
	//int cleanUp();
	//void receivingRoutine(int channelID, ADC* adc);
	void samepleLoop();
	std::list<int> meassure();
	std::thread receivingThread;
	int zero = 0;
	int high = 0;
	float factor = 0;
	int binaryZero = 0;
	int binaryOne = 0;
	int hole = 0;
private:
	void receivingRoutine(int channelID, ADC* adc);
	void handle_pulse(_pulse msg);
	name_attach_t *attach;
	int coid;
	int adcValue = 0;
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREPOLLING_H_ */
