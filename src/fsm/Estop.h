/*
 * Estop.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_ESTOP_H_
#define SRC_FSM_ESTOP_H_

#include "Connecting.h"
#include "Connected.h"
#include "Estop/SafeState.h"
#include "gof/BaseState.h"
#include "gof/SubEndState.h"

class Estop: public BaseState {
public:
	Estop();
	virtual ~Estop();

	void entry() override;

	//transitions
	bool handleEstopDone() override;
	bool handleEstopSelfPressed() override;
	bool handleEstopSelfReleased() override;
	bool handleEstopExtPressed() override;
	bool handleEstopExtReleased() override;	
	bool handleResetSp() override;
	// bool handleStopLp() override;
};

#endif /* SRC_FSM_ESTOP_H_ */
