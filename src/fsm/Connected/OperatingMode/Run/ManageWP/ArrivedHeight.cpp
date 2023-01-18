/*
 * ArrivedHeight.cpp
 *
 *  Created on: 21 Dec 2022
 *      Author: j-oeh
 */

#include "ArrivedHeight.h"

ArrivedHeight::ArrivedHeight() {}
ArrivedHeight::~ArrivedHeight() {}

void ArrivedHeight::entry()
{
	// std::cout << "ArrivedHeight entry" << std::endl;
	checkEarly();
	manageList();
}

//transitions
bool ArrivedHeight::handleManageDone()
{
	new (this) IdleWatch;
	entry();
	return true;
}


//methods
void ArrivedHeight::checkEarly()
{

}

void ArrivedHeight::manageList()
{

}

