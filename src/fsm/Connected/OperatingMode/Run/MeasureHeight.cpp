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
	std::cout << "MeasureHeight handleHsBelt" << std::endl;
	substate->handleHsBelt();
	return true;
}

bool MeasureHeight::handleHsWP() 
{
	std::cout << "MeasureHeight handleHsWP" << std::endl;
	substate->handleHsWP();
	return true;
}

bool MeasureHeight::handleWpCode(int height)
{
	std::cout << "MeasureHeight handleWpCode" << std::endl;
	substate->handleWpCode(height);
	return true;
}

bool MeasureHeight::handleWpDrilling(int height)
{
	std::cout << "MeasureHeight handleWpDrilling" << std::endl;
	substate->handleWpDrilling(height);
	return true;
}

bool MeasureHeight::handleWpFlat(int height)
{
	std::cout << "MeasureHeight handleWpFlat" << std::endl;
	substate->handleWpFlat(height);
	return true;
}

bool MeasureHeight::handleWpHigh(int height)
{
	std::cout << "MeasureHeight handleWpHigh" << std::endl;
	substate->handleWpHigh(height);
	return true;
}