/*
 * MeasureCaliFastRamp.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "StartCaliSlowRamp.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_MEASURECALIFASTRAMP_H_
#define SRC_FSM_CONNECTED_CALIBRATION_MEASURECALIFASTRAMP_H_

class MeasureCaliFastRamp: public BaseState {
public:
	MeasureCaliFastRamp();
	virtual ~MeasureCaliFastRamp();

	void entry() override;
	bool handleLbI() override;

public:	
	int getTime();
	void stopTimer();
	void motorOff();
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_MEASURECALIFASTRAMP_H_ */
