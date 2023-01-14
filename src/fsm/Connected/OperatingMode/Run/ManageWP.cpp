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
	//ToDo not implemented yet
}

bool ManageWP::handleHsWP()
{
	//ToDo not implemented yet
}

bool ManageWP::handleLbSW()
{
	//ToDo not implemented yet
}

bool ManageWP::handleLbO()
{
	//ToDo not implemented yet
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



