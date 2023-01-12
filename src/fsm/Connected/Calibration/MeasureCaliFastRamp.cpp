/*
 * MeasureCaliFastRamp.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "MeasureCaliFastRamp.h"

MeasureCaliFastRamp::MeasureCaliFastRamp() {}
MeasureCaliFastRamp::~MeasureCaliFastRamp() {}

void MeasureCaliFastRamp::entry()
{
	std::cout << "MeasureCaliFastRamp entry" << std::endl;
	getTime();
	stopTimer();
	motorOff();
}

bool MeasureCaliFastRamp::handleLbI()
{
	new (this) StartCaliSlowRamp;
	entry();
	return true;
}

int MeasureCaliFastRamp::getTime()
{
	//ToDo: Code here
}

void MeasureCaliFastRamp::stopTimer()
{
	//ToDo: Code here
}

void MeasureCaliFastRamp::motorOff()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

