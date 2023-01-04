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

// bool Idle::handleStartLp() 
// {
	// exit();
// 	new (this) ServiceMode();
// 	entry();
// 	return true;
// }

// bool Idle::handleStartSp() 
// {
// 	if(loadedConf){
		// exit();
// 		new (this) OperatingMode();
// 		entry();
// 		return true;
// 	}else{
// 		return false;
// 	}
// }

bool Idle::handleResetLp() 
{
	std::cout << "Connected/handleResetLp" << std::endl;
	exit();
	new (this) Calibration();
	entry();
	return true;
}

// bool Idle::handleLbSW()
// {
// 	std::cout << "Connected/handleLbSW" << std::endl;
// 	if (MsgSendPulse(coid, -1, static_cast<int>(THROW_WP), 0) == -1) {
// 			perror("MsgSendPulse failed");
// 	}
// 	return true;
// }

void Idle::loadConf() 
{
	std::cout << "Load config for workpieces..." << std::endl;
	//data->setLoadConfig();
	std::cout << "Config for workpieces loaded." << std::endl;	
}
