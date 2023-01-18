/*
 * Error.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "Error.h"

Error::Error(){}
Error::~Error(){}

// bool Error::entryHistory()
// {
// 	new(this) Run;
// 	//new(this) OperatingMode;
// 	entryHistory();
// 	return true;
// }

void Error::entry()
{
	std::cout << "Error entry" << std::endl;
	substate = new IdleError;
	substate->setData(data);
	substate->entry();
}

bool Error::handleStartSp()
{
	substate->handleStartSp();
	return true;
}

bool Error::handleErrorGone()
{
	substate->handleErrorGone();
	return true;
}

bool Error::handleResetSp()
{
	substate->handleResetSp();
	return true;
}

bool Error::handleError(){
	substate->handleError();
	return true;
}

bool Error::handlePrinted(){
	substate->handlePrinted();
	return true;
}


