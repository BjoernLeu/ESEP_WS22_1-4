/*
 * ManageWP.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "ManageWP.h"

ManageWP::ManageWP() {}
ManageWP::~ManageWP() {}

void ManageWP::entry()
{
	// std::cout << "ManageWP entry" << std::endl;
	startWatchLateThread();
	substate = new IdleWatch;
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

bool ManageWP::handleLbI()
{
	data->addWp(INIT_TYPE, INIT_METAL, INIT_HEIGHT, INIT_FLIPPED, INIT_SEGMENT, INIT_DISTANCE);
	return true;
}

bool ManageWP::handleManageDone()
{
	substate->handleManageDone();
	return true;
}

bool ManageWP::handleHsWP()
{
	substate->handleHsWP();
	return true;
}

bool ManageWP::handleLbSW()
{
	substate->handleLbSW();
	return true;
}

bool ManageWP::handleLbO()
{
	substate->handleLbO();
	return true;
}

void ManageWP::startWatchLateThread()
{
	std::thread wT (&ManageWP::watchWPLate, this);
	wT.detach();
}

void ManageWP::watchWPLate() {
	bool watching = true;
	auto prev = std::chrono::system_clock::now();
	auto now = std::chrono::system_clock::now();
	for (int i=0; i<3; i++){
		std::cout << data->segmentDistanceList[i] << std::endl;
	}

	while(watching) {
		//std::cout << "Bernd 4" << std::endl;
		now = std::chrono::system_clock::now();
		if(data->motor && !data->motorStop) {
			std::chrono::duration<double> elapsed_seconds = now-prev;
			double addDistance = elapsed_seconds.count();
			if(data->motorSlow) {
				addDistance *= data->getSlowFactor();
			}
			
			for(std::vector<workpiece>::iterator it = data->wpList.begin(); it != data->wpList.end(); ++it) {
				(*it).distance += addDistance;
				// std::cout << "(*it).distance: " << (*it).distance << std::endl;
				// std::cout << "(*it).segment: " << (*it).segment << std::endl;
				// std::cout << "SEGMENT DISTANCE IN LIST" << data->segmentDistanceList[(*it).segment - 1] << std::endl;
				// if((*it).distance > data->segmentDistanceList[(*it).segment - 1]) {
				// 	if ((*it).segment == 3){
				// 		std::cout << "ENDE VON SEGMENT 3!!!!" << std::endl;
				// 	}else {
				// 		(*it).segment = (*it).segment + 1;
				// 		std::cout << "(*it).segment: " << (*it).segment << std::endl;
				// 	}
				// }
			}

			// for(workpiece wp: data->wpList) {
			// 	wp.distance += addDistance;
			// 	if(wp.distance > data->segmentDistanceList[wp.segment]) {
			// 		//send Error here
			// 	}
			// }
		}
		prev = now;
		usleep(50000);
	}
	
}



