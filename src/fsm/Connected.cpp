/*
 * Connected.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "Connected.h"

Connected::Connected() {}
Connected::~Connected() {}

void Connected::entry() 
{
	// std::cout << "Connected entry" << std::endl;

	if (MsgSendPulse(coid, -1, static_cast<int>(CHECK_ESTOP), 0) == -1) {
			perror("MsgSendPulse failed");
	}

	if(data->getEstopSelf()) {
		if (MsgSendPulse(coid, -1, static_cast<int>(ESTOP_SELF_PRESSED), 0) == -1) {
				perror("MsgSendPulse failed");
		}
		if (MsgSendPulse(coidExt, -1, static_cast<int>(ESTOP_SELF_PRESSED), 0) == -1) {
				perror("MsgSendPulse failed");
		}
	}


//	exit();
	

	substate = new Idle;
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

void Connected::exit() 
{
	std::cout << "Connected exit" << std::endl;
	motorOff();
	switchOff();
	action->lightOff(START_LED);
	action->lightOff(RESET_LED);
	action->lightOff(Q1);
	action->lightOff(Q2);
}

bool Connected::handleConLost() 
{
	data->setConnectionFalse();
	exit();
	new (this) Connecting;
	entry();
	return true;
}

bool Connected::handleEstopSelfPressed()
{
	std::cout << "Handleing EstopSelfPressed" << std::endl;
	data->setEstopSelfTrue();
	exit();
	new (this) Estop;
	entry();
	return true;
}

bool Connected::handleEstopExtPressed()
{
	std::cout << "Handleing EstopExtPressed" << std::endl;
	data->setEstopExtTrue();
	exit();
	new (this) Estop;
	entry();
	return true;
}

void Connected::motorOff(){
	data->motor = false;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void Connected::switchOff(){
	if (MsgSendPulse(coid, -1, static_cast<int>(SWITCH_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

bool Connected::handleLbI()
{
	substate->handleLbI();
	return true;
}

bool Connected::handleHsWP()
{
	substate->handleHsWP();
	return true;
}

bool Connected::handleManageDone()
{
	substate->handleManageDone();
	return true;
}

bool Connected::handleCalcDone() 
{
	substate->handleCalcDone();
	return true;
}

bool Connected::handleStartSp() 
{
	substate->handleStartSp();
	return true;
}

bool Connected::handlePrinted() 
{
	substate->handlePrinted();
	return true;
}

bool Connected::handleErrorGone()
{
	substate->handleErrorGone();
	return true;
}

bool Connected::handleStartLp()
{
	substate->handleStartLp();
	return true;
}

bool Connected::handleResetLp()
{
	substate->handleResetLp();
	return true;
}

bool Connected::handleError()
{
	substate->handleError();
	return true;
}

bool Connected::handleSignalReceipted()
{
	substate->handleSignalReceipted();
	return true;
}

bool Connected::handleOutOfOrder()
{
	substate->handleOutOfOrder();
	return true;
}

bool Connected::handleFlat()
{
	substate->handleFlat();
	return true;
}

bool Connected::handleLbSW()
{
	substate->handleLbSW();
	return true;
}

bool Connected::handleLbSwFree()
{
	substate->handleLbSwFree();
	return true;
}

bool Connected::handleSlBothFree()
{
	substate->handleSlBothFree();
	return true;
}

bool Connected::handleSlSelfFull()
{
	substate->handleSlSelfFull();
	return true;
}

bool Connected::handleSlExtFull()
{
	substate->handleSlExtFull();
	return true;
}

bool Connected::handleSlFree(){
	substate->handleSlFree();
	return true;
}

bool Connected::handleSlBothFull(){
	substate->handleSlBothFull();
	return true;
}

bool Connected::handleSlExtFree()
{
	substate->handleSlExtFree();
	return true;
}

bool Connected::handleWpExpected()
{
	substate->handleWpExpected();
	return true;
}

bool Connected::handleSlSelfFree()
{
	substate->handleSlSelfFree();
	return true;
}

bool Connected::handleLbSL()
{
	substate->handleLbSL();
	return true;
}

bool Connected::handleLbO()
{
	substate->handleLbO();
	return true;
}

bool Connected::handleHsBelt()
{
	substate->handleHsBelt();
	return true;
}

bool Connected::handleNoMetal()
{
	substate->handleNoMetal();
	return true;
}

bool Connected::handleEmptyBelt()
{
	substate->handleEmptyBelt();
	return true;
}

bool Connected::handleInOrder()
{
	substate->handleInOrder();
	return true;
}

bool Connected::handleWpMetal()
{
	substate->handleWpMetal();
	return true;
}

bool Connected::handleResetSp()
{
	substate->handleResetSp();
	return true;
}

bool Connected::handleLoadingCompleted()
{
	substate->handleLoadingCompleted();
	return true;
}

bool Connected::handleWpArrived()
{
	substate->handleWpArrived();
	return true;
}

bool Connected::handleTransferOK()
{
	substate->handleTransferOK();
	return true;
}

bool Connected::handleTransferWait()
{
	substate->handleTransferWait();
	return true;
}

bool Connected::handleLbOFree()
{
	substate->handleLbOFree();
	return true;
}

bool Connected::handleWpTransfer()
{
	substate->handleWpTransfer();
	return true;
}

bool Connected::handleWpCode(int height){
	substate->handleWpCode(height);
	return true;
}

bool Connected::handleWpDrilling(int height){
	substate->handleWpDrilling(height);
	return true;
}

bool Connected::handleWpFlat(int height){
	substate->handleWpFlat(height);
	return true;
}

bool Connected::handleWpHigh(int height){
	substate->handleWpHigh(height);
	return true;
}
