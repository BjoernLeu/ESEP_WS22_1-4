/*
 * StartCaliSlowRamp.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "StartCaliSlowRamp.h"

StartCaliSlowRamp::StartCaliSlowRamp() {}
StartCaliSlowRamp::~StartCaliSlowRamp() {}

void StartCaliSlowRamp::entry()
{
	startTimer();
	getTime();
	motorOn();
}

bool StartCaliSlowRamp::handleHsWP()
{
	new (this) MeasureCaliSlowRamp;
	entry();
	return true;
}

void StartCaliSlowRamp::startTimer()
{
	//Too: Code here
}

int StartCaliSlowRamp::getTime()
{
	//Too: Code here
}

void StartCaliSlowRamp::motorOn()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}
