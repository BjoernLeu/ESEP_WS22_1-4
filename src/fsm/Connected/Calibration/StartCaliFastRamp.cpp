/*
 * StartCaliFastRamp.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "StartCaliFastRamp.h"

StartCaliFastRamp::StartCaliFastRamp() {}
StartCaliFastRamp::~StartCaliFastRamp() {}

void StartCaliFastRamp::entry()
{
	startTimer();
	getTime();
	motorOn();
}

bool StartCaliFastRamp::handleHsWP()
{
	new (this) MeasureCaliFastRamp;
	entry();
	return true;
}

void StartCaliFastRamp::startTimer()
{
	//ToDo: Code here
}

int StartCaliFastRamp::getTime()
{
	//ToDo: Code here
}

void StartCaliFastRamp::motorOn()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

