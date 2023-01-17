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
	int* expWp = data->getExpectedWp(); //[0] == height, [1] == metal, [2] == isDrilling    

	if ((data->getWpType() == WP_HIGH) == expWp[EXP_HEIGHT]) //getWpType is not implemented yet
	{
		handleInOrder();
	}
	else if ((data->getWpType() == WP_DRILLING) == expWp[EXP_ISDRILLING])
	{
		if (data->getWpMetal() == expWp[EXP_METAL])//getWpType is noch implemented yet 
		{
			handleInOrder();
		}
		else 
		{
			handleOutOfOrder();
		}
	}
	else if ((data->getWpType() == WP_FLAT) == !expWp[EXP_HEIGHT])
	{
		handleInOrder();
	}
	else 
	{
		handleOutOfOrder();
	}
}

