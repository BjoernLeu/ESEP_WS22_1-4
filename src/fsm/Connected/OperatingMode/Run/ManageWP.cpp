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
	std::cout << "ManageWP entry" << std::endl;
	startWatchLateThread();
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
	std::cout << "Bernd 1" << std::endl;	
	std::thread wT (&ManageWP::watchWPLate, this);
	wT.detach();
}

void ManageWP::watchWPLate() {
	std::cout << "Bernd 2" << std::endl;
	bool watching = true;
	auto prev = std::chrono::system_clock::now();
	auto now = std::chrono::system_clock::now();

	std::cout << "Bernd 3" << std::endl;
	while(watching) {
		//std::cout << "Bernd 4" << std::endl;
		now = std::chrono::system_clock::now();
		if(data->motor && !data->motorStop) {
			std::cout << "Bernd 5" << std::endl;
			std::chrono::duration<double> elapsed_seconds = now-prev;
			double addDistance = elapsed_seconds.count();
			if(data->motorSlow) {
				addDistance *= data->getSlowFactor();
			}
			for(workpiece wp: data->wpList) {
				wp.distance += addDistance;
				if(wp.distance > data->segmentDistanceList[wp.segment]) {
					//send Error here
				}
			}
		}
		prev = now;
		usleep(50000);
	}
	
}



