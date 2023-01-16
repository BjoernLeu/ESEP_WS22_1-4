/*
 * BothBusy.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_BOTHBUSY_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_BOTHBUSY_H_

#include "IdleSlide.h"
#include "SLExtBusy.h"
#include "SLSelfBusy.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "../../../../Estop.h"

class BothBusy : public BaseState{
public:
	BothBusy();
	virtual ~BothBusy();

	void entry() override;

	//transitions
	bool handleWPExpected() override;
	bool handleSLSelfFree() override;
	bool handleSLExtFree() override;

private:
	void replyBothFull();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_BOTHBUSY_H_ */
