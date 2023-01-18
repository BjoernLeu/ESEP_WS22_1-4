/*
 * HeightStraight.cpp
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#include "HeightStraight.h"

HeightStraight::HeightStraight() {}
HeightStraight::~HeightStraight() {}

void HeightStraight::entry() 
{
	// std::cout << "HeightStraight entry" << std::endl;
	data->setTime_hsWP_fast_min();
}

bool HeightStraight::handleLbSW()
{
	// std::cout << "handleLbSW" << std::endl;
	new (this) SwitchStraight;
	entry();
	return true;
}
