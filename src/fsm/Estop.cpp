/*
 * Estop.cpp
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 *      Author: Pascal
 */

#include "Estop.h"

Estop::Estop() {}
Estop::~Estop() {}

void Estop::entry()
{
	std::cout << "ESTOP entry" << std::endl;
	action->blinkingOff(ALL);
	action->lightOn(RED);
	action->lightOn(RED);
	substate = new SafeState;
	substate->setData(data);
	substate->entry();
}

bool Estop::handleResetSp()
{
	substate->handleResetSp();

	if(substate->isSubEndState()){
		// std::cout << "handleResetSp" << std::endl;
		std::cout << "Connection: " <<data->getConnection() << "; Self: " << data->getEstopSelf() << "; Ext: " << data-> getEstopExt() << std::endl;
		if(data->getConnection() && !data->getEstopSelf() && !data->getEstopExt()){
			new (this) Connected();
			entry();
		}else if(!data->getConnection() && !data->getEstopSelf() && !data->getEstopExt()){
			new (this) Connecting();
			entry();
		}
	}
	return true;
}

bool Estop::handleEstopDone() 
{
	substate->handleEstopDone();
	return true;
}

bool Estop::handleEstopSelfPressed() 
{
	substate->handleEstopSelfPressed();
	return true;
}

bool Estop::handleEstopSelfReleased() 
{
	substate->handleEstopSelfReleased();
	return true;
}

bool Estop::handleEstopExtPressed() 
{
	substate->handleEstopExtPressed();
	return true;
}

bool Estop::handleEstopExtReleased() 
{
	substate->handleEstopExtReleased();
	return true;
}

// bool Estop::handleStopLp() {
// 	substate->handleStopLp();
// 	return true;
// }
bool Estop::handleConLost() {
	data->setConnectionFalse();
	substate->handleConLost();
	return true;
}

