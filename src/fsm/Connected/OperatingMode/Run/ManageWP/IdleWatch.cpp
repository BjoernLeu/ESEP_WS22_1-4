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
	std::cout << "idleWatch handleHsWP" << std::endl;
	new (this) ArrivedHeight;
	entry();
	return true;
}

bool IdleWatch::handleLbSW()
{
	std::cout << "idleWatch handleLbSW" << std::endl;
	new (this) ArrivedSwitch;
	entry();
	return true;
}

bool IdleWatch::handleLbO()
{
	std::cout << "idleWatch handleLbO" << std::endl;
	new (this) ArrivedOut;
	entry();
	return true;
}
