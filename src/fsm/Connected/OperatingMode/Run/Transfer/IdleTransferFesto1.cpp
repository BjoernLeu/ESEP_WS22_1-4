/*
 * IdleTransferFesto1.cpp
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#include "IdleTransferFesto1.h"

IdleTransferFesto1::IdleTransferFesto1() {}
IdleTransferFesto1::~IdleTransferFesto1() {}

void IdleTransferFesto1::entry() 
{
	std::cout << "Transfer/IdleTransferFesto1 entry" << std::endl;
}

//Transitionen
bool IdleTransferFesto1::handleLbSL()
{
	std::cout << "Transfer/IdleTransferFesto1 handleLbSL" << std::endl;
	checkEmptyBelt();
	return true;
}

bool IdleTransferFesto1::handleWpArrived()
{
	std::cout << "Transfer/IdleTransferFesto1 handleWpArrived" << std::endl;
	checkEmptyBelt();
	return true;
} 

bool IdleTransferFesto1::handleLbO()
{
	std::cout << "Transfer/IdleTransferFesto1 handleLbO" << std::endl;
	new (this) CheckFesto2;
	entry();
	return true;
}

//Methods
void IdleTransferFesto1::checkEmptyBelt()
{
	std::cout << "Transfer/IdleTransferFesto1 checkEmptyBelt" << std::endl;
	if(data->getNumberWpsOnBelt() == NO_WP_DETECTED)
	{
		if (MsgSendPulse(coid, -1, static_cast<int>(EMPTY_BELT), 0) == -1) {
			perror("MsgSendPulse failed");
		}	
	}
}
