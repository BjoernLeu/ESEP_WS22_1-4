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

bool Slide::handleSlExtFull() 
{
	std::cout << "Slide handleSlExtFull" << std::endl;
	substate->handleSlExtFull();
	return true;
}

bool Slide::handleSlSelfFree() 
{
	std::cout << "Slide handleSlSelfFree" << std::endl;
	substate->handleSlSelfFree();
	return true;
}

bool Slide::handleSlSelfFull() 
{
	std::cout << "Slide handleSlSelfFull" << std::endl;
	substate->handleSlSelfFull();
	return true;
}

bool Slide::handleWpExpected() 
{
	std::cout << "Slide handleWpExpected" << std::endl;
	substate->handleWpExpected();
	return true;
}

bool Slide::handleSlExtFree()
{
	std::cout << "Slide handleSlExtFree" << std::endl;
	substate->handleSlExtFree();
	return true;
}
