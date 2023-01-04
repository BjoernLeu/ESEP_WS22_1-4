/**
 * Hardware Abstraction Layer für Festo-Anlage mit Funktionen zum Ansprechen der Aktorik
 *
 * @author Björn Leuendorf 
 * @author Johannes Oehlers
 */

//custom
#include "Hal.h"

#include "../utils/Gpio.h"

Hal::Hal() {}
Hal::~Hal() {}

void Hal::init(){
	ThreadCtl( _NTO_TCTL_IO, 0);
	out32((uintptr_t) (GPIO_BANK_2 + 0x134), 0);
}

void Hal::motorOn() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_SET_DATA_OUT), MOTOR_RIGHT);
}

void Hal::motorOff() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_CLEAR_DATA_OUT), MOTOR_RIGHT);
}

void Hal::motorSlowOn() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_SET_DATA_OUT), MOTOR_SLOW);
}

void Hal::motorSlowOff() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_CLEAR_DATA_OUT), MOTOR_SLOW);
}

void Hal::motorStopOn() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_SET_DATA_OUT), MOTOR_STOP);
}

void Hal::motorStopOff() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_CLEAR_DATA_OUT), MOTOR_STOP);
}

void Hal::lightRedOn() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_SET_DATA_OUT), LIGHT_RED);
}

void Hal::lightRedOff() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_CLEAR_DATA_OUT), LIGHT_RED);
}

void Hal::lightYellowOn() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_SET_DATA_OUT), LIGHT_YELLOW);
}

void Hal::lightYellowOff() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_CLEAR_DATA_OUT), LIGHT_YELLOW);
}

void Hal::lightGreenOn() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_SET_DATA_OUT), LIGHT_GREEN);
}

void Hal::lightGreenOff() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_CLEAR_DATA_OUT), LIGHT_GREEN);
}

void Hal::switchOn() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_SET_DATA_OUT), OPEN_SWITCH);
}

void Hal::switchOff() {
	out32((uintptr_t) (GPIO_BANK_1 + GPIO_CLEAR_DATA_OUT), OPEN_SWITCH);
}

void Hal::ledStartOn() {
	out32((uintptr_t) (GPIO_BANK_2 + GPIO_SET_DATA_OUT), LED_START);
}

void Hal::ledStartOff() {
	out32((uintptr_t) (GPIO_BANK_2 + GPIO_CLEAR_DATA_OUT), LED_START);
}

void Hal::ledResetOn() {
	out32((uintptr_t) (GPIO_BANK_2 + GPIO_SET_DATA_OUT), LED_RESET);
}

void Hal::ledResetOff() {
	out32((uintptr_t) (GPIO_BANK_2 + GPIO_CLEAR_DATA_OUT), LED_RESET);
}

void Hal::signalFirstOn() {
	out32((uintptr_t) (GPIO_BANK_2 + GPIO_SET_DATA_OUT), SIGNAL_FIRST);
}

void Hal::signalFirstOff() {
	out32((uintptr_t) (GPIO_BANK_2 + GPIO_CLEAR_DATA_OUT), SIGNAL_FIRST);
}

void Hal::signalSecondOn() {
	out32((uintptr_t) (GPIO_BANK_2 + GPIO_SET_DATA_OUT), SIGNAL_SECOND);
}

void Hal::signalSecondOff() {
	out32((uintptr_t) (GPIO_BANK_2 + GPIO_CLEAR_DATA_OUT), SIGNAL_SECOND);
}
