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
