/*
 * TransferFesto.cpp
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#include "TransferFesto.h"

TransferFesto::TransferFesto() {}
TransferFesto::~TransferFesto() {}

void TransferFesto::entry()
{
	if(data->getFesto() == FESTOONE)
	{
		new (this) IdleTransferFesto1;
		entry();
	}
	else if(data->getFesto() == FESTOTWO)
	{
		new (this) IdleTransferFesto2;
		entry();
	}
	else
	{
		std::cout << "Error! \nCannot find the Festo with the given integer!" << std::endl;
	}	
}
