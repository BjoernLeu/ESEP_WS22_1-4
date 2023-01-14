/*
 * GoneUnreceipted.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "GoneUnreceipted.h"

GoneUnreceipted::GoneUnreceipted() {}

GoneUnreceipted::~GoneUnreceipted() {}

bool GoneUnreceipted::handlePrinted()
{
	exit();
	new(this) SubEndState;
	entry();
	return true;
}

void GoneUnreceipted::entry()
{
	std::cout << "GoneUnreceipted entry" << std::endl;
	blinkingOn(RED, SLOW, 30);
	printError();
}

void GoneUnreceipted::exit()
{
	std::cout << "GoneUnreceipted exit" << std::endl;
	motorOn();
}

void GoneUnreceipted::blinkingOn(int color, int speed, int seconds)
{
	std::cout << "this is blinking now" << std::endl;
}

void GoneUnreceipted::printError()
{
	std::cout << "Printed Error" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(PRINT_ERROR), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void GoneUnreceipted::motorOn()
{
	std::cout << "Motor On" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}