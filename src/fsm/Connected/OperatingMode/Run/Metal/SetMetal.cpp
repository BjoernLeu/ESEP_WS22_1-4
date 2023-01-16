/*
 * SetMetal.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "SetMetal.h"

SetMetal::SetMetal() {}
SetMetal::~SetMetal() {}

void SetMetal::entry()
{
	std::cout << "SetMetal entry" << std::endl;
}

bool SetMetal::handleNoMetal()
{
	new (this) IdleMetal;
	entry();
	return true;
}

void SetMetal::setMType()
{
	data->addWpMetal();
	if (MsgSendPulse(coid, -1, static_cast<int>(WP_METAL), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}
