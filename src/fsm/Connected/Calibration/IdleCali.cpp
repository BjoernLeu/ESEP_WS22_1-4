/*
 * IdleCali.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "IdleCali.h"

IdleCali::IdleCali() {}
IdleCali::~IdleCali() {}

void IdleCali::entry() 
{
	std::cout << "IdleCali entry" << std::endl;
	measureBelt();
}

bool IdleCali::handleLbI()
{
	data->mp.setHigh();
	new (this) StartCaliFastLow;
	entry();
	return true;
}

void IdleCali::measureBelt(){
	data->mp.setZero();
}