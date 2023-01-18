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
	// std::cout << "IdleCali entry" << std::endl;
	measureBelt();
}

bool IdleCali::handleStartSp()
{
	new (this) MeasureHighCali;
	entry();
	return true;
}

void IdleCali::measureBelt(){
	data->mp->setZero();
}
