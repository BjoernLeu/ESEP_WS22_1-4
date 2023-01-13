/*
 * Throw.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "Throw.h"

Throw::Throw(){}

Throw::~Throw(){}

void Throw::entry()
{
	std::cout << "Throw entry" << std::endl;
	substate = new IdleThrow;
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

bool Throw::handleSlSelfFull() 
{
	substate->handleSlSelfFull();
	return true;
}

bool Throw::handleSlBothFree() 
{
	substate->handleSlBothFree();
	return true;
}

bool Throw::handleSlExtFull() 
{
	substate->handleSlExtFull();
	return true;
}

bool Throw::handleSlBothFull() 
{
	substate->handleSlBothFull();
	return true;
}

bool Throw::handleOutOfOrder() 
{
	substate->handleOutOfOrder();
	return true;
}

bool Throw::handleInOrder() 
{
	substate->handleInOrder();
	return true;
}

bool Throw::handleLbSW() 
{
	substate->handleLbSW();
	return true;
}

bool Throw::handleLbSwFree() 
{
	substate->handleLbSwFree();
	return true;
}

bool Throw::handleFlat() 
{
	substate->handleFlat();
	return true;
}

bool Throw::handleSignalReceipted() 
{
	substate->handleSignalReceipted();
	return true;
}

