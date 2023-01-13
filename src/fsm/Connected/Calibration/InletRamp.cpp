/*
 * InletRamp.cpp
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#include "InletRamp.h"

InletRamp::InletRamp() {}
InletRamp::~InletRamp() {}

void InletRamp::entry() 
{
	std::cout << "InletRamp entry" << std::endl;
	data->setTime_lbI_fast_max();
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

bool InletRamp::handleHsWP()
{
	new (this) HeightRamp;
	entry();
	return true;
}
