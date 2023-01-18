/*
 * BothBusy.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "BothBusy.h"

BothBusy::BothBusy() {}
BothBusy::~BothBusy() {}

void BothBusy::entry(){
	std::cout << "BothBusy entry" << std::endl;
	data->setSlSelfFalse();
	data->setSlExtFalse();
	action->blinkingOff(YELLOW);
	action->blinkingOn(YELLOW, FAST);
}

bool BothBusy::handleWpExpected()
{
	std::cout << "BothBusy handleWpExpected" << std::endl;
	replyBothFull();
	return true;
}

bool BothBusy::handleSlSelfFree()
{
	if(data->getError()){
		if (MsgSendPulse(coid, -1, static_cast<int>(ERROR_GONE), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		if (MsgSendPulse(coidExt, -1, static_cast<int>(ERROR_GONE), 0) == -1) {
			perror("MsgSendPulse failed");
		}
	}
	if (data->getSlExt())
	{
		new (this) IdleSlide;
		entry();
		return true;
	}
	else 
	{
		new (this) SLExtBusy;
		entry();
		return true;
	}
}

bool BothBusy::handleSlExtFree()
{
	if(data->getError()){
		if (MsgSendPulse(coid, -1, static_cast<int>(ERROR_GONE), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		if (MsgSendPulse(coidExt, -1, static_cast<int>(ERROR_GONE), 0) == -1) {
			perror("MsgSendPulse failed");
		}
	}
	new (this) SLSelfBusy;
	entry();
	return true;
}

void BothBusy::replyBothFull()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(BOTH_FULL), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

