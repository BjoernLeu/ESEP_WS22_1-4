/*
 * OutletRamp.h
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#ifndef SRC_FSM_CONNECTED_CALIBRATION_OUTLETRAMP_H_
#define SRC_FSM_CONNECTED_CALIBRATION_OUTLETRAMP_H_

#include "InletSlow.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class OutletRamp: public BaseState {
public:
	OutletRamp();
	virtual ~OutletRamp();

	void entry() override;
	bool handleLbI() override;
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_OUTLETRAMP_H_ */
