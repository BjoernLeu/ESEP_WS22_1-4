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
	// std::cout << "ServiceMode entry" << std::endl;
	action->blinkingOn(GREEN, SLOW);
	substate = new LoadConfigService();
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

void ServiceMode::exit() 
{
	// std::cout << "ServiceMode entry" << std::endl;
	action->blinkingOff(ALL);
}

bool ServiceMode::handleResetSp()
{
	// std::cout << "ServiceMode/handleResetSp" << std::endl;
	new (this) Idle();
	entry();
	return true;
}

bool ServiceMode::handleLoadingCompleted() 
{
	substate->handleLoadingCompleted();
	return true;
}
