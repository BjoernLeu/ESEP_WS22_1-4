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
	action->blinkingOn(YELLOW, SLOW);
}

bool SLSelfBusy::handleWpExpected()
{
	replySelfFull();
	return true;
}

bool SLSelfBusy::handleSlSelfFree()
{
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

void SLSelfBusy::replySelfFull()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(SELF_FULL), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}
