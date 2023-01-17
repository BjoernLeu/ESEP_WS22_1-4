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
	multiSubstateHeight->handleSignalReceipted();
	multiSubstateMetal->handleSignalReceipted();
	multiSubstateThrow->handleSignalReceipted();
	multiSubstateSlide->handleSignalReceipted();
	multiSubstateTransfer->handleSignalReceipted();
	return true;
}

bool Run::handleThrown() 
{
	multiSubstateManage->handleThrown();
	multiSubstateHeight->handleThrown();
	multiSubstateMetal->handleThrown();
	multiSubstateThrow->handleThrown();
	multiSubstateSlide->handleThrown();
	multiSubstateTransfer->handleThrown();
	return true;
}

bool Run::handleOutOfOrder() 
{
	multiSubstateManage->handleOutOfOrder();
	multiSubstateHeight->handleOutOfOrder();
	multiSubstateMetal->handleOutOfOrder();
	multiSubstateThrow->handleOutOfOrder();
	multiSubstateSlide->handleOutOfOrder();
	multiSubstateTransfer->handleOutOfOrder();
	return true;
}

bool Run::handleFlat() 
{
	multiSubstateManage->handleFlat();
	multiSubstateHeight->handleFlat();
	multiSubstateMetal->handleFlat();
	multiSubstateThrow->handleFlat();
	multiSubstateSlide->handleFlat();
	multiSubstateTransfer->handleFlat();
	return true;
}

bool Run::handleLbSwFree() 
{
	multiSubstateManage->handleLbSwFree();
	multiSubstateHeight->handleLbSwFree();
	multiSubstateMetal->handleLbSwFree();
	multiSubstateThrow->handleLbSwFree();
	multiSubstateSlide->handleLbSwFree();
	multiSubstateTransfer->handleLbSwFree();
	return true;
}

bool Run::handleLbSW() 
{
	multiSubstateManage->handleLbSW();
	multiSubstateHeight->handleLbSW();
	multiSubstateMetal->handleLbSW();
	multiSubstateThrow->handleLbSW();
	multiSubstateSlide->handleLbSW();
	multiSubstateTransfer->handleLbSW();
	return true;
}

bool Run::handleSlSelfFull() 
{
	multiSubstateManage->handleSlSelfFull();
	multiSubstateHeight->handleSlSelfFull();
	multiSubstateMetal->handleSlSelfFull();
	multiSubstateThrow->handleSlSelfFull();
	multiSubstateSlide->handleSlSelfFull();
	multiSubstateTransfer->handleSlSelfFull();
	return true;
}

bool Run::handleSlBothFree() 
{
	multiSubstateManage->handleSlBothFree();
	multiSubstateHeight->handleSlBothFree();
	multiSubstateMetal->handleSlBothFree();
	multiSubstateThrow->handleSlBothFree();
	multiSubstateSlide->handleSlBothFree();
	multiSubstateTransfer->handleSlBothFree();
	return true;
}

bool Run::handleSlBothFull() 
{
	multiSubstateManage->handleSlBothFull();
	multiSubstateHeight->handleSlBothFull();
	multiSubstateMetal->handleSlBothFull();
	multiSubstateThrow->handleSlBothFull();
	multiSubstateSlide->handleSlBothFull();
	multiSubstateTransfer->handleSlBothFull();
	return true;
}

bool Run::handleSlExtFull() 
{
	multiSubstateManage->handleSlExtFull();
	multiSubstateHeight->handleSlExtFull();
	multiSubstateMetal->handleSlExtFull();
	multiSubstateThrow->handleSlExtFull();
	multiSubstateSlide->handleSlExtFull();
	multiSubstateTransfer->handleSlExtFull();
	return true;
}

bool Run::handleWpExpected() 
{
	multiSubstateManage->handleWpExpected();
	multiSubstateHeight->handleWpExpected();
	multiSubstateMetal->handleWpExpected();
	multiSubstateThrow->handleWpExpected();
	multiSubstateSlide->handleWpExpected();
	multiSubstateTransfer->handleWpExpected();
	return true;
}

