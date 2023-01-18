/*
 * HeightSlow.cpp
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#include "HeightSlow.h"

HeightSlow::HeightSlow() {}
HeightSlow::~HeightSlow() {}

void HeightSlow::entry() 
{
	// std::cout << "HeightSlow entry" << std::endl;
	data->setTime_hsWP_slow();
	data->motorSlow = false;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_SLOW_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
	data->motor = false;
	if (MsgSendPulse(coid, -1, static_cast<int>(MOTOR_OFF), 0) == -1) {
			perror("MsgSendPulse failed");
	}
	action->lightOn(RESET_LED);
}

void HeightSlow::exit() 
{
	// std::cout << "HeightSlow exit" << std::endl;
	data->setSectorDiff_max();
	data->setSectorDiff_min();
	data->setSlowDur();
	data->setSlowFactor();

	std::cout << std::fixed << std::setprecision(2) << "S1 max. : " << data->getS1Max() << " S2 max. : " << data->getS2Max() << " S3 max. : " << data->getS3Max() << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "S1 min. : " << data->getS1Min() << " S2 min. : " << data->getS2Min() << " S3 min. : " << data->getS3Min() << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "S1 slow : " << data->getSlowDur() << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "SlowFactor : " << data->getSlowFactor() << std::endl;
}

bool HeightSlow::handleResetSp()
{
	exit();
	new (this) SubEndState;
	entry();
	return true;
}
