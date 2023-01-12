/*
 * CheckWP.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "CheckWP.h"

CheckWP::CheckWP() {}

CheckWP::~CheckWP() {}

void CheckWP::entry()
{
	std::cout << "CheckWP entry" << std::endl;
	checkWP();
}

bool CheckWP::handleOutOfOrder()
{
	new(this) CheckSlide();
	entry();
	return true;
}

bool CheckWP::handleInOrder()
{
	new(this) Pass();
	entry();
	return true;
}

void CheckWP::checkWP()
{
	if(data->getWP_Expected){
		handleInOrder();
	} else {
		handleOutOfOrder();
	}
}

