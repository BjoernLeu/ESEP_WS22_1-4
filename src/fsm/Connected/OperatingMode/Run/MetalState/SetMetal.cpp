/*
 * SetMetal.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "SetMetal.h"

SetMetal::SetMetal() {}
SetMetal::~SetMetal() {}

void SetMetal::entry()
{
	// std::cout << "SetMetal entry" << std::endl;
	setMType();
}

bool SetMetal::handleNoMetal()
{
	new (this) IdleMetal;
	entry();
	return true;
}

void SetMetal::setMType()
{
	data->addWpMetal();
}
