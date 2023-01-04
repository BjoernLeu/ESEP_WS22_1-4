/*
 * StartCaliFastLow.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "MeasureCaliFastLow.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_STARTCALIFASTLOW_H_
#define SRC_FSM_CONNECTED_CALIBRATION_STARTCALIFASTLOW_H_

class StartCaliFastLow: public BaseState {
public:
	StartCaliFastLow();
	virtual ~StartCaliFastLow();

	void entry() override;
	bool handleHsWP() override;

private:
	void startTimer();
	int getTime();
	void motorOn();
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_STARTCALIFASTLOW_H_ */
