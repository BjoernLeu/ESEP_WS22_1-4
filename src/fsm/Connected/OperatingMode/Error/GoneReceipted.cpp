/*
 * GoneReceipted.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "GoneReceipted.h"

GoneReceipted::GoneReceipted() {}

GoneReceipted::~GoneReceipted() {}


void GoneReceipted::entry()
{
	std::cout << "GoneReceipted entry" << std::endl;
	action->lightOn(RED);
}

bool GoneReceipted::handleStartSp()
{
	exit();
	new(this) IdleError;
	entry();
	return true;
}

void GoneReceipted::exit()
{
	std::cout << "GoneReceipted exit" << std::endl;
	action->lightOff(RED);
	receipted();
	sendSignalSlide();
	// motorOn();
}

void GoneReceipted::receipted()
{
	std::cout << "receipted" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(RECEIPTED), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void GoneReceipted::sendSignalSlide()
{
	std::cout << "Send Signal to Slide" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(SEND_SIGNAL_SLIDE), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void GoneReceipted::motorOn()
{
	data->motor = true;
	std::cout << "Motor On" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}
