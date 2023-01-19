/*
 * ArrivedHeight.cpp
 *
 *  Created on: 21 Dec 2022
 *      Author: j-oeh
 */

#include "ArrivedHeight.h"

ArrivedHeight::ArrivedHeight() {}
ArrivedHeight::~ArrivedHeight() {}

void ArrivedHeight::entry()
{
	// std::cout << "ArrivedHeight entry" << std::endl;
	checkEarly();
	manageList();
}

//transitions
bool ArrivedHeight::handleManageDone()
{
	new (this) IdleWatch;
	entry();
	return true;
}


//methods
void ArrivedHeight::checkEarly()
{
	workpiece arrivedWp = {-1, -1, false, -1, false, 1, 0};
	for(workpiece wp: data->wpList) {
		if(wp.segment == 1) {
			arrivedWp = wp;
		}
	}
	if(arrivedWp.distance < data->segmentDistanceListMin[0]) {
 		if (MsgSendPulse(coid, -1, static_cast<int>(ERROR), 0) == -1) {
 			perror("MsgSendPulse failed");
 		}
 		if (MsgSendPulse(coidExt, -1, static_cast<int>(ERROR), 0) == -1) {
 			perror("MsgSendPulse failed");
 		}
	}
	if(arrivedWp.id != -1) {
		arrivedWp.segment = 2;
		arrivedWp.distance = 0;
	}
	handleManageDone();
}

void ArrivedHeight::manageList()
{
	handleManageDone();
}

