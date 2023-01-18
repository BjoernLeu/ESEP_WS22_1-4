/**
 * Hardware Abstraction Layer fuer Festo-Anlage mit Funktionen zum Ansprechen der Sensorik
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

//custom
#include "ISR.h"

#include "../utils/Events.h"
#include "../utils/Gpio.h"
#include "../dispatcher/Dispatcher.h"

/* My pulse codes */
#define PULSE_STOP_THREAD _PULSE_CODE_MINAVAIL + 1
#define PULSE_INTR_ON_PORT0 _PULSE_CODE_MINAVAIL + 2

ISR::ISR(const char* nameSend, const char* nameSend2) {
	ThreadCtl(_NTO_TCTL_IO, 0);
	if ((coid = name_open(nameSend, 0)) == -1) {
		perror("name_open failed");
		exit(EXIT_FAILURE);
	}

	if ((coid2 = name_open(nameSend2, 0)) == -1) {
		perror("name_open failed");
		exit(EXIT_FAILURE);
	}
}

void ISR::handle_pulse(_pulse msg) {
}

int ISR::startISR() {
	// Request interrupt and IO abilities.
	int procmgr_status = procmgr_ability(0,
	PROCMGR_ADN_ROOT | PROCMGR_AOP_ALLOW | PROCMGR_AID_INTERRUPT,
	PROCMGR_ADN_NONROOT | PROCMGR_AOP_ALLOW | PROCMGR_AID_INTERRUPT,
	PROCMGR_ADN_ROOT | PROCMGR_AOP_ALLOW | PROCMGR_AID_IO,
	PROCMGR_ADN_NONROOT | PROCMGR_AOP_ALLOW | PROCMGR_AID_IO,
	PROCMGR_AID_EOL);
	if (procmgr_status != EOK) {
		perror("Requested abilities failed or denied!");
		exit(EXIT_FAILURE);
	}

	InterruptEnable();			//Enables interrupts.

	/* ### Create channel ### */
	int chanID = ChannelCreate(0);//Create channel to receive interrupt pulse messages.
	if (chanID < 0) {
		perror("Could not create a channel!\n");
		return EXIT_FAILURE;
	}

	int conID = ConnectAttach(0, 0, chanID, _NTO_SIDE_CHANNEL, 0); //Connect to channel.
	if (conID < 0) {
		perror("Could not connect to channel!");
		return EXIT_FAILURE;
	}

	/* ### Register interrupts by OS. ### */
	struct sigevent intr_event;
	SIGEV_PULSE_INIT(&intr_event, conID, SIGEV_PULSE_PRIO_INHERIT,
			PULSE_INTR_ON_PORT0, 0);
	interruptID = InterruptAttachEvent(INTR_GPIO_PORT0, &intr_event, 0);
	if (interruptID < 0) {
		perror("Interrupt was not able to be attached!");
		return EXIT_FAILURE;
	}

	/* ### Configure registers to receive irq events. */
	uintptr_t port0BaseAddr = mmap_device_io(GPIO_REGISTER_LENGHT, GPIO_PORT0);

	// Enable interrupts on pins.
	out32((uintptr_t) port0BaseAddr + GPIO_IRQSTATUS_SET_1, IN_INLET);
	out32((uintptr_t) port0BaseAddr + GPIO_IRQSTATUS_SET_1, IN_SWITCH);
	out32((uintptr_t) port0BaseAddr + GPIO_IRQSTATUS_SET_1, IS_METAL);
	out32((uintptr_t) port0BaseAddr + GPIO_IRQSTATUS_SET_1, ACTIVE_SWITCH);
	out32((uintptr_t) port0BaseAddr + GPIO_IRQSTATUS_SET_1, LIMIT_SLIDE);
	out32((uintptr_t) port0BaseAddr + GPIO_IRQSTATUS_SET_1, IN_OUTLET);
	out32((uintptr_t) port0BaseAddr + GPIO_IRQSTATUS_SET_1, START);
	out32((uintptr_t) port0BaseAddr + GPIO_IRQSTATUS_SET_1, STOP);
	out32((uintptr_t) port0BaseAddr + GPIO_IRQSTATUS_SET_1, RESET);
	out32((uintptr_t) port0BaseAddr + GPIO_IRQSTATUS_SET_1, ESTOP);

	// Set irq event types.
	unsigned int temp;

	//Debounce for less flikcering
	temp = in32((uintptr_t)(GPIO_BANK_0+GPIO_DEBOUNCENABLE));
	temp |= START | STOP | RESET | ESTOP;
	out32((uintptr_t)(GPIO_BANK_0+GPIO_DEBOUNCENABLE), temp);
	out32((uintptr_t)(GPIO_BANK_0+GPIO_DEBOUNCINGTIME), DEBOUNCETIME);

	//	(for rising edge detection)
	temp = in32((uintptr_t) (port0BaseAddr + GPIO_RISINGDETECT));//Read current config.
	temp |= (IN_INLET | IN_SWITCH | IS_METAL | ACTIVE_SWITCH | LIMIT_SLIDE
			| IN_OUTLET | START | STOP | RESET | ESTOP);                  //Add desired pins.
	out32((uintptr_t) (port0BaseAddr + GPIO_RISINGDETECT), temp);//Write new config back.

	// 	(for falling edge detection)
	temp = in32((uintptr_t) (port0BaseAddr + GPIO_FALLINGDETECT));//Read current config.
	temp |= (IN_INLET | IN_SWITCH | IS_METAL | ACTIVE_SWITCH | LIMIT_SLIDE
			| IN_OUTLET | START | STOP | RESET | ESTOP);                  //Add desired pins.
	out32((uintptr_t) (port0BaseAddr + GPIO_FALLINGDETECT), temp);//Write new config back.

	/* ### Start thread for handling interrupt messages. */
	thread receivingThread = thread(&ISR::receivingRoutine, this, chanID);
	receivingThread.detach();
//	receivingThread.join();
	/* ### Cleaning up. */

	// Detach interrupts.
//	int intr_detach_status = InterruptDetach(interruptID);
//	if (intr_detach_status != EOK) {
//		perror("Detaching interrupt failed!");
//		exit(EXIT_FAILURE);
//	}

	// Stop receiving thread.
//	MsgSendPulse(conID, -1, PULSE_STOP_THREAD, 0); //using prio of calling thread.
//	receivingThread.join();

	// Close channel
//	int detach_status = ConnectDetach(conID);
//	if (detach_status != EOK) {
//		perror("Detaching channel failed!");
//		exit(EXIT_FAILURE);
//	}
//
//	int destroy_status = ChannelDestroy(chanID);
//	if (destroy_status != EOK) {
//		perror("Destroying channel failed!");
//		exit(EXIT_FAILURE);
//	}

	return EXIT_SUCCESS;
}

