/*
 * StartCaliSlowHigh.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "MeasureCaliSlowHigh.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_STARTCALISLOWHIGH_H_
#define SRC_FSM_CONNECTED_CALIBRATION_STARTCALISLOWHIGH_H_

class StartCaliSlowHigh: public BaseState {
public:
	StartCaliSlowHigh();
	virtual ~StartCaliSlowHigh();

	void entry() override;
	bool handleHsWP() override;

private:
	void startTimer();
	int getTime();
	void motorOn();

};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_STARTCALISLOWHIGH_H_ */
