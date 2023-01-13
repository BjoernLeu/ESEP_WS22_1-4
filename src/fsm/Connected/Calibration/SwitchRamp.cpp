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
	std::cout << "SwitchRamp entry" << std::endl;
	data->setTime_lbSW_fast_max();
}

bool SwitchRamp::handleLbO()
{
	new (this) OutletRamp;
	entry();
	return true;
}
