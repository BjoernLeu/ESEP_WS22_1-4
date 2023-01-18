/*
 * MeasureHighCali.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "MeasureHighCali.h"

MeasureHighCali::MeasureHighCali() {}
MeasureHighCali::~MeasureHighCali() {}

void MeasureHighCali::entry() 
{
	// std::cout << "MeasureHighCali entry" << std::endl;
	measureHigh();
}

bool MeasureHighCali::handleLbI()
{
	new (this) InletStraight;
	entry();
	return true;
}

void MeasureHighCali::measureHigh(){
	data->mp->setHigh();
}
