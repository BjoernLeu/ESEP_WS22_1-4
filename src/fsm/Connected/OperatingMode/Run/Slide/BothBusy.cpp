/*
 * BothBusy.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "BothBusy.h"

BothBusy::BothBusy() {}
BothBusy::~BothBusy() {}

bool BothBusy::handleWPExpected()
{
	replyBothBusy();
	entry();
	return true;
}

bool BothBusy::handleSLSelfFree()
{
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

bool BothBusy::handleSLExtFree()
{
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

