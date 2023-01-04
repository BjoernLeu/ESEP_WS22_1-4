/*
 * StartCaliFastLow.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "StartCaliFastLow.h"

StartCaliFastLow::StartCaliFastLow() {}
StartCaliFastLow::~StartCaliFastLow() {}

void StartCaliFastLow::entry()
{
	startTimer();
	getTime();
	motorOn();	
}

bool StartCaliFastLow::handleHsWP()
{
	new (this) MeasureCaliFastLow;
	entry();
	return true;
}

void StartCaliFastLow::startTimer()
{
	//ToDo: Code here
}

int StartCaliFastLow::getTime()
{
	//ToDo: Code here
}

void StartCaliFastLow::motorOn()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}
