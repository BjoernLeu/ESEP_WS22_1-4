/*
 * OutletStraight.h
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#ifndef SRC_FSM_CONNECTED_CALIBRATION_OUTLETSTRAIGHT_H_
#define SRC_FSM_CONNECTED_CALIBRATION_OUTLETSTRAIGHT_H_

#include "InletRamp.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class OutletStraight: public BaseState {
public:
	OutletStraight();
	virtual ~OutletStraight();

	void entry() override;
	bool handleLbI() override;
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_OUTLETSTRAIGHT_H_ */
