/*
 * WPDisappeared.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "WPDisappeared.h"

WPDisappeared::WPDisappeared() {}

WPDisappeared::~WPDisappeared() {}

bool WPDisappeared::handleStartSp()
{
	exit();
	new(this) SubEndState;
	entry();
	return true;
}

void WPDisappeared::entry()
{
	std::cout << "WPDisappeared entry" << std::endl;
	removeFromList();
}

void WPDisappeared::exit()
{
	std::cout << "WPDisappeared exit" << std::endl;
	motorOn();
}

void WPDisappeared::motorOn()
{
	std::cout << "Motor On" << std::endl;
	data->motor =true;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void WPDisappeared::removeFromList()
{
	std::cout << "WP will be removed from List" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(REMOVE_FROM_LIST), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}
