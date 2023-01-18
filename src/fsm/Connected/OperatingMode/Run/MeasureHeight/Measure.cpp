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
	data->motorSlow = true;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_SLOW_ON), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

void Measure::motorSlowOff()
{
	data->motorSlow = false;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_SLOW_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
}

bool Measure::handleWpDrilling(int height){
	std::cout << "data->addWpType(WP_DRILLING, height);" << std::endl;
	std::cout << "height: " << height << std::endl;
	data->addWpType(WP_DRILLING, height);
	exit();
	new (this) IdleMeasureHeight;
	entry();
	return true;
}

bool Measure::handleWpFlat(int height){
	std::cout << "data->addWpType(56, height);" << std::endl;
	data->addWpType(WP_FLAT, height);
	exit();
	new (this) IdleMeasureHeight;
	entry();
	return true;
}

bool Measure::handleWpHigh(int height){
	std::cout << "data->addWpType(57, height);" << std::endl;
	data->addWpType(WP_HIGH, height);
	exit();
	new (this) IdleMeasureHeight;
	entry();
	return true;
}

bool Measure::handleWpCode(int height){
	std::cout << "data->addWpType(59, height);" << std::endl;
	data->addWpType(WP_CODE, height);
	exit();
	new (this) IdleMeasureHeight;
	entry();
	return true;
}
