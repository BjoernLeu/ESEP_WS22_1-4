/*
 * Idle.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "Idle.h"

void Idle::entry() 
{
	std::cout << "Connected/Idle entry" << std::endl;
	data->setLoadedConfFalse();
	loadConf();
}

void Idle::exit()
{
	action->blinkingOff(GREEN);
	action->lightOff(RESET_LED);
	action->lightOff(START_LED);
}

bool Idle::handleStartLp() 
{
	exit();
	new (this) ServiceMode();
	entry();
	return true;
}

bool Idle::handleStartSp() 
{
	std::cout << "conf: " << data->getLoadedConf() << std::endl;
	if(data->getLoadedConf()){
		exit();
		new (this) OperatingMode();
		entry();
		return true;
	}else{
		std::cout << "Config not loaded" << std::endl;
		return false;
	}
}

bool Idle::handleResetLp() 
{
	std::cout << "Connected/handleResetLp" << std::endl;
	exit();
	new (this) Calibration();
	entry();
	return true;
}

void Idle::loadConf() 
{
	std::cout << "Load config for workpieces..." << std::endl;
	// data->setLoadConfig();
    data->setLoadedConfTrue();
	std::cout << "Config for workpieces loaded." << std::endl;	
}
