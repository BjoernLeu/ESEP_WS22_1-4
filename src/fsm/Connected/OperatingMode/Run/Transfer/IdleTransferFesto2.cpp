/*
 * IdleTransferFesto2.cpp
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#include "IdleTransferFesto2.h"

IdleTransferFesto2::IdleTransferFesto2() {}

IdleTransferFesto2::~IdleTransferFesto2() {}


	void entry()
	{
		
	}

	//transitions
	bool IdleTransferFesto2::handleLbSl()
	{
		emptyBelt();
		entry();
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
		void emptyBelt()
		{
			
		}

		void motorOff()
		{
			if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
				perror("MsgSendPulse failed");
			}
		}

		void sendWpArrived()
		{

		}

