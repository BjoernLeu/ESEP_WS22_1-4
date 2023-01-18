/*
 * IdleTransferFesto2.cpp
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#include "IdleTransferFesto2.h"

IdleTransferFesto2::IdleTransferFesto2() {}
IdleTransferFesto2::~IdleTransferFesto2() {}

void IdleTransferFesto2::entry()
{
	std::cout << "Tranfer/IdleTransferFesto2 entry" << std::endl;
}

//transitions
bool IdleTransferFesto2::handleLbSL()
{
	emptyBelt();
	entry();
	return true;
}

bool IdleTransferFesto2::handleLbO()
{
	data->wpList.pop_back();
	motorOff();
	entry();
	return true;
}

bool IdleTransferFesto2::handleLbOFree()
{
	emptyBelt();
	entry();
	return true;
}

bool IdleTransferFesto2::handleWpTransfer()
{
	new (this) WaitFesto2;
	entry();
	return true;
}

bool IdleTransferFesto2::handleLbI()
{
	sendWpArrived();
	entry();
	return true;
}

//Methods
void IdleTransferFesto2::emptyBelt()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(EMPTY_BELT), 0) == -1) {
		perror("MsgSendPulse failed");
	}	
}

void IdleTransferFesto2::motorOff()
{
	data->motor = false;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

void IdleTransferFesto2::sendWpArrived()
{
	if (MsgSendPulse(coidExt, -1, static_cast<int>(WP_ARRIVED), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

