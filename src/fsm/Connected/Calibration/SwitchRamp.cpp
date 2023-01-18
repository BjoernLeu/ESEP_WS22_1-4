/*
 * SwitchRamp.cpp
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#include "SwitchRamp.h"

SwitchRamp::SwitchRamp() {}
SwitchRamp::~SwitchRamp() {}

void SwitchRamp::entry() 
{
	// std::cout << "SwitchRamp entry" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(PASS_WP), 0) == -1) {
			perror("MsgSendPulse failed");
	}
	data->setTime_lbSW_fast_max();
}

bool SwitchRamp::handleLbO()
{
	new (this) OutletRamp;
	entry();
	return true;
}
