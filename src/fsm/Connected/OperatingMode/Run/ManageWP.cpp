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
	startWatchLateThread();
}

bool ManageWP::handleLbI()
{
	addWP();
	entry();
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
	//not implemented yet
}

void ManageWP::addWP()
{
	//not implemented yet
}

// void ManageWP::watchWPLate() {
// 	bool watching = true;
// 	auto prev = std::chrono::system_clock::now();
// 	auto now = std::chrono::system_clock::now();

// 	while(watching) {
// 		now = std::chrono::system_clock::now();
// 		if(data->motor && !data->motorStop) {
// 			std::chrono::duration<double> elapsed_seconds = now-prev;
// 			double addDistance = elapsed_seconds.count();
// 			if(data->motorSlow) {
// 				addDistance *= data->slowFactor;
// 			}
// 			for(workpiece wp: data->wpList) {
// 				wp.distance += addDistance;
// 				if(wp.distance > data->segmentDistanceList[wp.segment]) {
// 					//send Error here
// 				}
// 			}
// 		}
// 		prev = now;
// 		usleep(50000);
// 	}
// }



