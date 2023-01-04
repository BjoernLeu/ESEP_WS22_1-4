/*
 * ServiceMode.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "ServiceMode.h"

ServiceMode::ServiceMode() {}

ServiceMode::~ServiceMode() {}

void ServiceMode::entry() 
{
	std::cout << "ServiceMode entry" << std::endl;
	blinkingOn(GREEN, SLOW);
	substate = new LoadConfigService();
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

bool ServiceMode::handleResetSp()
{
	std::cout << "ServiceMode/handleResetSp" << std::endl;
	new (this) Idle();
	entry();
	return true;
}

void ServiceMode::exit() 
{
	std::cout << "ServiceMode entry" << std::endl;
	blinkingOff(GREEN);
}

void ServiceMode::blinkingOn(int color, int speed) 
{
	// TODO 
}

void ServiceMode::blinkingOff(int color) 
{
	// TODO 
}

bool ServiceMode::handleLoadingCompleted() 
{
	substate->handleLoadingCompleted();
	return true;
}