void ISR::receivingRoutine(int channelID) {
	ThreadCtl( _NTO_TCTL_IO, 0);	//Request IO privileges
	_pulse msg;
	receivingRunning = true;
	//printf("Message thread started.\n");
	while (receivingRunning) {
		int recvid = MsgReceivePulse(channelID, &msg, sizeof(_pulse), nullptr);
		if (recvid < 0) {
			perror("MsgReceivePulse failed!");
			exit(EXIT_FAILURE);
		}
		if (recvid == 0) {	//pulse received.
			//Stop thread while it blocks.
			if (msg.code == PULSE_STOP_THREAD) {
				//printf("Thread kill code received!\n");
				receivingRunning = false;
			}
			if (msg.code == PULSE_INTR_ON_PORT0) {
				handleInterrupt();
			}
			// Do not ignore OS pulses!
		}
	}
	//printf("Message thread stops...\n");
}

void ISR::handleInterrupt(void) {
	uintptr_t gpioBase = mmap_device_io(GPIO_REGISTER_LENGHT, GPIO_PORT0);
	unsigned int intrStatusReg = in32(uintptr_t(gpioBase + GPIO_IRQSTATUS_1));
	out32(uintptr_t(gpioBase + GPIO_IRQSTATUS_1), 0xffffffff);//clear all interrupts.
	InterruptUnmask(INTR_GPIO_PORT0, interruptID);			//unmask interrupt.

	for (int pin = 0; pin < 32; pin++) {
		unsigned int mask = (uint32_t) BIT_MASK(pin);
		if (intrStatusReg == mask) {
			int current_level = (in32((uintptr_t) gpioBase + GPIO_DATA_IN) >> pin) & 0x1;
			printf("Interrupt on pin %d, now %d\n", pin, current_level);
			
			switch (pin) {
			case P_IN_INLET:
				if (current_level) {
					this->send(coid, static_cast<int>(LB_I_FREE), 0);
				} else {
					std::cout << "LB_I" << std::endl;
					this->send(coid, static_cast<int>(LB_I), 0);
				}
				break;
			case P_IS_METAL:
				if (current_level) {
					this->send(coid, static_cast<int>(WP_METAL), 0);
				} else {
					this->send(coid, static_cast<int>(NO_METAL), 0);
				}
				break;
			case P_IN_SWITCH:
				if (current_level) {
					this->send(coid, static_cast<int>(LB_SW_FREE), 0);
				} else {
					this->send(coid, static_cast<int>(LB_SW), 0);
				}
				break;
			case P_ACTIVE_SWITCH:
				if (current_level) {
					this->send(coid, static_cast<int>(SWITCH_OPEN), 0);
				} else {
					this->send(coid, static_cast<int>(SWITCH_CLOSE), 0);
				}
				break;
			case P_LIMIT_SLIDE:
				if (current_level) {
					this->send(coid, static_cast<int>(LB_SL_FREE), 0);
					this->send(coid, static_cast<int>(LB_SL_SELF_FREE), 0);
					this->send(coid2, static_cast<int>(LB_SL_EXT_FREE), 0);
				} else {
					this->send(coid, static_cast<int>(LB_SL), 0);
					this->send(coid, static_cast<int>(LB_SL_SELF_FULL), 0);
					this->send(coid2, static_cast<int>(LB_SL_EXT_FULL), 0);
				}
				break;
			case P_IN_OUTLET:
				if (current_level) {
					this->send(coid, static_cast<int>(LB_O_FREE), 0);
				} else {
					this->send(coid, static_cast<int>(LB_O), 0);
				}
				break;
			case P_START:
				if (current_level) {
					time(&start_t_start);
					// this->send(coid, static_cast<int>(START_RELEASED), 0);
				} else {
					time(&end_t_start);
					diff_t_start = difftime(end_t_start, start_t_start);
					if (diff_t_start < 3) {
						std::cout << "START_SP" << std::endl;
						this->send(coid, static_cast<int>(START_SP), 0);
					} else {
						std::cout << "START_LP" << std::endl;
						this->send(coid, static_cast<int>(START_LP), 0);
					}
				}
				break;
			case P_STOP:
				if (current_level) {
					time(&end_t_stop);
					diff_t_stop = difftime(end_t_stop, start_t_stop);
					if (diff_t_stop < 3) {
						std::cout << "STOP_SP" << std::endl;
						this->send(coid, static_cast<int>(STOP_SP), 0);
					} else {
						std::cout << "STOP_LP" << std::endl;
						this->send(coid, static_cast<int>(STOP_LP), 0);
					}
				} else {
					time(&start_t_stop);
					// this->send(coid, static_cast<int>(STOP_RELEASED), 0);
				}
				break;
			case P_RESET:
				if (current_level) {
					time(&start_t_reset);
					// this->send(coid, static_cast<int>(RESET_RELEASED), 0);
				} else {
					time(&end_t_reset);
					diff_t_reset = difftime(end_t_reset, start_t_reset);
					if (diff_t_reset < 3) {
						std::cout << "RESET_SP" << std::endl;
						this->send(coid, static_cast<int>(RESET_SP), 0);
					} else {
						std::cout << "RESET_LP" << std::endl;
						this->send(coid, static_cast<int>(RESET_LP), 0);
					}
				}
				break;
			case P_ESTOP:
				if (current_level && (current_level != old_level)) {
//					this->send(coid, static_cast<int>(ESTOP1_DONE), 0);
					if (MsgSendPulse(coid, -1, ESTOP_SELF_RELEASED, 0) == -1) {
						perror("MsgSendPulse failed");
					}
					if (MsgSendPulse(coid2, -1, ESTOP_SELF_RELEASED, 0) == -1) {
						perror("MsgSendPulse failed");
					}
				} else {
//					this->send(coid, static_cast<int>(ESTOP1_PRESSED), 0);
					if (MsgSendPulse(coid, -1, ESTOP_SELF_PRESSED, 0) == -1) {
						perror("MsgSendPulse failed");
					}
					if (MsgSendPulse(coid2, -1, ESTOP_SELF_PRESSED, 0) == -1) {
						perror("MsgSendPulse failed");
					}
				}
				old_level = current_level;
				break;

			default:
				std::cout << "no valid pin";
			}

		}
	}
}
