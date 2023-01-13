/*
 * HeightRamp.h
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#ifndef SRC_FSM_CONNECTED_CALIBRATION_HEIGHTRAMP_H_
#define SRC_FSM_CONNECTED_CALIBRATION_HEIGHTRAMP_H_

#include "SwitchRamp.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class HeightRamp: public BaseState {
public:
	HeightRamp();
	virtual ~HeightRamp();

	void entry() override;
	bool handleLbSW() override;
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_HEIGHTRAMP_H_ */
