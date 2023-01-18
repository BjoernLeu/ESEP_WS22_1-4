/*
 * IdleRun.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "IdleRun.h"

IdleRun::IdleRun() {}
IdleRun::~IdleRun() {}

void IdleRun::entry(){
	std::cout << "IdleRun entry" << std::endl;
}

bool IdleRun::handleLbI() 
{
	new(this) Run();
	entry();
	return true;
}

bool IdleRun::handleWpTransfer() 
{
	sendTransferOK();
	new(this) Run();
	entry();
	return true;
}

void IdleRun::sendTransferOK() 
{
	std::cout << "Hier wird was gesendet." << std::endl;
	if (MsgSendPulse(coidExt, -1, static_cast<int>(TRANSFER_OK), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}
