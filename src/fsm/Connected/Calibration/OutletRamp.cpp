/*
 * OutletRamp.cpp
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#include "OutletRamp.h"

OutletRamp::OutletRamp() {}
OutletRamp::~OutletRamp() {}

void OutletRamp::entry() 
{
	// std::cout << "OutletRamp entry" << std::endl;
	data->setTime_lbO_fast_max();
	data->motor = false;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

bool OutletRamp::handleLbI()
{
	new (this) InletSlow;
	entry();
	return true;
}
