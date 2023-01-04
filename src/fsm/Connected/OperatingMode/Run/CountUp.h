/*
 * CountUp.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTUP_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTUP_H_

#include "../../Error.h"
#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"

class CountUp : public BaseState {
public:
	CountUp();
	virtual ~CountUp();

	//transition
	bool handleLbI();
	
	//methods
	void entry() override;
	void exit() override;

private: 
	void checkCount();
	void currentCount();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTUP_H_ */