bool Run::handleSlSelfFree() 
{
	multiSubstateManage->handleSlSelfFree();
	multiSubstateHeight->handleSlSelfFree();
	multiSubstateMetal->handleSlSelfFree();
	multiSubstateThrow->handleSlSelfFree();
	multiSubstateSlide->handleSlSelfFree();
	multiSubstateTransfer->handleSlSelfFree();
	return true;
}

bool Run::handleWpEarly() 
{
	multiSubstateManage->handleWpEarly();
	multiSubstateHeight->handleWpEarly();
	multiSubstateMetal->handleWpEarly();
	multiSubstateThrow->handleWpEarly();
	multiSubstateSlide->handleWpEarly();
	multiSubstateTransfer->handleWpEarly();
	return true;
}

bool Run::handleWpLate() 
{
	multiSubstateManage->handleWpLate();
	multiSubstateHeight->handleWpLate();
	multiSubstateMetal->handleWpLate();
	multiSubstateThrow->handleWpLate();
	multiSubstateSlide->handleWpLate();
	multiSubstateTransfer->handleWpLate();
	return true;
}

bool Run::handleEarly() 
{
	multiSubstateManage->handleEarly();
	multiSubstateHeight->handleEarly();
	multiSubstateMetal->handleEarly();
	multiSubstateThrow->handleEarly();
	multiSubstateSlide->handleEarly();
	multiSubstateTransfer->handleEarly();
	return true;
}

bool Run::handleLate() 
{
	multiSubstateManage->handleLate();
	multiSubstateHeight->handleLate();
	multiSubstateMetal->handleLate();
	multiSubstateThrow->handleLate();
	multiSubstateSlide->handleLate();
	multiSubstateTransfer->handleLate();
	return true;
}

bool Run::handleLbO() 
{
	multiSubstateManage->handleLbO();
	multiSubstateHeight->handleLbO();
	multiSubstateMetal->handleLbO();
	multiSubstateThrow->handleLbO();
	multiSubstateSlide->handleLbO();
	multiSubstateTransfer->handleLbO();
	return true;
}

bool Run::handleLbSL() 
{
	multiSubstateManage->handleLbSL();
	multiSubstateHeight->handleLbSL();
	multiSubstateMetal->handleLbSL();
	multiSubstateThrow->handleLbSL();
	multiSubstateSlide->handleLbSL();
	multiSubstateTransfer->handleLbSL();
	return true;
}
bool Run::handleNoMetal() 
{
	multiSubstateManage->handleNoMetal();
	multiSubstateHeight->handleNoMetal();
	multiSubstateMetal->handleNoMetal();
	multiSubstateThrow->handleNoMetal();
	multiSubstateSlide->handleNoMetal();
	multiSubstateTransfer->handleNoMetal();
	return true;
}

bool Run::handleHsBelt() 
{
	multiSubstateManage->handleHsBelt();
	multiSubstateHeight->handleHsBelt();
	multiSubstateMetal->handleHsBelt();
	multiSubstateThrow->handleHsBelt();
	multiSubstateSlide->handleHsBelt();
	multiSubstateTransfer->handleHsBelt();
	return true;
}

bool Run::handleHsWP() 
{
	multiSubstateManage->handleHsWP();
	multiSubstateHeight->handleHsWP();
	multiSubstateMetal->handleHsWP();
	multiSubstateThrow->handleHsWP();
	multiSubstateSlide->handleHsWP();
	multiSubstateTransfer->handleHsWP();
	return true;
}

bool Run::handleMetalDetected() 
{
	multiSubstateManage->handleMetalDetected();
	multiSubstateHeight->handleMetalDetected();
	multiSubstateMetal->handleMetalDetected();
	multiSubstateThrow->handleMetalDetected();
	multiSubstateSlide->handleMetalDetected();
	multiSubstateTransfer->handleMetalDetected();
	return true;
}

bool Run::handleLbI() 
{
	multiSubstateManage->handleLbI();
	multiSubstateHeight->handleLbI();
	multiSubstateMetal->handleLbI();
	multiSubstateThrow->handleLbI();
	multiSubstateSlide->handleLbI();
	multiSubstateTransfer->handleLbI();
	return true;
}

bool Run::handleInOrder() 
{
	multiSubstateManage->handleInOrder();
	multiSubstateHeight->handleInOrder();
	multiSubstateMetal->handleInOrder();
	multiSubstateThrow->handleInOrder();
	multiSubstateSlide->handleInOrder();
	multiSubstateTransfer->handleInOrder();
	return true;
}

