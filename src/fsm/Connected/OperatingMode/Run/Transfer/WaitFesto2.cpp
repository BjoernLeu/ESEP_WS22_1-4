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
		exit();
		motorOff();
		entry();
		return true;
	}

	//Methods
	void WaitFesto2::sendTransferWait()
	{

	}

	void WaitFesto2::sendTransferOK()
	{

	}

	void WaitFesto2::motorOff()
	{
		if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
		}
	}

	void WaitFesto2::motorOn()
	{
		if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
		}
	}
