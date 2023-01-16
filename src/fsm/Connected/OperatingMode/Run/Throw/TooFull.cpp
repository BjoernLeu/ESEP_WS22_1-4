/*
 * TooFull.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "TooFull.h"

TooFull::TooFull() {}

TooFull::~TooFull() {}

void TooFull::entry()
{
	std::cout << "TooFull entry" << std::endl;
	sendError();
	action->blinkingOff(YELLOW);
}

bool TooFull::handleSignalReceipted()
{
	new (this) ThrowWP;
	entry();
	return true;
}

void TooFull::sendError()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(ERROR), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}
