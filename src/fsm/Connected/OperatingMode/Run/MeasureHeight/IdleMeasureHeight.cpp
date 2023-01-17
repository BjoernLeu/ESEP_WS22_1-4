/*
 * IdleMeasureHeight.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "IdleMeasureHeight.h"

IdleMeasureHeight::IdleMeasureHeight() {}
IdleMeasureHeight::~IdleMeasureHeight() {}

bool IdleMeasureHeight::handleHsWP()
{
	std::cout << "IdleMeasureHeight handleHsWP" << std::endl;
	data->changeSeg2();
	new (this) Measure;
	entry();
	return true;
}

void IdleMeasureHeight::entry(){
	std::cout << "IdleMeasureHeight entry" << std::endl;
}
