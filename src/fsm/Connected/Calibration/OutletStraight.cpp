/*
 * OutletStraight.cpp
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#include "OutletStraight.h"

OutletStraight::OutletStraight() {}
OutletStraight::~OutletStraight() {}

void OutletStraight::entry() 
{
	// std::cout << "OutletStraight entry" << std::endl;
	data->setTime_lbO_fast_min();
	data->motor = false;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

bool OutletStraight::handleLbI()
{
	new (this) InletRamp;
	entry();
	return true;
}
