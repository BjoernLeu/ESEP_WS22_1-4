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

bool SLSelfBusy::handleWPExpected()
{
	replySelfBusy();
	entry();
}

bool SLSelfBusy::handleSLSelfFree()
{
	new (this) IdleSlide;
	entry();
	return true;
}

bool SLSelfBusy::handleSLExtFull()
{
	new (this) BothBusy;
	return true;
}

void SLSelfBusy::replySelfBusy()
{
	// ToDo: Implement me
}
