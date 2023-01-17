/*
 * IdleSlide.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_IDLESLIDE_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_IDLESLIDE_H_

#include "SLExtBusy.h"
#include "SLSelfBusy.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "../../../../Estop.h"

class IdleSlide : public BaseState{
public:
	IdleSlide();
	virtual ~IdleSlide();

	void entry() override;

	//transitions
	bool handleSlSelfFull() override;
	bool handleWpExpected() override;
	bool handleSlExtFull() override;

private:
	void replyBothFree();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_IDLESLIDE_H_ */
