/*
 * Calibration.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_CALIBRATION_H_
#define SRC_FSM_CONNECTED_CALIBRATION_H_

#include "Idle.h"
#include "Calibration/IdleCali.h"
#include "../gof/BaseState.h"
#include "../gof/SubEndState.h"
#include "../Estop.h"

class Calibration: public BaseState {
public:
	Calibration();
	virtual ~Calibration();
	
	void entry() override;	

	//Transitions
	bool handleResetSp() override;
	bool handleLbI() override;
	bool handleHsWP() override;
	bool handleLbSW() override;
	bool handleLbO() override;
	bool handleCalcDone() override;
	bool handleStartSp() override;
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_H_ */
