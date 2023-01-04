/*
 * MeasureCaliSlowHigh.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "MeasureCaliSlowHigh.h"

MeasureCaliSlowHigh::MeasureCaliSlowHigh() {}
MeasureCaliSlowHigh::~MeasureCaliSlowHigh() {}

void MeasureCaliSlowHigh::entry()
{
	getTime();
	stopTimer();
	motorOff();
	setHighValue();
}

bool MeasureCaliSlowHigh::handleLbI()
{
	new (this) StartCaliFastRamp;
	entry();
	return true;
}

int MeasureCaliSlowHigh::getTime()
{
	//ToDo: Code here
}

void MeasureCaliSlowHigh::stopTimer()
{
	//ToDo: Code here
}

void MeasureCaliSlowHigh::motorOff()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void MeasureCaliSlowHigh::setHighValue()
{
	// data->mp.setHigh();
}
