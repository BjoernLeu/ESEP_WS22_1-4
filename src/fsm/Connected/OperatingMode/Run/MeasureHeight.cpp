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

bool MeasureHeight::handleWpHigh(){
	substate->handleWpHigh();
	return true;
}

bool MeasureHeight::handleWpFlat(){
	substate->handleWpFlat();
	return true;
}

bool MeasureHeight::handleWpDrilling(){
	substate->handleWpDrilling();
	return true;
}

bool MeasureHeight::handleWpID(){
	substate->handleWpID();
	return true;
}