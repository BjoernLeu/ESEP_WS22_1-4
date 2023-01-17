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
	action->lightOn(GREEN);
	substate = new IdleRun;
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

void OperatingMode::exit()
{
	std::cout << "OperatingMode exit" << std::endl;
	action->lightOff(GREEN);
}

// bool OperatingMode::entryHistory()
// {
// 	new(this) Run;
// 	entryHistory();
// 	return true;
// }

// bool OperatingMode::handleError()
// {
// 	std::cout << "Error" << std::endl;
// 	if (MsgSendPulse(coid, -1, static_cast<int>(ERROR), 0) == -1) {
// 			perror("MsgSendPulse failed");
// 	}

// 	exit();
// 	new(this) Error;
// 	entry();

// 	return true;
// }

bool OperatingMode::handleStopSp()
{
	std::cout << "Connected/handleStopSp" << std::endl;
	exit();
	new (this) Idle();
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

bool OperatingMode::handleSlBothFree() 
{
	substate->handleSlBothFree();
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

bool OperatingMode::handleSlSelfFull() 
{
	substate->handleSlSelfFull();
	return true;
}

bool OperatingMode::handleSlFree() 
{
	substate->handleSlFree();
	return true;
}

bool OperatingMode::handleSlBothFull() 
{
	substate->handleSlBothFull();
	return true;
}

bool OperatingMode::handleSlExtFull() 
{
	substate->handleSlExtFull();
	return true;
}

bool OperatingMode::handleWpExpected() 
{
	substate->handleWpExpected();
	return true;
}

bool OperatingMode::handleSlSelfFree() 
{
	substate->handleSlSelfFree();
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

bool OperatingMode::handleWpHigh(){
	substate->handleWpHigh();
	return true;
}

bool OperatingMode::handleWpFlat(){
	substate->handleWpFlat();
	return true;
}

bool OperatingMode::handleWpDrilling(){
	substate->handleWpDrilling();
	return true;
}

bool OperatingMode::handleWpID(){
	substate->handleWpID();
	return true;
}

bool OperatingMode::handleWpArrived()
{
	substate->handleWpArrived();
	return true;
}

bool OperatingMode::handleTransferOK()
{
	substate->handleTransferOK();
	return true;
}

bool OperatingMode::handleTransferWait()
{
	substate->handleTransferWait();
	return true;
}

bool OperatingMode::handleLbOFree()
{
	substate->handleLbOFree();
	return true;
}

bool OperatingMode::handleWpTransfer()
{
	substate->handleWpTransfer();
	return true;
}

bool OperatingMode::handleManageDone()
{
	substate->handleManageDone();
	return true;
}
