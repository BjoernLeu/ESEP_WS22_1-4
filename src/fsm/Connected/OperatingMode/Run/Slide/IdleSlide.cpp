/*
 * IdleSlide.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "IdleSlide.h"

IdleSlide::IdleSlide() {}
IdleSlide::~IdleSlide() {}

void IdleSlide::entry()
{
	std::cout << "IdleSlide entry" << std::endl;
	action->blinkingOff(YELLOW);
}

bool IdleSlide::handleSlSelfFull()
{
	new (this) SLSelfBusy;
	entry();
	return true;
}

bool IdleSlide::handleWPExpected()
{
	replyBothFree();
	entry();
}

bool IdleSlide::handleSlExtFull()
{
	new (this) SLExtBusy;
	entry();
	return true;
}

void IdleSlide::replyBothFree() 
{
	//ToDo: implement me
}
