/*
 * SortWPBothFull.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "SortWPBothFull.h"

SortWPBothFull::SortWPBothFull() {}

SortWPBothFull::~SortWPBothFull() {}

void SortWPBothFull::entry()
{
	std::cout << "SortWPBothFull entry" << std::endl;
}

bool SortWPBothFull::handleFlat()
{
	new (this) TooFull;
	entry();
	return true;
}

bool SortWPBothFull::handleOutOfOrder()
{
	new (this) Pass;
	entry();
	return true;
}