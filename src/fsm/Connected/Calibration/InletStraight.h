/*
 * InletStraight.h
 *
 *  Created on: Dec 3, 2022
 *      Author: björn
 */

#include "HeightStraight.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_INLETSTRAIGHT_H_
#define SRC_FSM_CONNECTED_CALIBRATION_INLETSTRAIGHT_H_

class InletStraight: public BaseState {
public:
	InletStraight();
	virtual ~InletStraight();

	void entry() override;
	bool handleHsWP() override;
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_INLETSTRAIGHT_H_ */
