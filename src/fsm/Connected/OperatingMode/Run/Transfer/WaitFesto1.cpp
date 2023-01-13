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
		motorOff();
		closeSwitch();
	}

	void WaitFesto1::exit()
	{
		motorOn();
		restoreSwitch();
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
		if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
		}
	}

	void WaitFesto1::closeSwitch()
	{
		if (MsgSendPulse(coid, -1, static_cast<int>(SWITCH_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
		}
	}

	void WaitFesto1::motorOn()
	{
		if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
		}
	}

	void WaitFesto1::restoreSwitch()
	{

	}