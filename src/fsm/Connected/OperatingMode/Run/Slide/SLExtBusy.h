/*
 * SL2Busy.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_SLEXTBUSY_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_SLEXTBUSY_H_

#include "IdleSlide.h"
#include "BothBusy.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "../../../../Estop.h"

class SLExtBusy : public BaseState{
public:
	SLExtBusy();
	virtual ~SLExtBusy();

	void entry() override;

	//transitions
	bool handleSLExtFree() override;
	bool handleSLSelfFull() override;
	bool handleWPExpected() override;

private:
	void replyExtBusy();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_SLEXTBUSY_H_ */
