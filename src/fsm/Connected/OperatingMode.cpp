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
	// std::cout << "OperatingMode entry" << std::endl;
	action->lightOn(GREEN);

	multiSubstateSlide = new Slide();
	multiSubstateSlide->setData(data);
	multiSubstateSlide->setAction(action);
	multiSubstateSlide->entry();
	multiSubstateIdleRun = new IdleRun();
	multiSubstateIdleRun->setData(data);
	multiSubstateIdleRun->setAction(action);
	multiSubstateIdleRun->entry();
	multiSubstateError = new Error();
	multiSubstateError->setData(data);
	multiSubstateError->setAction(action);
	multiSubstateError->entry();
}

void OperatingMode::exit()
{
	// std::cout << "OperatingMode exit" << std::endl;
	action->lightOff(GREEN);
}

// bool OperatingMode::entryHistory()
// {
// 	new(this) Run;
// 	entryHistory();
// 	return true;
// }
bool OperatingMode::handleError() 
{
	std::cout << "handle Error" << std::endl;
	// multiSubstateIdleRun->handleError();
	multiSubstateError->handleError();
	return true;
}
bool OperatingMode::handleErrorGone(){
	multiSubstateError->handleErrorGone();
	return true;
}

bool OperatingMode::handleStartSp(){
	multiSubstateError->handleStartSp();
	return true;
}

bool OperatingMode::handleResetSp(){
	multiSubstateError->handleResetSp();
	return true;
}

bool OperatingMode::handlePrinted(){
	multiSubstateError->handlePrinted();
	return true;
}

bool OperatingMode::handleStopSp()
{
	// std::cout << "Connected/handleStopSp" << std::endl;
	exit();
	new (this) Idle();
	entry();
	return true;
}

bool OperatingMode::handleSignalReceipted() 
{
	multiSubstateIdleRun->handleSignalReceipted();
	multiSubstateSlide->handleSignalReceipted();
	return true;
}

bool OperatingMode::handleSlBothFree() 
{
	multiSubstateIdleRun->handleSlBothFree();
	return true;
}

bool OperatingMode::handleOutOfOrder() 
{
	multiSubstateIdleRun->handleOutOfOrder();
	return true;
}

bool OperatingMode::handleFlat() 
{
	multiSubstateIdleRun->handleFlat();
	return true;
}

bool OperatingMode::handleLbSwFree() 
{
	multiSubstateIdleRun->handleLbSwFree();
	return true;
}

bool OperatingMode::handleLbSW() 
{
	multiSubstateIdleRun->handleLbSW();
	return true;
}

bool OperatingMode::handleSlExtFree() 
{
	multiSubstateIdleRun->handleSlExtFree();
	multiSubstateSlide->handleSlExtFree();
	return true;
}

bool OperatingMode::handleSlSelfFull() 
{
	multiSubstateIdleRun->handleSlSelfFull();
	multiSubstateSlide->handleSlSelfFull();
	return true;
}

bool OperatingMode::handleSlFree() 
{
	multiSubstateIdleRun->handleSlFree();
	return true;
}

bool OperatingMode::handleSlBothFull() 
{
	multiSubstateIdleRun->handleSlBothFull();
	return true;
}

bool OperatingMode::handleSlExtFull() 
{
	multiSubstateIdleRun->handleSlExtFull();
	multiSubstateSlide->handleSlExtFull();
	return true;
}

bool OperatingMode::handleWpExpected() 
{
	multiSubstateIdleRun->handleWpExpected();
	multiSubstateSlide->handleWpExpected();
	return true;
}

bool OperatingMode::handleSlSelfFree() 
{
	multiSubstateIdleRun->handleSlSelfFree();
	multiSubstateSlide->handleSlSelfFree();
	return true;
}

bool OperatingMode::handleLbO()
{
	multiSubstateIdleRun->handleLbO();
	return true;
}

bool OperatingMode::handleLbSL()
{
	multiSubstateIdleRun->handleLbSL();
	return true;
}
bool OperatingMode::handleNoMetal() 
{
	multiSubstateIdleRun->handleNoMetal();
	return true;
}

bool OperatingMode::handleHsBelt()
{
	multiSubstateIdleRun->handleHsBelt();
	return true;
}

bool OperatingMode::handleHsWP()
{
	multiSubstateIdleRun->handleHsWP();
	return true;
}

bool OperatingMode::handleEmptyBelt() 
{
	multiSubstateIdleRun->handleEmptyBelt();
	return true;
}

bool OperatingMode::handleInOrder()
{
	multiSubstateIdleRun->handleInOrder();
	return true;
}

bool OperatingMode::handleWpMetal()
{
	multiSubstateIdleRun->handleWpMetal();
	return true;
}

bool OperatingMode::handleLbI()
{
	multiSubstateIdleRun->handleLbI();
	return true;
}

bool OperatingMode::handleWpArrived()
{
	multiSubstateIdleRun->handleWpArrived();
	return true;
}

bool OperatingMode::handleTransferOK()
{
	multiSubstateIdleRun->handleTransferOK();
	return true;
}

bool OperatingMode::handleTransferWait()
{
	multiSubstateIdleRun->handleTransferWait();
	return true;
}

bool OperatingMode::handleLbOFree()
{
	multiSubstateIdleRun->handleLbOFree();
	return true;
}

bool OperatingMode::handleWpTransfer()
{
	multiSubstateIdleRun->handleWpTransfer();
	return true;
}

bool OperatingMode::handleManageDone()
{
	multiSubstateIdleRun->handleManageDone();
	return true;
}

bool OperatingMode::handleWpCode(int height){
	multiSubstateIdleRun->handleWpCode(height);
	return true;
}

bool OperatingMode::handleWpDrilling(int height){
	multiSubstateIdleRun->handleWpDrilling(height);
	return true;
}

bool OperatingMode::handleWpFlat(int height){
	multiSubstateIdleRun->handleWpFlat(height);
	return true;
}

bool OperatingMode::handleWpHigh(int height){
	multiSubstateIdleRun->handleWpHigh(height);
	return true;
}
