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
	std::cout << "IdleSlide entry" << std::endl;
	action->blinkingOn(YELLOW, SLOW);
}

bool SLExtBusy::handleSlExtFree()
{
	new (this) IdleSlide;
	entry();
	return true;
}

bool SLExtBusy::handleSlSelfFull()
{
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
	if (MsgSendPulse(coid, -1, static_cast<int>(EXT_FULL), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}
