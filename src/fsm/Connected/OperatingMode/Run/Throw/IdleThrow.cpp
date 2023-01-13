/*
 * IdleThrow.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "IdleThrow.h"

IdleThrow::IdleThrow() {}

IdleThrow::~IdleThrow() {}

void IdleThrow::entry()
{
	std::cout << "IdleThrow entry" << std::endl;
}

bool IdleThrow::handleLbSW()
{
	new(this) CheckWP();
	entry();
	return true;
}
