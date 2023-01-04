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
}

bool ExitEstop::handleEstopExtPressed() 
{
	new (this) EstopExt;
	entry();
	return true;
}

bool ExitEstop::handleEstopSelfPressed() 
{
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
