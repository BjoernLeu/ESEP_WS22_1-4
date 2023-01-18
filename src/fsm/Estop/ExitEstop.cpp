/*
 * ExitEstop.cpp
 *
 *  Created on: Dec 8, 2022
 *      Author: daniel
 */

#include "ExitEstop.h"

ExitEstop::ExitEstop() {}
ExitEstop::~ExitEstop() {}

void ExitEstop::entry() 
{
	std::cout << "ExitEstop entry" << std::endl;
	data->setEstopSelfFalse();
	data->setEstopExtFalse();
	action->lightOn(RESET_LED);
}

bool ExitEstop::handleEstopExtPressed() 
{
	action->lightOff(RESET_LED);
	new (this) EstopExt;
	entry();
	return true;
}

bool ExitEstop::handleEstopSelfPressed() 
{
	action->lightOff(RESET_LED);
	new (this) EstopSelf;
	entry();
	return true;
}

bool ExitEstop::handleResetSp()
{
	action->lightOff(RED);
	if(data->getConnection()){
		new (this) SubEndState;
		entry();
		return true;
	}else{
		new (this) SubEndState;
		entry();
		return true;
	}
}
