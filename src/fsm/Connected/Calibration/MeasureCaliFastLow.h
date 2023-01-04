/*
 * MeasureCaliFastLow.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "StartCaliSlowHigh.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_MEASURECALIFASTLOW_H_
#define SRC_FSM_CONNECTED_CALIBRATION_MEASURECALIFASTLOW_H_

class MeasureCaliFastLow: public BaseState {
public:
	MeasureCaliFastLow();
	virtual ~MeasureCaliFastLow();

	void entry() override;
	bool handleLbI() override;
	
private:	
	int getTime();
	void stopTimer();
	void motorOff();
	void setLowValue();
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_MEASURECALIFASTLOW_H_ */
