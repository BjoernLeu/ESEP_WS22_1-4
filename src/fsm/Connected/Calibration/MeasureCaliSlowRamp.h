/*
 * MeasureCaliSlowRamp.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "SaveCali.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_MEASURECALISLOWRAMP_H_
#define SRC_FSM_CONNECTED_CALIBRATION_MEASURECALISLOWRAMP_H_

class MeasureCaliSlowRamp: public BaseState {
public:
	MeasureCaliSlowRamp();
	virtual ~MeasureCaliSlowRamp();

	void entry() override;
	bool handleCalcDone() override;

private:
	int getTime();
	void stopTimer();
	void motorOff();
	double getCMs_slow();
	double getCMs_fast();
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_MEASURECALISLOWRAMP_H_ */
