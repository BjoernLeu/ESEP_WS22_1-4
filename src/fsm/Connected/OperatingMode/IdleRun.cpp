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

bool IdleRun::hadleWpTransfer() 
{
	sendTransfer();
	new(this) Run();
	entry();
	return true;
}

void IdleRun::sendTransferOK() 
{
	std::cout << "Hier wird was gesendet." << std::endl;
	//send(":)");
}