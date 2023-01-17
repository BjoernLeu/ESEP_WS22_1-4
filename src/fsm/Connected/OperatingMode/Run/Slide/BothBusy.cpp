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
}

bool BothBusy::handleWpExpected()
{
	replyBothFull();
	entry();
	return true;
}

bool BothBusy::handleSlSelfFree()
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

bool BothBusy::handleSlExtFree()
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

