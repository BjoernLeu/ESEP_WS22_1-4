/*
 * ArrivedSwitch.cpp
 *
 *  Created on: 21 Dec 2022
 *      Author: j-oeh
 */

#include "ArrivedSwitch.h"

ArrivedSwitch::ArrivedSwitch() {}
ArrivedSwitch::~ArrivedSwitch() {}

void ArrivedSwitch::entry()
{
	// std::cout << "ArrivedSwitch entry" << std::endl;
	checkEarly();
	manageList();
}

//transitions
bool ArrivedSwitch::handleManageDone()
{
	new (this) IdleWatch;
	entry();
	return true;
}


//methods
void ArrivedSwitch::checkEarly()
{
	workpiece arrivedWp = {-1, -1, false, -1, false, 2, 0};
	for(workpiece wp: data->wpList) {
		if(wp.segment == 2) {
			arrivedWp = wp;
		}
	}
	if(arrivedWp.distance < data->segmentDistanceListMin[2]) {
 		if (MsgSendPulse(coid, -1, static_cast<int>(ERROR), 0) == -1) {
 			perror("MsgSendPulse failed");
 		}
 		if (MsgSendPulse(coidExt, -1, static_cast<int>(ERROR), 0) == -1) {
 			perror("MsgSendPulse failed");
 		}
	}
	if(arrivedWp.id != -1) {
		arrivedWp.segment = 3;
		arrivedWp.distance = 0;
	}
	handleManageDone();
}

void ArrivedSwitch::manageList()
{

}
