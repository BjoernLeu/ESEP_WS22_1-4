/*
 * CeckSlide.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "CheckSlide.h"

CheckSlide::CheckSlide() {}

CheckSlide::~CheckSlide() {}

void CheckSlide::entry()
{
	std::cout << "CheckSlide entry" << std::endl;

	//bothfree
	if(data->getSlSelf() && data->getSlExt()){
		std::cout << "data->getSlSelf() && data->getSlExt()" << std::endl;
		handleSlBothFree(); 
	//bothfull
	} else if (!data->getSlSelf() && !data->getSlExt()){
		std::cout << "data->getSlSelf() == false && data->getSlExt() == false" << std::endl;
		handleSlBothFull();
	//selffull
	} else if (!data->getSlSelf() && data->getSlExt()){
		std::cout << "data->getSlSelf() == false" << std::endl;
		handleSlSelfFull();
	//extfull
	} else if (!data->getSlExt() && data->getSlSelf()){
		std::cout << "data->getSlExt() == false" << std::endl;
		handleSlExtFull();
	} else {
		std::cout << "Error! Can not read from Slide" << std::endl;
	}
}

bool CheckSlide::handleSlSelfFull()
{
	if(checkFesto() == 1){
		new (this) Pass;
		entry();
		return true;
	} else if (checkFesto() == 2){
		std::cout << "handleSlSelfFull TooFull" << std::endl;
		new (this) TooFull;
		entry();
		return true;
	} else {
		std::cout << "Error! Identity of Festo unclear" << std::endl;
	}
	return false;
}

bool CheckSlide::handleSlBothFree()
{
	if(checkFesto() == 1){
		new (this) SortWPFree;
		entry();
		return true;
	} else if (checkFesto() == 2){
		new (this) ThrowWP;
		entry();
		return true;
	} else {
		std::cout << "Error! Identity of Festo unclear" << std::endl;
	}
	return false;
}

bool CheckSlide::handleSlExtFull()
{
	if(checkFesto() == 1){
		new (this) SortWPFree;
		entry();
		return true;
	} else if (checkFesto() == 2){
		new (this) ThrowWP;
		entry();
		return true;
	} else {
		std::cout << "Error! Identity of Festo unclear" << std::endl;
	}
	return false;
}

bool CheckSlide::handleSlBothFull()
{
	if(checkFesto() == 1){
		new (this) Pass;
		entry();
		return true;
	} else if (checkFesto() == 2){
		new (this) TooFull;
		entry();
		return true;
	} else {
		std::cout << "Error! Identity of Festo unclear" << std::endl;
	}
	return false;
}

int CheckSlide::checkFesto()
{
	return data->getFesto();
}
