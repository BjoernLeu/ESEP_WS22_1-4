/*
 * HeightSlow.h
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#ifndef SRC_FSM_CONNECTED_CALIBRATION_HEIGHTSLOW_H_
#define SRC_FSM_CONNECTED_CALIBRATION_HEIGHTSLOW_H_

#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class HeightSlow: public BaseState {
public:
	HeightSlow();
	virtual ~HeightSlow();

	void entry() override;
	void exit() override;
	bool handleResetSp() override;
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_HEIGHTSLOW_H_ */
