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
	std::cout << "Throw handleSlSelfFull" << std::endl;
	substate->handleSlSelfFull();
	return true;
}

bool Throw::handleSlBothFree() 
{
	std::cout << "Throw handleSlBothFree" << std::endl;
	substate->handleSlBothFree();
	return true;
}

bool Throw::handleSlExtFull() 
{
	std::cout << "Throw handleSlExtFull" << std::endl;
	substate->handleSlExtFull();
	return true;
}

bool Throw::handleSlBothFull() 
{
	std::cout << "Throw handleSlBothFull" << std::endl;
	substate->handleSlBothFull();
	return true;
}

bool Throw::handleOutOfOrder() 
{
	std::cout << "Throw handleOutOfOrder" << std::endl;
	substate->handleOutOfOrder();
	return true;
}

bool Throw::handleInOrder() 
{
	std::cout << "Throw handleInOrder" << std::endl;
	substate->handleInOrder();
	return true;
}

bool Throw::handleLbSW() 
{
	std::cout << "Throw handleLbSW" << std::endl;
	substate->handleLbSW();
	return true;
}

bool Throw::handleLbSwFree() 
{
	std::cout << "Throw handleLbSwFree" << std::endl;
	substate->handleLbSwFree();
	return true;
}

bool Throw::handleFlat() 
{
	std::cout << "Throw handleFlat" << std::endl;
	substate->handleFlat();
	return true;
}

bool Throw::handleSignalReceipted() 
{
	std::cout << "Throw bool Throw::handleSignalReceipted()" << std::endl;
	substate->handleSignalReceipted();
	return true;
}

