/*
 * IdleService.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "IdleService.h"

IdleService::IdleService() {}

IdleService::~IdleService() {}

void IdleService::entry()
{
	std::cout << "IdleService entry" << std::endl;
}

bool IdleService::handleResetSp() {
	std::cout << "ServiceMode/LoadConfigService" << std::endl;
	new(this) SubEndState;
	entry();
	return true;
}
