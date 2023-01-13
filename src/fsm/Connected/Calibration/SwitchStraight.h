/*
 * SwitchStraight.h
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#ifndef SRC_FSM_CONNECTED_CALIBRATION_SWITCHSTRAIGHT_H_
#define SRC_FSM_CONNECTED_CALIBRATION_SWITCHSTRAIGHT_H_

#include "OutletStraight.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class SwitchStraight: public BaseState {
public:
	SwitchStraight();
	virtual ~SwitchStraight();

	void entry() override;
	bool handleLbO() override;
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_SWITCHSTRAIGHT_H_ */
