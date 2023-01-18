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
	std::cout << "Tranfer/CheckFesto2 entry" << std::endl;
	sendWpTransfer();
}

//Transisions
bool CheckFesto2::handleTransferOK()
{
	workpiece wp = data->wpList.back();
	std::cout << "CheckFesto2 wp type: " << wp.type << std::endl;
	if (MsgSendPulse(coidExt, -1, wp.type, (int)wp.height+0.5) == -1) {
		perror("MsgSendPulse failed");
	}
	if (MsgSendPulse(coidExt, -1, wp.metal, 0) == -1) {
		perror("MsgSendPulse failed");
	}
	data->wpList.pop_back();
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
	if (MsgSendPulse(coidExt, -1, static_cast<int>(WP_TRANSFER), 0) == -1) {
		perror("MsgSendPulse failed");
	}
}
