/*
 * SafeState.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "SafeState.h"

SafeState::SafeState() {}
SafeState::~SafeState() {}

void SafeState::entry()
{
	std::cout << "SafeState entry" << std::endl;
	if(data->getEstopSelf()){
		if (MsgSendPulse(coid, -1, static_cast<int>(ESTOP_SELF_PRESSED), 0) == -1) {
			perror("MsgSendPulse failed");
		}
	}else if(data->getEstopExt()){
		if (MsgSendPulse(coid, -1, static_cast<int>(ESTOP_EXT_PRESSED), 0) == -1) {
			perror("MsgSendPulse failed");
		}
	}else{
		std::cout << "Error! No ESTOP-Bool set!" << std::endl;
	}
}

bool SafeState::handleEstopSelfPressed()
{
	new (this) EstopSelf;
	entry();
	return true;
}

bool SafeState::handleEstopExtPressed()
{
	new (this) EstopExt;
	entry();
	return true;
}
