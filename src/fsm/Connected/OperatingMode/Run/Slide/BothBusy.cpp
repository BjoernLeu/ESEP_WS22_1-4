/*
 * BothBusy.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "BothBusy.h"

BothBusy::BothBusy() {}
BothBusy::~BothBusy() {}

bool BothBusy::handleWPExpected()
{
	replyBothBusy();
}

bool BothBusy::handleSLSelfFree()
{
	if (data->getSlExt())
	{
		new (this) IdleSlide;
		entry();
		return true;
	}
	else 
	{
		new (this) SLExtBusy;
		entry();
		return true;
	}
}

bool BothBusy::handleSLExtFree()
{
	new (this) SLSelfBusy;
	entry();
	return true;
}

void BothBusy::replyBothBusy()
{
	//ToDo: implement me
}

