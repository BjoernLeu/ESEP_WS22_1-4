/*
 * CountDown.cpp
 *
 *  Created on: Dec 07, 2022
 *      Author: daniel
 */

#include "MeasureHeight.h"

MeasureHeight::MeasureHeight() {}
MeasureHeight::~MeasureHeight() {}

void MeasureHeight::entry() {
	std::cout << "MeasureHeight entry" << std::endl;
	substate = new IdleMeasureHeight;
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

bool MeasureHeight::handleHsBelt() 
{
	substate->handleHsBelt();
	return true;
}

bool MeasureHeight::handleHsWP() 
{
	substate->handleHsWP();
	return true;
}

bool MeasureHeight::handleWpCode(int height)
{
	substate->handleWpCode(height);
	return true;
}

bool MeasureHeight::handleWpDrilling(int height)
{
	substate->handleWpDrilling(height);
	return true;
}

bool MeasureHeight::handleWpFlat(int height)
{
	substate->handleWpFlat(height);
	return true;
}

bool MeasureHeight::handleWpHigh(int height)
{
	substate->handleWpHigh(height);
	return true;
}