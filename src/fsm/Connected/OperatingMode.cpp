/*
 * OperatingMode.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "OperatingMode.h"

OperatingMode::OperatingMode() {}

OperatingMode::~OperatingMode() {}

void OperatingMode::entry()
{
	std::cout << "OperatingMode entry" << std::endl;
	lightOn(GREEN);
}

void OperatingMode::exit()
{
	std::cout << "OperatingMode exit" << std::endl;
	lightOff(GREEN);
}


bool OperatingMode::entryHistory()
{
	new(this) Run;
	entryHistory();
	return true;
}

bool OperatingMode::handleStopSp()
{
	std::cout << "Connected/handleStopSp" << std::endl;
	exit();
	new (this) Idle();
	entry();
	return true;
}

bool OperatingMode::handleError()
{
	std::cout << "Error" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(ERROR), 0) == -1) {
			perror("MsgSendPulse failed");
	}

	exit();
	new(this) Error;
	entry();

	return true;
}

bool OperatingMode::handleSignalReceipted() 
{
	substate->handleSignalReceipted();
	return true;
}

bool OperatingMode::handleThrown() 
{
	substate->handleThrown();
	return true;
}

bool OperatingMode::handleOutOfOrder() 
{
	substate->handleOutOfOrder();
	return true;
}

bool OperatingMode::handleFlat() 
{
	substate->handleFlat();
	return true;
}

bool OperatingMode::handleLbSwFree() 
{
	substate->handleLbSwFree();
	return true;
}

bool OperatingMode::handleLbSW() 
{
	substate->handleLbSW();
	return true;
}

bool OperatingMode::handleSLSelfFull() 
{
	substate->handleSLSelfFull();
	return true;
}

bool OperatingMode::handleSlFree() 
{
	substate->handleSlFree();
	return true;
}

bool OperatingMode::handleBothFull() 
{
	substate->handleBothFull();
	return true;
}

bool OperatingMode::handleSLExtFull() 
{
	substate->handleSLExtFull();
	return true;
}

bool OperatingMode::handleWPExpected() 
{
	substate->handleWPExpected();
	return true;
}

bool OperatingMode::handleSLSelfFree() 
{
	substate->handleSLSelfFree();
	return true;
}

bool OperatingMode::handleSLbothFree() 
{
	substate->handleSLbothFree();
	return true;
}

bool OperatingMode::handleWpEarly() 
{
	substate->handleWpEarly();
	return true;
}

bool OperatingMode::handleWpLate() 
{
	substate->handleWpLate();
	return true;
}

bool OperatingMode::handleEarly()
{
	substate->handleEarly();
	return true;
}

bool OperatingMode::handleLate()
{
	substate->handleLate();
	return true;
}

bool OperatingMode::handleLbO()
{
	substate->handleLbO();
	return true;
}

bool OperatingMode::handleLbSL()
{
	substate->handleLbSL();
	return true;
}
bool OperatingMode::handleNoMetal() 
{
	substate->handleNoMetal();
	return true;
}

bool OperatingMode::handleHsBelt()
{
	substate->handleHsBelt();
	return true;
}

bool OperatingMode::handleHsWP()
{
	substate->handleHsWP();
	return true;
}

bool OperatingMode::handleEmptyBelt() 
{
	substate->handleEmptyBelt();
	return true;
}

bool OperatingMode::handleInOrder()
{
	substate->handleInOrder();
	return true;
}

bool OperatingMode::handleMetalDetected()
{
	substate->handleMetalDetected();
	return true;
}

bool OperatingMode::handleLbI()
{
	substate->handleLbI();
	return true;
}

void OperatingMode::lightOn(int color)
{
	//TODO
}

void OperatingMode::lightOff(int color)
{
	//TODO
}
