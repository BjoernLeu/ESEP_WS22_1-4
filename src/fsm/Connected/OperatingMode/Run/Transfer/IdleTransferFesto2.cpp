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
	
}

//transitions
bool IdleTransferFesto2::handleLbSL()
{
	emptyBelt();
	new (this) IdleTransferFesto2;
	entry();
	return true;
}

bool IdleTransferFesto2::handleLbO()
{
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
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

void IdleTransferFesto2::sendWpArrived()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(WP_ARRIVED), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}

