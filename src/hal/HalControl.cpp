/**
 * HalControl.cpp
 *
 * @author Björn Leuendorf 
 */

// custom
#include "HalControl.h"

int HalControl::coid;
int HalControl::coidExt;
bool HalControl::switchType;

HalControl::HalControl(const char* nameReceive, const char* nameSend, const char* nameSend2) {
	if ((attach = name_attach(NULL, nameReceive, 0)) == NULL) {
		perror("name_attach failed");
	}
	if ((coid = name_open(nameSend, 0)) == -1) {
		perror("name_open failed");
		exit(EXIT_FAILURE);
	}
	if ((coidExt = name_open(nameSend2, 0)) == -1) {
		perror("name_open failed");
		exit(EXIT_FAILURE);
	}
	std::thread receivingThread(&HalControl::receive, this, attach);
	receivingThread.detach();
}

void HalControl::handle_pulse(_pulse msg) {
	Event event = static_cast<Event>(msg.code);
	switch (event) {
	case MOTOR_ON:
		Hal::motorOn();
		break;
	case MOTOR_OFF:
		Hal::motorOff();
		break;
	case MOTOR_STOP_ON:
		Hal::motorStopOn();
		break;
	case MOTOR_STOP_OFF:
		Hal::motorStopOff();
		break;
	case MOTOR_SLOW_ON:
		Hal::motorSlowOn();
		break;
	case MOTOR_SLOW_OFF:
		Hal::motorSlowOff();
		break;
	case SWITCH_OFF:
		Hal::switchOff();
		break;
	case LIGHT_RED_ON:
		Hal::lightRedOn();
		break;
	case LIGHT_RED_OFF:
		Hal::lightRedOff();
		break;
	case LIGHT_YELLOW_ON:
		Hal::lightYellowOn();
		break;
	case LIGHT_YELLOW_OFF:
		Hal::lightYellowOff();
		break;
	case LIGHT_GREEN_ON:
		Hal::lightGreenOn();
		break;
	case LIGHT_GREEN_OFF:
		Hal::lightGreenOff();
		break;
	case LED_START_ON:
		Hal::ledStartOn();
		break;
	case LED_START_OFF:
		Hal::ledStartOff();
		break;
	case LED_RESET_ON:
		Hal::ledResetOn();
		break;
	case LED_RESET_OFF:
		Hal::ledResetOff();
		break;
	case LIGHT_Q1_ON:
		Hal::signalFirstOn();
		break;
	case LIGHT_Q1_OFF:
		Hal::signalFirstOff();
		break;
	case LIGHT_Q2_ON:
		Hal::signalSecondOn();
		break;
	case LIGHT_Q2_OFF:
		Hal::signalSecondOff();
		break;
	case STOP_ALL:
		HalControl::saveState();
		break;
	case THROW_WP:
		HalControl::throwWP();
		break;
	case PASS_WP:
		HalControl::passWP();
		break;
	case SET_SW_TYPE:
		HalControl::setSwitchType();
		break;
	case CHECK_ESTOP:
		HalControl::getEstop();
		break;
	default:
		std::cout << "no valid event" << std::endl;
	}
}

/**
 * @brief Helper to simplify the Switch or Extruder throwing
 * 
 */
void HalControl::throwWP(){
	if(switchType){		//Extruder
		// std::cout << "switchOn" << std::endl;
		Hal::motorSlowOn();
		Hal::switchOn();
		usleep(50000);
		// std::cout << "switchOff" << std::endl;
		Hal::switchOff();
		Hal::motorSlowOff();
	}else{				//Switch
		//just let the WP slide down the Switch-Arm
	}
}

/**
 * @brief Helper to simplify the Switch or Extruder passing
 * 
 */
void HalControl::passWP(){
	if(switchType){
		//just let the WP pass the Extruder
	}else{
		Hal::switchOn();
		sleep(1);
		Hal::switchOff();
	}
}

/**
 * @brief Sets the Switch Type
 * 
 */
void HalControl::setSwitchType (){
	uintptr_t gpioBase = mmap_device_io(GPIO_REGISTER_LENGHT, GPIO_PORT0);
	int current_level = (in32((uintptr_t) gpioBase + GPIO_DATA_IN) >> 14) & 0x1;

	if(current_level)
	{
		switchType = true;
	}else{
		switchType = false;
	}
}

void HalControl::getEstop() {
	uintptr_t gpioBase = mmap_device_io(GPIO_REGISTER_LENGHT, GPIO_PORT0);
	int current_level = (in32((uintptr_t) gpioBase + GPIO_DATA_IN) >> 27) & 0x1;
	if(current_level == 0) {
		if (MsgSendPulse(coid, -1, static_cast<int>(ESTOP_SELF_PRESSED), 0) == -1) {
				perror("MsgSendPulse failed");
		}
		if (MsgSendPulse(coidExt, -1, static_cast<int>(ESTOP_SELF_PRESSED), 0) == -1) {
				perror("MsgSendPulse failed");
		}
	}
}

/**
 * @brief Methode um die Anlage in einen sicheren Zustand zu bringen
 * 
 */
void HalControl::saveState(){
	Hal::motorOff();
	Hal::lightGreenOff();
	Hal::lightYellowOff();
}
