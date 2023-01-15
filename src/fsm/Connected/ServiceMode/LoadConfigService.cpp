/*
 * LoadConfigService.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "LoadConfigService.h"

LoadConfigService::LoadConfigService() {}

LoadConfigService::~LoadConfigService() {}

void LoadConfigService::entry()
{
	std::cout << "LoadConfigService entry" << std::endl;
	loadCfg();
}

bool LoadConfigService::handleLoadingCompleted() 
{
	std::cout << "ServiceMode/IdleService" << std::endl;
	new (this) IdleService();
	entry();
	return true;
}

void LoadConfigService::loadCfg() 
{
	std::cout << "Service/Load config for workpieces..." << std::endl;
	data->setLoadConfig();
	std::cout << "Service/Config for workpieces loaded." << std::endl;	
}