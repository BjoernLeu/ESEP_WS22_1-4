/*
 * ArrivedSwitch.cpp
 *
 *  Created on: 21 Dec 2022
 *      Author: j-oeh
 */

#include "ArrivedSwitch.h"

ArrivedSwitch::ArrivedSwitch() {}
ArrivedSwitch::~ArrivedSwitch() {}

void ArrivedSwitch::entry()
{
	checkEarly();
	manageList();
}

//transitions
bool ArrivedSwitch::handleManageDone()
{
	new (this) IdleWatch;
	entry();
	return true;
}


//methods
void ArrivedSwitch::checkEarly()
{

}

void ArrivedSwitch::manageList()
{

}
