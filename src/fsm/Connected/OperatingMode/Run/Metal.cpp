/*
 * Metal.cpp
 *
 *  Created on: Dec 07, 2022
 *      Author: daniel
 */

#include "Metal.h"

Metal::Metal() {}
Metal::~Metal() {}

void Metal::entry() {
	std::cout << "Metal entry" << std::endl;
	substate = new IdleMetal;
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

bool Metal::handleNoMetal() 
{
	substate->handleNoMetal();
	return true;
}

bool Metal::handleMetalDetected() 
{
	substate->handleMetalDetected();
	return true;
}
