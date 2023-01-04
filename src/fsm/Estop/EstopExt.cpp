/*
 * EstopExt.cpp
 *
 *  Created on: Dec 8, 2022
 *      Author: daniel
 */

#include "EstopExt.h"

EstopExt::EstopExt() {}
EstopExt::~EstopExt() {}

void EstopExt::entry() 
{
	std::cout << "EstopExt entry" << std::endl;
	
	if (MsgSendPulse(coid, -1, static_cast<int>(STOP_ALL), 0) == -1) {
		perror("MsgSendPulse failed");
	}

	data->setEstopExtTrue();
	data->setEstopSelfFalse();

	printEstopStates();
}

bool EstopExt::handleEstopExtReleased() 
{
	new (this) ExitEstop;
	entry();
	return true;
}

bool EstopExt::handleEstopSelfPressed() 
{
	new (this) EstopBoth;
	entry();
	return true;
}

bool EstopExt::handleConLost()
{
	new(this) ExitEstop;
	entry();
	return true;
}

void EstopExt::printEstopStates() 
{
	std::cout << "Estop_Self: " << data->getEstopSelf() << "; Estop_Ext: " << data->getEstopExt() << std::endl;
}