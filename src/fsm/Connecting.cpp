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
	// std::cout << "Connecting entry" << std::endl;

	for (int i = 1; i < 8; i++) {
		action->lightOff(i);
	}
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_SLOW_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
	if(data->getFesto() == 1){
		action->blinkingOn(Q1, FAST);
	}else{
		action->blinkingOn(Q2, FAST);
	}
	establishConnection();
	if (MsgSendPulse(coid, -1, static_cast<int>(SET_SW_TYPE), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void Connecting::exit() {
	action->blinkingOff(Q1);
	action->blinkingOff(Q2);
}

bool Connecting::handleConEstablished() 
{
	data->setConnectionTrue();
	exit();
	new (this) Connected;
	entry();
	return true;
}

bool Connecting::handleEstopSelfPressed()
{
	std::cout << "Handling EstopSelfPressed" << std::endl;
	data->setEstopSelfTrue();
//	if (MsgSendPulse(coidExt, -1, static_cast<int>(KILL_SERVER), 0) == -1) {
//			perror("MsgSendPulse failed");
//	}
//	exit();
//	new (this) Estop;
//	entry();
	return true;
}

bool Connecting::handleEstopSelfReleased() {
	data->setEstopSelfFalse();
	return true;
}

void Connecting::establishConnection(){
	std::cout << "Connecting here..." << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(CONNECT), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}
