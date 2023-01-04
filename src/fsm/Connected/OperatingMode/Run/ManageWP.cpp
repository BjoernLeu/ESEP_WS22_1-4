/*
 * ManageWP.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "ManageWP.h"

ManageWP::ManageWP() {
	// TODO Auto-generated constructor stub

}

ManageWP::~ManageWP() {
	// TODO Auto-generated destructor stub
}

bool ManageWP::handleWpEarly()
{
	return false;
}

bool ManageWP::handleWpLate()
{
	return false;
}

bool ManageWP::handleEarly()
{
	// TODO Auto-generated destructor stub
}

bool ManageWP::handleLate()
{
	// TODO Auto-generated destructor stub
}

bool ManageWP::watchWS()
{
	// TODO Auto-generated destructor stub
}

void ManageWP::sendErrorEarly()
{
	// TODO Auto-generated destructor stub
}

void ManageWP::sendErrorLate()
{
	// TODO Auto-generated destructor stub
}

void ManageWP::entry()
{
	// TODO Auto-generated destructor stub
}

void ManageWP::increaseCurrentCount()
{
	// TODO Auto-generated destructor stub
}

bool ManageWP::handleLbI()
{
	// TODO Auto-generated destructor stub
}

void ManageWP::watchWPLate() {
	bool watching = true;
	auto prev = std::chrono::system_clock::now();
	auto now = std::chrono::system_clock::now();

	while(watching) {
		now = std::chrono::system_clock::now();
		if(data->motor && !data->motorStop) {
			std::chrono::duration<double> elapsed_seconds = now-prev;
			double addDistance = elapsed_seconds.count();
			if(data->motorSlow) {
				addDistance *= data->slowFactor;
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



