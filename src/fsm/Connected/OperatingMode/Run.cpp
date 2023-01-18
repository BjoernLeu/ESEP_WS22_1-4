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
	// std::cout << "Run entry" << std::endl;
	motorOn();
//	if (MsgSendPulse(coid, -1, static_cast<int>(LB_I), 0) == -1) {
//			perror("MsgSendPulse failed");
//	}
	multiSubstateManage = new ManageWP();
	multiSubstateManage->setData(data);
	multiSubstateManage->entry();
	multiSubstateHeight = new MeasureHeight();
	multiSubstateHeight->setData(data);
	multiSubstateHeight->entry();
	multiSubstateMetal = new MetalState();
	multiSubstateMetal->setData(data);
	multiSubstateMetal->entry();
	multiSubstateThrow = new Throw();
	multiSubstateThrow->setData(data);
	multiSubstateThrow->entry();
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

	if (multiSubstateTransfer->isSubEndState()) {
		entry();
	} else if (!multiSubstateTransfer->entryHistory()) {
		multiSubstateTransfer->entry();
	}

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
	multiSubstateThrow->handleSignalReceipted();
	return true;
}

bool Run::handleOutOfOrder() 
{
	multiSubstateThrow->handleOutOfOrder();
	return true;
}

bool Run::handleFlat() 
{
	multiSubstateThrow->handleFlat();
	return true;
}

bool Run::handleLbSwFree() 
{
	multiSubstateThrow->handleLbSwFree();
	return true;
}

bool Run::handleLbSW() 
{
	multiSubstateManage->handleLbSW();
	multiSubstateThrow->handleLbSW();

	return true;
}

bool Run::handleSlSelfFull() 
{
	multiSubstateThrow->handleSlSelfFull();
	return true;
}

bool Run::handleSlBothFree() 
{
	multiSubstateThrow->handleSlBothFree();
	return true;
}

bool Run::handleSlBothFull() 
{
	multiSubstateThrow->handleSlBothFull();
	return true;
}

bool Run::handleSlExtFull() 
{
	multiSubstateThrow->handleSlExtFull();
	return true;
}

bool Run::handleLbO() 
{
	multiSubstateManage->handleLbO();
	multiSubstateTransfer->handleLbO();		//good
	return true;
}

bool Run::handleLbSL() 
{
	multiSubstateTransfer->handleLbSL();	//good
	return true;
}
bool Run::handleNoMetal() 
{
	multiSubstateMetal->handleNoMetal();
	return true;
}

bool Run::handleHsBelt() 
{
	multiSubstateHeight->handleHsBelt();	//good
	return true;
}

bool Run::handleHsWP() 
{
	multiSubstateManage->handleHsWP();
	multiSubstateHeight->handleHsWP();		//good
	return true;
}

bool Run::handleWpMetal() 
{
	multiSubstateMetal->handleWpMetal();
	return true;
}

bool Run::handleLbI() 
{
	multiSubstateManage->handleLbI();
	multiSubstateTransfer->handleLbI();		//good
	return true;
}

bool Run::handleInOrder() 
{
	multiSubstateThrow->handleInOrder();
	return true;
}

void Run::motorOff() 
{
	data->motor = false;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

void Run::motorOn() 
{
	data->motor = true;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

bool Run::handleWpArrived()
{
	multiSubstateTransfer->handleWpArrived();		//good
	return true;
}

bool Run::handleTransferOK()
{
	multiSubstateTransfer->handleTransferOK();		//good
	return true;
}

bool Run::handleTransferWait()
{
	multiSubstateTransfer->handleTransferWait();	//good
	return true;
}

bool Run::handleLbOFree()
{
	multiSubstateTransfer->handleLbOFree();			//good
	return true;
}

bool Run::handleWpTransfer()
{
	multiSubstateTransfer->handleWpTransfer();		//good
	return true;
}

bool Run::handleManageDone()
{
	multiSubstateManage->handleManageDone();
	return true;
}

bool Run::handleWpCode(int height){
	multiSubstateHeight->handleWpCode(height);
	return true;
}

bool Run::handleWpDrilling(int height){
	multiSubstateHeight->handleWpDrilling(height);
	return true;
}

bool Run::handleWpFlat(int height){
	multiSubstateHeight->handleWpFlat(height);
	return true;
}

bool Run::handleWpHigh(int height){
	multiSubstateHeight->handleWpHigh(height);
	return true;
}
