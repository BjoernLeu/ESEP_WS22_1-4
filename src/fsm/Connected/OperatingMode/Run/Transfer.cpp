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
	substate->handleLbSL();
	return true;
}

bool Transfer::handleLbO()
{
	substate->handleLbO();
	return true;
}

bool Transfer::handleWpArrived()
{
	substate->handleWpArrived();
	return true;
}

bool Transfer::handleTransferOK()
{
	substate->handleTransferOK();
	return true;
}

bool Transfer::handleTransferWait()
{
	substate->handleTransferWait();
	return true;
}

bool Transfer::handleLbOFree()
{
	substate->handleLbOFree();
	return true;
}

bool Transfer::handleWpTransfer()
{
	substate->handleWpTransfer();
	return true;
}

bool Transfer::handleLbI()
{
	substate->handleLbI();
	return true;
}
