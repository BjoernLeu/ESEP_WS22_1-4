/*
 * InletSlow.cpp
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#include "InletSlow.h"

InletSlow::InletSlow() {}
InletSlow::~InletSlow() {}

void InletSlow::entry() 
{
	std::cout << "InletSlow entry" << std::endl;
	data->setTime_lbI_slow();
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_SLOW_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

bool InletSlow::handleHsWP()
{
	new (this) HeightSlow;
	entry();
	return true;
}
