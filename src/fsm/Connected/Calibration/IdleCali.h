/*
 * IdleCali.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "StartCaliFastLow.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_IDLECALI_H_
#define SRC_FSM_CONNECTED_CALIBRATION_IDLECALI_H_

class IdleCali: public BaseState {
public:
	IdleCali();
	virtual ~IdleCali();

	void entry() override;
	bool handleLbI() override;

private:
	void measureBelt();
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_IDLECALI_H_ */
