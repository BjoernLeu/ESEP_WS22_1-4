/*
 * WPDisappeared.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_ERROR_WPDISAPPEARED_H_
#define SRC_FSM_CONNECTED_ERROR_WPDISAPPEARED_H_

#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class WPDisappeared : public BaseState{
public:
	WPDisappeared();
	virtual ~WPDisappeared();

	//transitions
	bool handleStartSp() override;

	//Methods
	void entry() override;
	void exit() override;

private: 
	void motorOn();
	void removeFromList();
	
};

#endif /* SRC_FSM_CONNECTED_ERROR_WPDISAPPEARED_H_ */