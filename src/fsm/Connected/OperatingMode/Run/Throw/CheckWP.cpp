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
	if(data->getWP_Expected()){
		std::cout << "CheckWP handleInOrder" << std::endl;
		handleInOrder();
	} else {
		std::cout << "CheckWP handleOutOfOrder" << std::endl;
		handleOutOfOrder();
	}
}

