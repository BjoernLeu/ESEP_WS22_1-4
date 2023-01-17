/*
 * Transfer.cpp
 *
 *  Created on: Dec 22, 2022
 *      Author: daniel
 */

#include "Transfer.h"

Transfer::Transfer() {}
Transfer::~Transfer() {}

void Transfer::entry()
{
	std::cout << "Transfer entry" << std::endl;
	substate = new TransferFesto;
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

bool Transfer::handleLbSL()
{
	std::cout << "Transfer handleLbSL" << std::endl;
	substate->handleLbSL();
	return true;
}

bool Transfer::handleLbO()
{
	std::cout << "Transfer handleLbO" << std::endl;
	substate->handleLbO();
	return true;
}

bool Transfer::handleWpArrived()
{
	std::cout << "Transfer handleWpArrived" << std::endl;
	substate->handleWpArrived();
	return true;
}

bool Transfer::handleTransferOK()
{
	std::cout << "Transfer handleTransferOK" << std::endl;
	substate->handleTransferOK();
	return true;
}

bool Transfer::handleTransferWait()
{
	std::cout << "Transfer handleTransferWait" << std::endl;
	substate->handleTransferWait();
	return true;
}

bool Transfer::handleLbOFree()
{
	std::cout << "Transfer handleLbOFree" << std::endl;
	substate->handleLbOFree();
	return true;
}

bool Transfer::handleWpTransfer()
{
	std::cout << "Transfer handleWpTransfer" << std::endl;
	substate->handleWpTransfer();
	return true;
}

bool Transfer::handleLbI()
{
	std::cout << "Transfer handleLbI" << std::endl;
	substate->handleLbI();
	return true;
}
