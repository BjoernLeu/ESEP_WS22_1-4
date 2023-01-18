/*
 * SwitchRamp.h
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#ifndef SRC_FSM_CONNECTED_CALIBRATION_SWITCHRAMP_H_
#define SRC_FSM_CONNECTED_CALIBRATION_SWITCHRAMP_H_

#include "OutletRamp.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class SwitchRamp: public BaseState {
public:
	SwitchRamp();
	virtual ~SwitchRamp();

	void entry() override;
	bool handleLbO() override;
	bool handleLbSwFree() override;
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_SWITCHRAMP_H_ */
