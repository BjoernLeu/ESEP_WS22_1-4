/*
 * CheckFesto2.cpp
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#include "CheckFesto2.h"

CheckFesto2::CheckFesto2() {}

CheckFesto2::~CheckFesto2() {}

	void CheckFesto2::entry()
	{
		sendWpTransfer();
	}

	//Transisions
	bool CheckFesto2::handleTransferOK()
	{
		new (this) IdleTransferFesto1;
		entry();
		return true;
	} 

	bool CheckFesto2::handleTransferWait()
	{
		new (this) WaitFesto1;
		entry();
		return true;
	}

	//Methods
	void CheckFesto2::sendWpTransfer()
	{
		if (MsgSendPulse(coid, -1, static_cast<int>(WP_TRANSFER), 0) == -1) {
			perror("MsgSendPulse failed");
		}
	}
