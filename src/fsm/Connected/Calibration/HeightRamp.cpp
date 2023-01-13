/*
 * HeightRamp.cpp
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#include "HeightRamp.h"

HeightRamp::HeightRamp() {}
HeightRamp::~HeightRamp() {}

void HeightRamp::entry() 
{
	std::cout << "HeightRamp entry" << std::endl;
	data->setTime_hsWP_fast_max();
}

bool HeightRamp::handleLbSW()
{
	new (this) SwitchRamp;
	entry();
	return true;
}
