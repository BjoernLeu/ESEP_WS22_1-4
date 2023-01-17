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
	substate = new IdleWatch;
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

bool ManageWP::handleLbI()
{
	std::cout << "ManageWP handleLbI" << std::endl;
	data->addWp(INIT_TYPE, INIT_METAL, INIT_HEIGHT, INIT_FLIPPED, INIT_SEGMENT, INIT_DISTANCE);
	return true;
}

bool ManageWP::handleManageDone()
{
	std::cout << "ManageWP handleManageDone" << std::endl;
	substate->handleManageDone();
	return true;
}

bool ManageWP::handleHsWP()
{
	std::cout << "ManageWP handleHsWP" << std::endl;
	substate->handleHsWP();
	return true;
}

bool ManageWP::handleLbSW()
{
	std::cout << "ManageWP handleLbSW" << std::endl;
	substate->handleLbSW();
	return true;
}

bool ManageWP::handleLbO()
{
	std::cout << "ManageWP handleLbO" << std::endl;
	substate->handleLbO();
	return true;
}

void ManageWP::startWatchLateThread()
{
	std::cout << "ManageWP startWatchLateThread" << std::endl;
	std::thread wT (&ManageWP::watchWPLate, this);
	wT.detach();
}

void ManageWP::watchWPLate() {
	bool watching = true;
	auto prev = std::chrono::system_clock::now();
	auto now = std::chrono::system_clock::now();

	while(watching) {
		//std::cout << "Bernd 4" << std::endl;
		now = std::chrono::system_clock::now();
		if(data->motor && !data->motorStop) {
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



