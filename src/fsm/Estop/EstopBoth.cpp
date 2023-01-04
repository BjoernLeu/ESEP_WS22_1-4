/*
 * Estop_Self.cpp
 *
 *  Created on: Dec 8, 2022
 *      Author: daniel
 */

#include "EstopBoth.h"

EstopBoth::EstopBoth() {}
EstopBoth::~EstopBoth() {}

void EstopBoth::entry() 
{
	std::cout << "EstopBoth entry" << std::endl;
	data->setEstopSelfTrue();
	data->setEstopExtTrue();
}

// bool EstopBoth::handleStopLp(){
// 	if (MsgSendPulse(coid, -1, static_cast<int>(ESTOP_EXT_RELEASED), 0) == -1) {
// 		perror("MsgSendPulse failed");
// 	}
// }

bool EstopBoth::handleEstopSelfReleased() 
{
	if(data->getConnection()){
		new (this) EstopExt;
		entry();
		return true;
	}else{
		new (this) ExitEstop;
		entry();
		return true;
	}
}

bool EstopBoth::handleEstopExtReleased() 
{
	new (this) EstopSelf;
	entry();
	return true;
}