bool Run::handleWpHigh(){
	multiSubstateManage->handleWpHigh();
	multiSubstateHeight->handleWpHigh();
	multiSubstateMetal->handleWpHigh();
	multiSubstateThrow->handleWpHigh();
	multiSubstateSlide->handleWpHigh();
	multiSubstateTransfer->handleWpHigh();
	return true;
}

bool Run::handleWpFlat(){
	multiSubstateManage->handleWpFlat();
	multiSubstateHeight->handleWpFlat();
	multiSubstateMetal->handleWpFlat();
	multiSubstateThrow->handleWpFlat();
	multiSubstateSlide->handleWpFlat();
	multiSubstateTransfer->handleWpFlat();
	return true;
}

bool Run::handleWpDrilling(){
	multiSubstateManage->handleWpDrilling();
	multiSubstateHeight->handleWpDrilling();
	multiSubstateMetal->handleWpDrilling();
	multiSubstateThrow->handleWpDrilling();
	multiSubstateSlide->handleWpDrilling();
	multiSubstateTransfer->handleWpDrilling();
	return true;
}

bool Run::handleWpID(){
	multiSubstateManage->handleWpID();
	multiSubstateHeight->handleWpID();
	multiSubstateMetal->handleWpID();
	multiSubstateThrow->handleWpID();
	multiSubstateSlide->handleWpID();
	multiSubstateTransfer->handleWpID();
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
	multiSubstateHeight->handleWpArrived();
	multiSubstateMetal->handleWpArrived();
	multiSubstateThrow->handleWpArrived();
	multiSubstateSlide->handleWpArrived();
	multiSubstateTransfer->handleWpArrived();
	return true;
}

bool Run::handleTransferOK()
{
	multiSubstateManage->handleTransferOK();
	multiSubstateHeight->handleTransferOK();
	multiSubstateMetal->handleTransferOK();
	multiSubstateThrow->handleTransferOK();
	multiSubstateSlide->handleTransferOK();
	multiSubstateTransfer->handleTransferOK();
	return true;
}

bool Run::handleTransferWait()
{
	multiSubstateManage->handleTransferWait();
	multiSubstateHeight->handleTransferWait();
	multiSubstateMetal->handleTransferWait();
	multiSubstateThrow->handleTransferWait();
	multiSubstateSlide->handleTransferWait();
	multiSubstateTransfer->handleTransferWait();
	return true;
}

bool Run::handleLbOFree()
{
	multiSubstateManage->handleLbOFree();
	multiSubstateHeight->handleLbOFree();
	multiSubstateMetal->handleLbOFree();
	multiSubstateThrow->handleLbOFree();
	multiSubstateSlide->handleLbOFree();
	multiSubstateTransfer->handleLbOFree();
	return true;
}

bool Run::handleWpTransfer()
{
	multiSubstateManage->handleWpTransfer();
	multiSubstateHeight->handleWpTransfer();
	multiSubstateMetal->handleWpTransfer();
	multiSubstateThrow->handleWpTransfer();
	multiSubstateSlide->handleWpTransfer();
	multiSubstateTransfer->handleWpTransfer();
	return true;
}

bool Run::handleManageDone()
{
	multiSubstateManage->handleManageDone();
	multiSubstateHeight->handleManageDone();
	multiSubstateMetal->handleManageDone();
	multiSubstateThrow->handleManageDone();
	multiSubstateSlide->handleManageDone();
	multiSubstateTransfer->handleManageDone();
	return true;
}

bool Run::handleWpCode(int height){
	substate->handleWpCode(height);
	multiSubstateHeight->handleWpCode(height);
	return true;
}

bool Run::handleWpDrilling(int height){
	substate->handleWpDrilling(height);
	multiSubstateHeight->handleWpDrilling(height);
	return true;
}

bool Run::handleWpFlat(int height){
	substate->handleWpFlat(height);
	multiSubstateHeight->handleWpFlat(height);
	return true;
}

bool Run::handleWpHigh(int height){
	substate->handleWpHigh(height);
	multiSubstateHeight->handleWpHigh(height);
	return true;
}
