/*
 * StartCaliSlowHigh.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "StartCaliSlowHigh.h"

StartCaliSlowHigh::StartCaliSlowHigh() {}
StartCaliSlowHigh::~StartCaliSlowHigh() {}

void StartCaliSlowHigh::entry()
{
	startTimer();
	getTime();
	motorOn();
}

bool StartCaliSlowHigh::handleHsWP()
{
	new (this) MeasureCaliSlowHigh;
	entry();
	return true;
}

void StartCaliSlowHigh::startTimer()
{
	//ToDo: Code here
}

int StartCaliSlowHigh::getTime()
{
	return -1;
}

void StartCaliSlowHigh::motorOn()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}
