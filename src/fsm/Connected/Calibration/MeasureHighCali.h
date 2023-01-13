/*
 * MeasureHighCali.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "InletStraight.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_MEASUREHIGHCALI_H_
#define SRC_FSM_CONNECTED_CALIBRATION_MEASUREHIGHCALI_H_

class MeasureHighCali: public BaseState {
public:
	MeasureHighCali();
	virtual ~MeasureHighCali();

	void entry() override;
	bool handleLbI() override;

private:
	void measureHigh();
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_MEASUREHIGHCALI_H_ */
