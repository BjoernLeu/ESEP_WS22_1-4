/*
 * MeasureCaliSlowRamp.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "MeasureCaliSlowRamp.h"

MeasureCaliSlowRamp::MeasureCaliSlowRamp() {}
MeasureCaliSlowRamp::~MeasureCaliSlowRamp() {}

void MeasureCaliSlowRamp::entry()
{
	getTime();
	stopTimer();
	motorOff();
	getCMs_slow();
	getCMs_fast();
}

bool MeasureCaliSlowRamp::handleCalcDone()
{
	new (this) SaveCali;
	entry();
	return true;
}

int MeasureCaliSlowRamp::getTime()
{
	//Too: Code here
}

void MeasureCaliSlowRamp::stopTimer()
{
	//Too: Code here
}

void MeasureCaliSlowRamp::motorOff()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

double MeasureCaliSlowRamp::getCMs_slow()
{
	//Too: Code here
}

double MeasureCaliSlowRamp::getCMs_fast()
{
	//Too: Code here
}

