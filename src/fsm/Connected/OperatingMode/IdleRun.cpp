/*
 * IdleRun.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "IdleRun.h"

IdleRun::IdleRun() {}

IdleRun::~IdleRun() {}

bool IdleRun::handleLbI() 
{
	new(this) Run();
	entry();
	return true;
}

void IdleRun::entry(){
	std::cout << "IdleRun entry" << std::endl;
}