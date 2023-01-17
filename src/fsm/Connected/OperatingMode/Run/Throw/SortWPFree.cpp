/*
 * SortWPFree.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "SortWPFree.h"

SortWPFree::SortWPFree() {}

SortWPFree::~SortWPFree() {}

void SortWPFree::entry()
{
	std::cout << "SortWPFree entry" << std::endl;
	checkFlat();
}

bool SortWPFree::handleOutOfOrder()
{
	new (this) Pass;
	entry();
	return true;
}

bool SortWPFree::handleFlat()
{
	new (this) ThrowWP;
	entry();
	return true;
}

void SortWPFree::checkFlat(){
	if (data->getWpType() == 56){
		handleFlat();
	} else {
		handleOutOfOrder();
	}
}
