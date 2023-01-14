/*
 * PendingUnreceipted.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "PendingUnreceipted.h"

PendingUnreceipted::PendingUnreceipted() {}

PendingUnreceipted::~PendingUnreceipted() {}

void PendingUnreceipted::entry()
{
	std::cout << "PendingUnreceipted entry" << std::endl;
	blinkingOn(RED, FAST);
	motorOff();
}

void PendingUnreceipted::exit()
{
	std::cout << "PendingUnreceipted exit" << std::endl;
	blinkingOff(RED);
}

bool PendingUnreceipted::handleErrorGone()
{
	exit();
	new (this) GoneUnreceipted();
	entry();
	return true; 
}

bool PendingUnreceipted::handleResetSp()
{
	if(data->getAppeared()){
		exit();
		new (this) WPAppeared();
		entry();
		return true;
	}else if (data->getDissapeared()){
		exit();
		new (this) WPDisappeared();
		entry();
		return true;
	}else{
		exit();
		new (this) GoneReceipted();
		entry();
		return true;
	}

}

void PendingUnreceipted::blinkingOn(int color, int speed)
{
	std::cout << "this is blinking now" << std::endl;
}

void PendingUnreceipted::motorOff()
{
	std::cout << "Motor Off" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void PendingUnreceipted::blinkingOff(int color)
{
	std::cout << "this is not blinking now" << std::endl;
}