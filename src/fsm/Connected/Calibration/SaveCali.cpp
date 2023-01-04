/*
 * SaveCali.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "SaveCali.h"

SaveCali::SaveCali() {}
SaveCali::~SaveCali() {}

void SaveCali::entry()
{
	saveDataInFile();
}	

bool SaveCali::handleSavingDone()
{
	new (this) SubEndState;
	entry();
	return true;
}

void SaveCali::saveDataInFile()
{
	//Too: Code here
}
