/*
 * IdleWatch.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "IdleWatch.h"

IdleWatch::IdleWatch(){}
IdleWatch::~IdleWatch(){}

void IdleWatch::entry()
{
	std::cout << "idleWatch entry" << std::endl;
}

bool IdleWatch::handleHsWP()
{
	new (this) ArrivedHeight;
	entry();
	return true;
}

bool IdleWatch::handleLbSW()
{
	new (this) ArrivedSwitch;
	entry();
	return true;
}

bool IdleWatch::handleLbO()
{
	new (this) ArrivedOut;
	entry();
	return true;
}
