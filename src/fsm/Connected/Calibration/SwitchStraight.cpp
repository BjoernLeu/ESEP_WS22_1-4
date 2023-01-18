/*
 * SwitchStraight.cpp
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#include "SwitchStraight.h"

SwitchStraight::SwitchStraight() {}
SwitchStraight::~SwitchStraight() {}

void SwitchStraight::entry() 
{
	// std::cout << "SwitchStraight entry" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(PASS_WP), 0) == -1) {
			perror("MsgSendPulse failed");
	}
	data->setTime_lbSW_fast_min();
}

bool SwitchStraight::handleLbSwFree() {
	if (MsgSendPulse(coid, -1, static_cast<int>(PASS_WP_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
	return true;
}

bool SwitchStraight::handleLbO()
{
	new (this) OutletStraight;
	entry();
	return true;
}
