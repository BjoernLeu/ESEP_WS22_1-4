/*
 * Run.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "Run.h"

Run::Run() {}

Run::~Run() {}

void Run::entry() 
{
	std::cout << "Run entry" << std::endl;
	motorOn();
	multiSubstateManage = new ManageWP();
	multiSubstateManage->setData(data);
	multiSubstateManage->entry();
	multiSubstateHeight = new IdleRun();
	multiSubstateHeight->setData(data);
	multiSubstateHeight->entry();
	multiSubstateMetal = new IdleMetal();
	multiSubstateMetal->setData(data);
	multiSubstateMetal->entry();
	multiSubstateThrow = new IdleThrow();
	multiSubstateThrow->setData(data);
	multiSubstateThrow->entry();
	multiSubstateSlide = new IdleSlide();
	multiSubstateSlide->setData(data);
	multiSubstateSlide->entry();
	multiSubstateTransfer = new Transfer();
	multiSubstateTransfer->setData(data);
	multiSubstateTransfer->entry();
}

void Run::exit() 
{
	std::cout << "Run exit" << std::endl;
	motorOff();
}

bool Run::entryHistory()
{
	std::cout << "Run HistoryEntry" << std::endl;
	if (multiSubstateManage->isSubEndState()) {
		entry();
	} else if (!multiSubstateManage->entryHistory()) {
		multiSubstateManage->entry();
	}

	if (multiSubstateHeight->isSubEndState()) {
		entry();
	} else if (!multiSubstateHeight->entryHistory()) {
		multiSubstateHeight->entry();
	}

	if (multiSubstateMetal->isSubEndState()) {
		entry();
	} else if (!multiSubstateMetal->entryHistory()) {
		multiSubstateMetal->entry();
	}

	if (multiSubstateThrow->isSubEndState()) {
		entry();
	} else if (!multiSubstateThrow->entryHistory()) {
		multiSubstateThrow->entry();
	}

	if (multiSubstateSlide->isSubEndState()) {
		entry();
	} else if (!multiSubstateSlide->entryHistory()) {
		multiSubstateSlide->entry();
	}

	if (multiSubstateTransfer->isSubEndState()) {
		entry();
	} else if (!multiSubstateTransfer->entryHistory()) {
		multiSubstateTransfer->entry();
	}

	return true;
}

bool Run::handleError()
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

bool Run::handleEmptyBelt() 
{
	exit();
	new (this) IdleRun();
	entry();
	return true;
}

bool Run::handleSignalReceipted() 
{
	substate->handleSignalReceipted();
	return true;
}

bool Run::handleThrown() 
{
	substate->handleThrown();
	return true;
}

bool Run::handleOutOfOrder() 
{
	substate->handleOutOfOrder();
	return true;
}

bool Run::handleFlat() 
{
	substate->handleFlat();
	return true;
}

bool Run::handleLbSwFree() 
{
	substate->handleLbSwFree();
	return true;
}

bool Run::handleLbSW() 
{
	substate->handleLbSW();
	return true;
}

bool Run::handleSlSelfFull() 
{
	substate->handleSlSelfFull();
	return true;
}

bool Run::handleSlBothFree() 
{
	substate->handleSlBothFree();
	return true;
}

bool Run::handleSlBothFull() 
{
	substate->handleSlBothFull();
	return true;
}

bool Run::handleSlExtFull() 
{
	substate->handleSlExtFull();
	return true;
}

bool Run::handleWPExpected() 
{
	substate->handleWPExpected();
	return true;
}

bool Run::handleSLSelfFree() 
{
	substate->handleSLSelfFree();
	return true;
}

bool Run::handleWpEarly() 
{
	substate->handleWpEarly();
	return true;
}

bool Run::handleWpLate() 
{
	substate->handleWpLate();
	return true;
}

bool Run::handleEarly() 
{
	substate->handleEarly();
	return true;
}

bool Run::handleLate() 
{
	substate->handleLate();
	return true;
}

bool Run::handleLbO() 
{
	substate->handleLbO();
	return true;
}

bool Run::handleLbSL() 
{
	substate->handleLbSL();
	return true;
}
bool Run::handleNoMetal() 
{
	substate->handleNoMetal();
	return true;
}

bool Run::handleHsBelt() 
{
	substate->handleHsBelt();
	return true;
}

bool Run::handleHsWP() 
{
	substate->handleHsWP();
	return true;
}

bool Run::handleMetalDetected() 
{
	substate->handleMetalDetected();
	return true;
}

bool Run::handleLbI() 
{
	substate->handleLbI();
	return true;
}

bool Run::handleInOrder() 
{
	substate->handleInOrder();
	return true;
}

bool Run::handleWpHigh(){
	substate->handleWpHigh();
	return true;
}

bool Run::handleWpFlat(){
	substate->handleWpFlat();
	return true;
}

bool Run::handleWpDrilling(){
	substate->handleWpDrilling();
	return true;
}

bool Run::handleWpID(){
	substate->handleWpID();
	return true;
}

void Run::motorOff() 
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

void Run::motorOn() 
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

bool Run::handleWpArrived()
{
	substate->handleWpArrived();
	return true;
}

bool Run::handleTransferOK()
{
	substate->handleTransferOK();
	return true;
}

bool Run::handleTransferWait()
{
	substate->handleTransferWait();
	return true;
}

bool Run::handleLbOFree()
{
	substate->handleLbOFree();
	return true;
}

bool Run::handleWpTransfer()
{
	substate->handleWpTransfer();
	return true;
}

bool Run::handleManageDone()
{
	substate->handleManageDone();
	return true;
}

bool Run::handleWpCode(int height){
	substate->handleWpCode(height);
	return true;
}

bool Run::handleWpDrilling(int height){
	substate->handleWpDrilling(height);
	return true;
}

bool Run::handleWpFlat(int height){
	substate->handleWpFlat(height);
	return true;
}

bool Run::handleWpHigh(int height){
	substate->handleWpHigh(height);
	return true;
}
