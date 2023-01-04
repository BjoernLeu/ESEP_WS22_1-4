/*
 * SL1Busy.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_SLSELFBUSY_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_SLSELFBUSY_H_

#include "IdleSlide.h"
#include "BothBusy.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "../../../../Estop.h"

class SLSelfBusy : public BaseState{
public:
	SLSelfBusy();
	virtual ~SLSelfBusy();
	
	void entry() override;

	//transition
	bool handleWPExpected() override;
	bool handleSLSelfFree() override;
	bool handleSLExtFull() override;

private:
	void replySelfBusy();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_SLSELFBUSY_H_ */
