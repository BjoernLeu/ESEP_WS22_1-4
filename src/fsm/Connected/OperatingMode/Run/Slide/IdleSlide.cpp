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
	std::cout << "IdleSlide handleSlSelfFull" << std::endl;
	new (this) SLSelfBusy;
	entry();
	return true;
}

bool IdleSlide::handleWpExpected()
{
	std::cout << "IdleSlide handleWpExpected" << std::endl;
	replyBothFree();
	entry();
	return true;
}

bool IdleSlide::handleSlExtFull()
{
	std::cout << "IdleSlide handleSlExtFull" << std::endl;
	new (this) SLExtBusy;
	entry();
	return true;
}

void IdleSlide::replyBothFree() 
{
	std::cout << "IdleSlide replyBothFree" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(BOTH_FREE), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}
