/*
 * Pass.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "Pass.h"

Pass::Pass() {}

Pass::~Pass() {}

void Pass::entry()
{
	std::cout << "Pass entry" << std::endl;
	passWP();
}

bool Pass::handleLbSwFree()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(PASS_WP_OFF), 0) == -1) {
		perror("MsgSendPulse failed");
	}
	new(this) IdleThrow();
	entry();
	return true;
}

void Pass::passWP()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(PASS_WP), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

