/*
 * IdleError.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "IdleError.h"

IdleError::IdleError() {}
IdleError::~IdleError() {}


void IdleError::entry()
{
	std::cout << "IdleError entry" << std::endl;
}

bool IdleError::handleError(){
    new (this) PendingUnreceipted;
	entry();
	return true;
}