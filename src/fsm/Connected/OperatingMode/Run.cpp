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
	multiSubstateHeight = new MeasureHeight();
	multiSubstateHeight->setData(data);
	multiSubstateHeight->entry();
	multiSubstateMetal = new MetalState();
	multiSubstateMetal->setData(data);
	multiSubstateMetal->entry();
	multiSubstateThrow = new Throw();
	multiSubstateThrow->setData(data);
	multiSubstateThrow->entry();
	multiSubstateSlide = new Slide();
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
	multiSubstateManage->handleSignalReceipted();
	multiSubstateThrow->handleSignalReceipted();
	multiSubstateSlide->handleSignalReceipted();
	return true;
}

bool Run::handleThrown() 
{
	multiSubstateManage->handleThrown();
	multiSubstateSlide->handleThrown();
	return true;
}

bool Run::handleOutOfOrder() 
{
	multiSubstateManage->handleOutOfOrder();
	multiSubstateThrow->handleOutOfOrder();
	multiSubstateSlide->handleOutOfOrder();
	return true;
}

bool Run::handleFlat() 
{
	multiSubstateManage->handleFlat();
	multiSubstateThrow->handleFlat();
	multiSubstateSlide->handleFlat();
	return true;
}

bool Run::handleLbSwFree() 
{
	multiSubstateManage->handleLbSwFree();
	multiSubstateThrow->handleLbSwFree();
	multiSubstateSlide->handleLbSwFree();
	return true;
}

bool Run::handleLbSW() 
{
	multiSubstateManage->handleLbSW();
	multiSubstateThrow->handleLbSW();
	multiSubstateSlide->handleLbSW();
	return true;
}

bool Run::handleSlSelfFull() 
{
	multiSubstateManage->handleSlSelfFull();
	multiSubstateThrow->handleSlSelfFull();
	multiSubstateSlide->handleSlSelfFull();
	return true;
}

bool Run::handleSlBothFree() 
{
	multiSubstateManage->handleSlBothFree();
	multiSubstateThrow->handleSlBothFree();
	multiSubstateSlide->handleSlBothFree();
	return true;
}

bool Run::handleSlBothFull() 
{
	multiSubstateManage->handleSlBothFull();
	multiSubstateThrow->handleSlBothFull();
	multiSubstateSlide->handleSlBothFull();
	return true;
}

bool Run::handleSlExtFull() 
{
	multiSubstateManage->handleSlExtFull();
	multiSubstateThrow->handleSlExtFull();
	multiSubstateSlide->handleSlExtFull();
	return true;
}

bool Run::handleWpExpected() 
{
	multiSubstateManage->handleWpExpected();
	multiSubstateSlide->handleWpExpected();
	return true;
}

bool Run::handleSlSelfFree() 
{
	multiSubstateManage->handleSlSelfFree();
	multiSubstateSlide->handleSlSelfFree();
	return true;
}

bool Run::handleWpEarly() 
{
	multiSubstateManage->handleWpEarly();
	multiSubstateSlide->handleWpEarly();
	return true;
}

bool Run::handleWpLate() 
{
	multiSubstateManage->handleWpLate();
	multiSubstateSlide->handleWpLate();
	return true;
}

bool Run::handleEarly() 
{
	multiSubstateManage->handleEarly();
	multiSubstateSlide->handleEarly();
	return true;
}

bool Run::handleLate() 
{
	multiSubstateManage->handleLate();
	multiSubstateSlide->handleLate();
	return true;
}

bool Run::handleLbO() 
{
	multiSubstateManage->handleLbO();
	multiSubstateSlide->handleLbO();
	multiSubstateTransfer->handleLbO();		//good
	return true;
}

bool Run::handleLbSL() 
{
	multiSubstateManage->handleLbSL();
	multiSubstateSlide->handleLbSL();
	multiSubstateTransfer->handleLbSL();	//good
	return true;
}
bool Run::handleNoMetal() 
{
	multiSubstateManage->handleNoMetal();
	multiSubstateMetal->handleNoMetal();
	multiSubstateSlide->handleNoMetal();
	return true;
}

bool Run::handleHsBelt() 
{
	multiSubstateManage->handleHsBelt();
	multiSubstateHeight->handleHsBelt();	//good
	multiSubstateSlide->handleHsBelt();
	return true;
}

bool Run::handleHsWP() 
{
	multiSubstateManage->handleHsWP();
	multiSubstateHeight->handleHsWP();		//good
	multiSubstateSlide->handleHsWP();
	return true;
}

bool Run::handleMetalDetected() 
{
	multiSubstateManage->handleMetalDetected();
	multiSubstateMetal->handleMetalDetected();
	multiSubstateSlide->handleMetalDetected();
	return true;
}

bool Run::handleLbI() 
{
	multiSubstateManage->handleLbI();
	multiSubstateSlide->handleLbI();
	multiSubstateTransfer->handleLbI();		//good
	return true;
}

bool Run::handleInOrder() 
{
	multiSubstateManage->handleInOrder();
	multiSubstateThrow->handleInOrder();
	multiSubstateSlide->handleInOrder();
	return true;
}

bool Run::handleWpHigh(){
	multiSubstateManage->handleWpHigh();
	multiSubstateSlide->handleWpHigh();
	return true;
}

bool Run::handleWpFlat(){
	multiSubstateManage->handleWpFlat();
	multiSubstateSlide->handleWpFlat();
	return true;
}

bool Run::handleWpDrilling(){
	multiSubstateManage->handleWpDrilling();
	multiSubstateSlide->handleWpDrilling();
	return true;
}

bool Run::handleWpID(){
	multiSubstateManage->handleWpID();
	multiSubstateSlide->handleWpID();
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
	multiSubstateManage->handleWpArrived();
	multiSubstateSlide->handleWpArrived();
	multiSubstateTransfer->handleWpArrived();		//good
	return true;
}

bool Run::handleTransferOK()
{
	multiSubstateManage->handleTransferOK();
	multiSubstateSlide->handleTransferOK();
	multiSubstateTransfer->handleTransferOK();		//good
	return true;
}

bool Run::handleTransferWait()
{
	multiSubstateManage->handleTransferWait();
	multiSubstateSlide->handleTransferWait();
	multiSubstateTransfer->handleTransferWait();	//good
	return true;
}

bool Run::handleLbOFree()
{
	multiSubstateManage->handleLbOFree();
	multiSubstateSlide->handleLbOFree();
	multiSubstateTransfer->handleLbOFree();			//good
	return true;
}

bool Run::handleWpTransfer()
{
	multiSubstateManage->handleWpTransfer();
	multiSubstateSlide->handleWpTransfer();
	multiSubstateTransfer->handleWpTransfer();		//good
	return true;
}

bool Run::handleManageDone()
{
	multiSubstateManage->handleManageDone();
	multiSubstateSlide->handleManageDone();
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
