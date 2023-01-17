/*
 * MetalState.cpp
 *
 *  Created on: Dec 07, 2022
 *      Author: daniel
 */

#include "MetalState.h"

MetalState::MetalState() {}
MetalState::~MetalState() {}

void MetalState::entry() {
	std::cout << "MetalState entry" << std::endl;
	substate = new IdleMetal;
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

bool MetalState::handleNoMetal() 
{
	std::cout << "MetalState handleNoMetal" << std::endl;
	substate->handleNoMetal();
	return true;
}

bool MetalState::handleWpMetal() 
{
	std::cout << "MetalState handleWpMetal" << std::endl;
	substate->handleWpMetal();
	return true;
}
