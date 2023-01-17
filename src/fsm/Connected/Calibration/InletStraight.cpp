/*
 * InletStraight.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: björn
 */

#include "InletStraight.h"

InletStraight::InletStraight() {}
InletStraight::~InletStraight() {}

void InletStraight::entry() 
{
	std::cout << "InletStraight entry" << std::endl;
	data->setTime_lbI_fast_min();
	data->motor = true;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

bool InletStraight::handleHsWP()
{
	new (this) HeightStraight;
	entry();
	return true;
}
