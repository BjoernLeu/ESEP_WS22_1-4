/*
 * StartCaliFastRamp.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "MeasureCaliFastRamp.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_STARTCALIFASTRAMP_H_
#define SRC_FSM_CONNECTED_CALIBRATION_STARTCALIFASTRAMP_H_

class StartCaliFastRamp: public BaseState {
public:
	StartCaliFastRamp();
	virtual ~StartCaliFastRamp();

	void entry() override;
	bool handleHsWP() override;

private:	
	void startTimer();
	int getTime();
	void motorOn();
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_STARTCALIFASTRAMP_H_ */
