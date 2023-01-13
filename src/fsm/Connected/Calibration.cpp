/*
 * Calibration.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "Calibration.h"

Calibration::Calibration() {}
Calibration::~Calibration() {}

void Calibration::entry() 
{
	std::cout << "Calibration entry" << std::endl;
	action->blinkingOn(YELLOW, SLOW);
	substate = new IdleCali;
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

bool Calibration::handleResetSp() 
{
	substate->handleResetSp();

	if(substate->isSubEndState()){
		// std::cout << "handleResetSp" << std::endl;
		action->blinkingOff(YELLOW);
		new (this) Idle;
		entry();
	}
	return true;
}

//Transitions
bool Calibration::handleLbI()
{
	substate->handleLbI();
	return true;
}

bool Calibration::handleHsWP()
{
	substate->handleHsWP();
	return true;
}

bool Calibration::handleLbSW()
{
	substate->handleLbSW();
	return true;
}

bool Calibration::handleLbO()
{
	substate->handleLbO();
	return true;
}

bool Calibration::handleCalcDone()
{
	substate->handleCalcDone();
	return true;
}

bool Calibration::handleStartSp()
{
	
	substate->handleStartSp();
	return true;
}
