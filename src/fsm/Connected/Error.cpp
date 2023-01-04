/*
 * Error.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "Error.h"

Error::Error(){}
Error::~Error(){}

bool Error::entryHistory()
{
	new(this) OperatingMode;
	entryHistory();
	return true;
}

void Error::entry()
{
	std::cout << "Error entry" << std::endl;
	substate = new PendingUnreceipted;
	substate->setData(data);
	substate->entry();
}

bool Error::handleStartSp()
{
	new(this) OperatingMode;
	entryHistory();
	return true;
}

bool Error::handlePrinted()
{
	new(this) OperatingMode;
	entryHistory();
	return true;
}

bool Error::handleErrorGone()
{
	substate->handleErrorGone();
	return true;
}

bool Error::handleResetSp()
{
	substate->handleErrorGone();
	return true;
}


