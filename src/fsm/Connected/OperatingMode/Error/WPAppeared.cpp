/*
 * WPAppeared.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "WPAppeared.h"

WPAppeared::WPAppeared() {}

WPAppeared::~WPAppeared() {}

bool WPAppeared::handleStartSp()
{
	exit();
	new(this) IdleError;
	entry();
	return true;
}

void WPAppeared::entry()
{
	std::cout << "WPAppeared entry" << std::endl;
	addToList();
	addWatcher(true);
}

void WPAppeared::exit()
{
	std::cout << "WPAppeared exit" << std::endl;
	// motorOn();
}

void WPAppeared::addToList()
{
	std::cout << "WP will be added to List" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(ADD_TO_LIST), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void WPAppeared::addWatcher(bool current_lb)
{
	std::cout << "Watcher Added" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(ADD_WATCHER), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void WPAppeared::motorOn()
{
	data->motor = true;
	std::cout << "Motor On" << std::endl;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}