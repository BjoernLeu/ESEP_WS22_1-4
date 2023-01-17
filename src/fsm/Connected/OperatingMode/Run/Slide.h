/*
 * Slide.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_H_

#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"
#include "Slide/IdleSlide.h"

class Slide : public BaseState{
public:
	Slide();
	virtual ~Slide();

	void entry() override;

	//transitions
	bool handleSlExtFree() override;
	bool handleSlExtFull() override;
	bool handleWpExpected() override;
	bool handleSlSelfFree() override;
	bool handleSlSelfFull() override;
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_SLIDE_H_ */
