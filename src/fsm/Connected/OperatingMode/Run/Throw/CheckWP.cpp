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

	int type = data->getWpType(); 
	bool isMetal = data->getWpMetal();

	//If the workpiece is High
	if (((type != WP_FLAT) && (type == WP_HIGH) && (type != WP_DRILLING) && !isMetal) && (tempExpectedWorkpiece.height && !tempExpectedWorkpiece.isDrilling && !tempExpectedWorkpiece.metal))
	{
		//std::cout << "\t\tHigh in order" << std::endl;
		data->increaseExpectedCount();
		handleInOrder();
	}
	//If the workpiece have a Drilling
	else if (((type != WP_FLAT) && (type != WP_HIGH) && (type == WP_DRILLING) && !isMetal) && (tempExpectedWorkpiece.height && tempExpectedWorkpiece.isDrilling && !tempExpectedWorkpiece.metal)) 
	{
		//std::cout << "\t\tDrilling in order" << std::endl;
		data->increaseExpectedCount();
		handleInOrder();
	}
	//If the Workpiece have metal
	else if (((type != WP_FLAT) && (type != WP_HIGH) && (type == WP_DRILLING) && isMetal) && (tempExpectedWorkpiece.height && tempExpectedWorkpiece.isDrilling && tempExpectedWorkpiece.metal))
	{
		//std::cout << "\t\tMetal in order" << std::endl;
		data->increaseExpectedCount();
		handleInOrder();
	}
	//If the workpiece is flat
	else if (((type == WP_FLAT) && (type != WP_HIGH) && (type != WP_DRILLING) && !isMetal) && (!tempExpectedWorkpiece.height && !tempExpectedWorkpiece.isDrilling && !tempExpectedWorkpiece.metal))
	{
		//std::cout << "\t\tflat in order" << std::endl;
		data->increaseExpectedCount();
		handleInOrder();
	}
	else 
	{
		//std::cout << "\t\telse out of order" << std::endl;
		handleOutOfOrder();
	}
}
