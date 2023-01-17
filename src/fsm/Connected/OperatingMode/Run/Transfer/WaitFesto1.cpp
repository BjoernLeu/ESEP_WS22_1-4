/*
 * WaitFesto1.cpp
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#include "WaitFesto1.h"

WaitFesto1::WaitFesto1() {}
WaitFesto1::~WaitFesto1() {}

void WaitFesto1::entry()
{
	std::cout << "Tranfer/WaitFesto1 entry" << std::endl;
	motorOff();
}

void WaitFesto1::exit()
{
	motorOn();
}

//Transitions
bool WaitFesto1::handleTransferOK()
{
	exit();
	new (this) IdleTransferFesto1;
	entry();
	return true;
}

//Methods
void WaitFesto1::motorOff()
{
	data->motor = false;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

void WaitFesto1::motorOn()
{
	data->motor = true;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}
