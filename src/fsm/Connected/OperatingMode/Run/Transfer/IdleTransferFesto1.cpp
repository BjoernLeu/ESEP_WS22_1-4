/*
 * IdleTransferFesto1.cpp
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#include "IdleTransferFesto1.h"

IdleTransferFesto1::IdleTransferFesto1() {
	// TODO Auto-generated constructor stub

}

IdleTransferFesto1::~IdleTransferFesto1() {
	// TODO Auto-generated destructor stub
}

	void IdleTransferFesto1::entry() 
	{
		
	}

	//Transitionen
	bool IdleTransferFesto1::handleLbSL()
	{
		checkEmptyBelt();
		entry();
		return true;
	}

	bool IdleTransferFesto1::handleLbO()
	{
		new (this) CheckFesto2;
		entry();
		return true;
	}

	bool IdleTransferFesto1::handleWpArrived()
	{
		checkEmptyBelt();
		entry();
		return true;
	} 

	//Methods
	void IdleTransferFesto1::checkEmptyBelt()
	{
		
	}