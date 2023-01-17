/*
 * WaitFesto2.cpp
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#include "WaitFesto2.h"

WaitFesto2::WaitFesto2() {}
WaitFesto2::~WaitFesto2() {}

void WaitFesto2::entry()
{
	std::cout << "Tranfer/WaitFesto2 entry" << std::endl;
	sendTransferWait();
}

void WaitFesto2::exit()
{
	sendTransferOK();
}

//Transisions
bool WaitFesto2::handleLbOFree()
{
	exit();
	motorOn();
	new (this) IdleTransferFesto2;
	entry();
	return true;
}

bool WaitFesto2::handleLbSL()
{
	exit();
	motorOn();
	new (this) IdleTransferFesto2;
	entry();
	return true;
}

bool WaitFesto2::handleLbO()
{
	motorOff();
	return true;
}

//Methods
void WaitFesto2::sendTransferWait()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(TRANSFER_WAIT), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

void WaitFesto2::sendTransferOK()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(TRANSFER_OK), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

void WaitFesto2::motorOff()
{
	data->motor = false;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

void WaitFesto2::motorOn()
{
	data->motor = true;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}
