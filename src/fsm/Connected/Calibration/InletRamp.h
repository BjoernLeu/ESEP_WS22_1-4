/*
 * InletRamp.h
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#ifndef SRC_FSM_CONNECTED_CALIBRATION_INLETRAMP_H_
#define SRC_FSM_CONNECTED_CALIBRATION_INLETRAMP_H_

#include "HeightRamp.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class InletRamp: public BaseState {
public:
	InletRamp();
	virtual ~InletRamp();

	void entry() override;
	bool handleHsWP() override;
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_INLETRAMP_H_ */
