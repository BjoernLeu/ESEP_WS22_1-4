/*
 * EstopSelf.cpp
 *
 *  Created on: Dec 8, 2022
 *      Author: daniel
 */

#include "EstopSelf.h"

EstopSelf::EstopSelf() {}
EstopSelf::~EstopSelf() {}

void EstopSelf::entry() 
{
	std::cout << "EstopSelf entry" << std::endl;
	
	if (MsgSendPulse(coid, -1, static_cast<int>(STOP_ALL), 0) == -1) {
		perror("MsgSendPulse failed");
	}

	data->setEstopSelfTrue();
	data->setEstopExtFalse();
	
	printEstopStates();
}

// bool EstopSelf::handleStopLp(){
// 	if (MsgSendPulse(coid, -1, static_cast<int>(ESTOP_EXT_PRESSED), 0) == -1) {
// 		perror("MsgSendPulse failed");
// 	}
// }

bool EstopSelf::handleEstopExtPressed() 
{
	new (this) EstopBoth;
	entry();
	return true;
}

bool EstopSelf::handleEstopSelfReleased() 
{
	new (this) ExitEstop;
	entry();
	return true;
}

void EstopSelf::printEstopStates() 
{
	std::cout << "Estop_Self: " << data->getEstopSelf() << "; Estop_Ext: " << data->getEstopExt() << std::endl;
}

