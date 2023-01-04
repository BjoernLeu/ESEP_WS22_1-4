/*
 * StartCaliSlowRamp.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "MeasureCaliSlowRamp.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_STARTCALISLOWRAMP_H_
#define SRC_FSM_CONNECTED_CALIBRATION_STARTCALISLOWRAMP_H_

class StartCaliSlowRamp: public BaseState {
public:
	StartCaliSlowRamp();
	virtual ~StartCaliSlowRamp();

	void entry() override;
	bool handleHsWP() override;

private:
	void startTimer();
	int getTime();
	void motorOn();
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_STARTCALISLOWRAMP_H_ */
