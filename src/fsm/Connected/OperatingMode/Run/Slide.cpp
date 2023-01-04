/*
 * Slide.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "Slide.h"

Slide::Slide(){}
Slide::~Slide(){}

void Slide::entry() 
{
	std::cout << "Slide entry" << std::endl;
	substate = new IdleSlide;
	substate->setData(data);
	substate->setAction(action);
	substate->entry();
}

bool Slide::handleSLExtFull() 
{
	substate->handleSLExtFull();
	return true;
}

bool Slide::handleSLSelfFree() 
{
	substate->handleSLSelfFree();
	return true;
}

bool Slide::handleSLSelfFull() 
{
	substate->handleSLSelfFull();
	return true;
}

bool Slide::handleWPExpected() 
{
	substate->handleWPExpected();
	return true;
}

bool Slide::handleSLExtFree()
{
	substate->handleSLExtFree();
	return true;
}
