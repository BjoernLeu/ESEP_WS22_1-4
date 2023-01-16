/*
 * Measure.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "Measure.h"

Measure::Measure() {}
Measure::~Measure() {}

void Measure::entry()
{
	std::cout << "Measure entry" << std::endl;
	motorSlowOn();
}

void Measure::exit()
{
	motorSlowOff();
}

bool Measure::handleHsBelt() 
{
	exit();
	new (this) IdleMeasureHeight;
	entry();
	return true;
}

void Measure::motorSlowOn()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_SLOW_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void Measure::motorSlowOff()
{
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_SLOW_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

bool Measure::handleWpDrilling(int height){
	data->addWpType(55, height);
}

bool Measure::handleWpFlat(int height){
	data->addWpType(56, height);
}

bool Measure::handleWpHigh(int height){
	data->addWpType(57, height);
}

bool Measure::handleWpCode(int height){
	data->addWpType(59, height);
}
