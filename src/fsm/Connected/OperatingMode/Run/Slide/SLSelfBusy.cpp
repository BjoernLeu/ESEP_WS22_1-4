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
	// std::cout << "SLSelfBusy entry" << std::endl;
	data->setSlSelfTrue();
	action->blinkingOn(YELLOW, SLOW);
}


bool SLSelfBusy::handleSlSelfFree()
{
	data->setSlSelfFalse();
	new (this) IdleSlide;
	entry();
	return true;
}

bool SLSelfBusy::handleSlExtFull()
{
	data->setSlExtTrue();
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
