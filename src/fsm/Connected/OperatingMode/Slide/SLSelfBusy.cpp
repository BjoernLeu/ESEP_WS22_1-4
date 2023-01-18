/*
 * SL1Busy.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "SLSelfBusy.h"

SLSelfBusy::SLSelfBusy() {}
SLSelfBusy::~SLSelfBusy() {}

void SLSelfBusy::entry()
{
	std::cout << "SLSelfBusy entry" << std::endl;
	data->setSlSelfFalse();
	action->blinkingOn(YELLOW, SLOW);
	if (MsgSendPulse(coidExt, -1, static_cast<int>(LB_SL_EXT_FULL), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}


bool SLSelfBusy::handleSlSelfFree()
{
	data->setSlSelfTrue();
	new (this) IdleSlide;
	entry();
	return true;
}

bool SLSelfBusy::handleSlExtFull()
{
	new (this) BothBusy;
	entry();
	return true;
}

bool SLSelfBusy::handleWpExpected()
{
	replySelfFull();
	return true;
}

void SLSelfBusy::replySelfFull()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(SELF_FULL), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}
