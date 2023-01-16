/*
 * Connecting.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "Connecting.h"

Connecting::Connecting() {}
Connecting::~Connecting() {}

void Connecting::entry() {
	std::cout << "Connecting entry" << std::endl;
	for (int i = 1; i < 8; i++) {
		action->lightOff(i);
	}
	establishConnection();
	if (MsgSendPulse(coid, -1, static_cast<int>(SET_SW_TYPE), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void Connecting::exit() {
	// substate = new SubEndState;
	// substate->entry();
}

bool Connecting::handleConEstablished() 
{
	exit();
	new (this) Connected;
	entry();
	return true;
}

bool Connecting::handleEstopSelfPressed()
{
	std::cout << "Handleing EstopSelfPressed" << std::endl;
	data->setEstopSelfTrue();
	exit();
	new (this) Estop;
	entry();
	return true;
}

void Connecting::establishConnection(){
	std::cout << "Connecting here..." << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(CONNECT), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}
