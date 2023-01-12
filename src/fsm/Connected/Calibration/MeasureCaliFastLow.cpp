/*
 * MeasureCaliFastLow.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "MeasureCaliFastLow.h"

MeasureCaliFastLow::MeasureCaliFastLow() {}
MeasureCaliFastLow::~MeasureCaliFastLow() {}

void MeasureCaliFastLow::entry()
{
	std::cout << "MeasureCaliFastLow entry" << std::endl;
	getTime();
	stopTimer();
	motorOff();
	setLowValue();
}

bool MeasureCaliFastLow::handleLbI()
{
	new (this) StartCaliSlowHigh;
	entry();
	return true;
}

int MeasureCaliFastLow::getTime()
{
	//Too: Code here
}

void MeasureCaliFastLow::stopTimer()
{
	//Too: Code here
}

void MeasureCaliFastLow::motorOff()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void MeasureCaliFastLow::setLowValue()
{
	// data->mp->setLowValue();
}

