/*
 * HeightStraight.h
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#ifndef SRC_FSM_CONNECTED_CALIBRATION_HEIGHTSTRAIGHT_H_
#define SRC_FSM_CONNECTED_CALIBRATION_HEIGHTSTRAIGHT_H_

#include "SwitchStraight.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class HeightStraight: public BaseState {
public:
	HeightStraight();
	virtual ~HeightStraight();

	void entry() override;
	bool handleLbSW() override;
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_HEIGHTSTRAIGHT_H_ */
