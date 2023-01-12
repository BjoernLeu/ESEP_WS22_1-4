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
	std::cout << "CheckSlide entry" << std::endl
	//bothfree
	if (checkSlide() == 1) {
		handleSlBothFree(); 
	}
	//bothfull
	else if (checkSlide() == 2) {
		handleSlBothFull();
	}
	else if (checkSlide() == 3) {
		handleSlSelfFull();
	}
	//extfull
	else if (checkSlide() == 3) {
		handleSlExtFull();
	}
	else {
		std::cout << "Error by Festo1" << std::endl;
	}
}

bool CheckSlide::handleSlSelfFull()
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
		new (this) SortWPBothFull;
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

int CheckSlide::checkSlide()
{
	if(data->getSlSelf == true && data->getSlExt == true){
		return 1;
	} else if (data->getSlSelf == false && data->getSlExt == false){
		return 2;
	} else if (data->getSlSelf == false){
		return 3;
	} else if (data->getSlExt == false){
		return 4;
	} else {
		std::cout << "Error! Can not read from Slide" << std::endl;
	}
	return 0; 
}
