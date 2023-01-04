/*
 * MeasureHeight.h
 *
 *  Created on: Dec 07, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_

#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"

class MeasureHeight : public BaseState {
public:
	MeasureHeight();
	virtual ~MeasureHeight();

	//transition
	bool handleHsBelt();
	bool handleHsWP();

	//methods
	void entry() override;
	void exit() override;

private:
	void motorSlow();
	void motorFast();
	void setHType();
	void pollHS();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_ */
