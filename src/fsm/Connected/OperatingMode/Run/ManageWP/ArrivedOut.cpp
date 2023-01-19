/*
 * ArrivedOut.cpp
 *
 *  Created on: 21 Dec 2022
 *      Author: j-oeh
 */

#include "ArrivedOut.h"

ArrivedOut::ArrivedOut() {}
ArrivedOut::~ArrivedOut() {}

void ArrivedOut::entry()
{
		// std::cout << "ArrivedOut entry" << std::endl;
	checkEarly();
	manageList();
}

//transitions
bool ArrivedOut::handleManageDone()
{
	new (this) IdleWatch;
	entry();
	return true;
}


//methods
void ArrivedOut::checkEarly()
{
	workpiece *arrivedWp;
	data->wpListM.lock();
	for(workpiece wp: data->wpList) {
		if(wp.segment == 3) {
			arrivedWp = &wp;
		}
	}
	data->wpListM.unlock();
	if(arrivedWp->distance < data->segmentDistanceListMin[3]) {
 		if (MsgSendPulse(coid, -1, static_cast<int>(ERROR), 0) == -1) {
 			perror("MsgSendPulse failed");
 		}
 		if (MsgSendPulse(coidExt, -1, static_cast<int>(ERROR), 0) == -1) {
 			perror("MsgSendPulse failed");
 		}
	}
//	data->wpList.pop_back();
	handleManageDone();
}

void ArrivedOut::manageList()
{

}
