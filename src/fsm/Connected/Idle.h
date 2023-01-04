/*
 * Idle.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

//States

#ifndef SRC_FSM_CONNECTED_IDLE_H_
#define SRC_FSM_CONNECTED_IDLE_H_

// #include "ServiceMode.h"
#include "Calibration.h"
// #include "OperatingMode.h"
#include "../gof/BaseState.h"
#include "../gof/SubEndState.h"
#include "../Estop.h"

class Idle: public BaseState {
public:
	void entry() override;
	void exit() override;

	//transitions
	// bool handleStartSp() override;
	// bool handleStartLp() override;
	bool handleResetLp() override;
	// bool handleLbSW() override;
	
private:
	void loadConf();
};

#endif /* SRC_FSM_CONNECTED_IDLE_H_ */
