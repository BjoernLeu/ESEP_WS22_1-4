/*
 * InletSlow.h
 *
 *  Created on: 13.01.2023
 *      Author: bjoern
 */

#ifndef SRC_FSM_CONNECTED_CALIBRATION_INLETSLOW_H_
#define SRC_FSM_CONNECTED_CALIBRATION_INLETSLOW_H_

#include "HeightSlow.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class InletSlow: public BaseState {
public:
	InletSlow();
	virtual ~InletSlow();

	void entry() override;
	bool handleHsWP() override;
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_INLETSLOW_H_ */
