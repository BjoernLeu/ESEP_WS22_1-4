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
	std::cout << "ArrivedHeight checkEarly" << std::endl;
	workpiece *arrivedWp;
	data->wpListM.lock();
	for(workpiece wp: data->wpList) {
		std::cout << "in for loop" << std::endl;
		if(wp.segment == 1) {
			arrivedWp = &wp;
		}
	}
	std::cout << "left for loop" << std::endl;
	if(arrivedWp->distance < data->segmentDistanceListMin[0]) {
		std::cout << "ArrivedHeight Error" << std::endl;
 		if (MsgSendPulse(coid, -1, static_cast<int>(ERROR), 0) == -1) {
 			perror("MsgSendPulse failed");
 		}
 		if (MsgSendPulse(coidExt, -1, static_cast<int>(ERROR), 0) == -1) {
 			perror("MsgSendPulse failed");
 		}
	}
	if(arrivedWp->id != 0) {
		std::cout << "changing segment" << std::endl;
		arrivedWp->segment = 2;
		arrivedWp->distance = 0;
	}
	data->wpListM.unlock();
	std::cout << "handleManageDone()" << std::endl;
	handleManageDone();
}

void ArrivedHeight::manageList()
{
	handleManageDone();
}

