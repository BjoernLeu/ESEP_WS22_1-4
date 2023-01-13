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
	std::cout << "SwitchStraight entry" << std::endl;
	data->setTime_lbSW_fast_min();
}

bool SwitchStraight::handleLbO()
{
	new (this) OutletStraight;
	entry();
	return true;
}