/*
 * SL2Busy.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "SLExtBusy.h"

SLExtBusy::SLExtBusy() {}
SLExtBusy::~SLExtBusy() {}

void SLExtBusy::entry()
{
	std::cout << "SLExtBusy entry" << std::endl;
	data->setSlExtFalse();
	// action->blinkingOn(YELLOW, SLOW);
}

bool SLExtBusy::handleSlExtFree()
{
	if(data->getError()){
		data->clearVector();
		if (MsgSendPulse(coid, -1, static_cast<int>(ERROR_GONE), 0) == -1) {
			perror("MsgSendPulse failed");
		}
		if (MsgSendPulse(coidExt, -1, static_cast<int>(ERROR_GONE), 0) == -1) {
			perror("MsgSendPulse failed");
		}
	}
	data->setSlExtTrue();
	new (this) IdleSlide;
	entry();
	return true;
}

bool SLExtBusy::handleSlSelfFull()
{
	if (MsgSendPulse(coidExt, -1, static_cast<int>(LB_SL_EXT_FULL), 0) == -1) {
		perror("MsgSendPulse failed");
	}
	new (this) BothBusy;
	entry();
	return true;
}

bool SLExtBusy::handleWpExpected()
{
	replyExtFull();
	return true;
}

void SLExtBusy::replyExtFull() 
{
	if (MsgSendPulse(coid, -1, static_cast<int>(LB_SL_EXT_FULL), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}
