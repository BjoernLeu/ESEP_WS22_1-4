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

bool SLExtBusy::handleSLExtFree()
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

bool SLExtBusy::handleWPExpected()
{
	replyExtBusy();
	entry();
	return true;
}

void SLExtBusy::replyExtBusy() 
{
	
}