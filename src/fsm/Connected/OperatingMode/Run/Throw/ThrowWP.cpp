/*
 * Throw.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "ThrowWP.h"

ThrowWP::ThrowWP() {}

ThrowWP::~ThrowWP() {}

void ThrowWP::entry()
{
	std::cout << "ThrowWP entry" << std::endl;
	throwWP();
	data->eraseWp();
}

void ThrowWP::exit()
{
	std::cout << "ThrowWP exit" << std::endl;
	// throwWPOff();
}

bool ThrowWP::handleLbSwFree()
{
	exit();
	new (this) IdleThrow;
	entry();
	return true;
}

void ThrowWP::throwWP()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(THROW_WP), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

void ThrowWP::throwWPOff()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(SWITCH_OFF), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}


