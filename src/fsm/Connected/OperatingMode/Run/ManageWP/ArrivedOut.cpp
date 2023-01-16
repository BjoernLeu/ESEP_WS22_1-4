/*
 * ArrivedOut.cpp
 *
 *  Created on: 21 Dec 2022
 *      Author: j-oeh
 */

#include "ArrivedOut.h"

ArrivedOut::ArrivedOut() {}
ArrivedOut::~ArrivedOut() {}

void ArrivedOut::entry()
{
		std::cout << "ArrivedOut entry" << std::endl;
	checkEarly();
	manageList();
}

//transitions
bool ArrivedOut::handleManageDone()
{
	new (this) IdleWatch;
	entry();
	return true;
}


//methods
void ArrivedOut::checkEarly()
{

}

void ArrivedOut::manageList()
{

}