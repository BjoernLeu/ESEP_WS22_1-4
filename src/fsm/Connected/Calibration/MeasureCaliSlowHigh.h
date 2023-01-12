/*
 * MeasureCaliSlowHigh.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "StartCaliFastRamp.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_MEASURECALISLOWHIGH_H_
#define SRC_FSM_CONNECTED_CALIBRATION_MEASURECALISLOWHIGH_H_

class MeasureCaliSlowHigh: public BaseState {
public:
	MeasureCaliSlowHigh();
	virtual ~MeasureCaliSlowHigh();

	void entry() override;
	bool handleLbI() override;

private:
	int getTime();
	void stopTimer();
	void motorOff();
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_MEASURECALISLOWHIGH_H_ */
