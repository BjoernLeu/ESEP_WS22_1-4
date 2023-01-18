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
	struct {
		bool height;
		bool metal;
		bool isDrilling;
	} tempExpectedWorkpiece;

	tempExpectedWorkpiece.height = data->getExpectedWpHeight(); 
	tempExpectedWorkpiece.metal = data->getExpectedWpMetal();
	tempExpectedWorkpiece.isDrilling = data->getExpectedWpIsDrilling();
	data->increaseExpectedCount();

	if ((data->getWpType() == WP_HIGH) == tempExpectedWorkpiece.height)
	{
		handleInOrder();
	}
	else if ((data->getWpType() == WP_DRILLING) == tempExpectedWorkpiece.isDrilling)
	{
		if (data->getWpMetal() == tempExpectedWorkpiece.metal)
		{
			handleInOrder();
		}
		else 
		{
			handleOutOfOrder();
		}
	}
	else if ((data->getWpType() == WP_FLAT) == !tempExpectedWorkpiece.height)
	{
		handleInOrder();
	}
	else 
	{
		handleOutOfOrder();
	}
}

