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
	std::cout << "MeasureHeight entry" << std::endl;
	substate->handleHsBelt();
	return true;
}

bool MeasureHeight::handleHsWP() 
{
	std::cout << "MeasureHeight entry" << std::endl;
	substate->handleHsWP();
	return true;
}

bool MeasureHeight::handleWpHigh()
{
	std::cout << "MeasureHeight entry" << std::endl;
	substate->handleWpHigh();
	return true;
}

bool MeasureHeight::handleWpFlat()
{
	std::cout << "MeasureHeight entry" << std::endl;
	substate->handleWpFlat();
	return true;
}

bool MeasureHeight::handleWpDrilling()
{
	std::cout << "MeasureHeight entry" << std::endl;
	substate->handleWpDrilling();
	return true;
}

bool MeasureHeight::handleWpID(){
	substate->handleWpID();
	return true;
}

bool MeasureHeight::handleWpCode(int height)
{
	std::cout << "MeasureHeight entry" << std::endl;
	substate->handleWpCode(height);
	return true;
}

bool MeasureHeight::handleWpDrilling(int height)
{
	std::cout << "MeasureHeight entry" << std::endl;
	substate->handleWpDrilling(height);
	return true;
}

bool MeasureHeight::handleWpFlat(int height)
{
	std::cout << "MeasureHeight entry" << std::endl;
	substate->handleWpFlat(height);
	return true;
}

bool MeasureHeight::handleWpHigh(int height)
{
	std::cout << "MeasureHeight entry" << std::endl;
	substate->handleWpHigh(height);
	return true;
}