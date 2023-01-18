/*
 * IdleMetal.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "IdleMetal.h"

IdleMetal::IdleMetal() {}
IdleMetal::~IdleMetal() {}

void IdleMetal::entry()
{
	// std::cout << "IdleMetal entry" << std::endl;
}

bool IdleMetal::handleWpMetal()
{
	new (this) SetMetal;
	entry();
	return true;
}
