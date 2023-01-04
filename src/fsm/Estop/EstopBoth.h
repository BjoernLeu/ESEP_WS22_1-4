/*
 * EstopBoth.h
 *
 *  Created on: Dec 8, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_ESTOP_ESTOPBOTH_H_
#define SRC_FSM_ESTOP_ESTOPBOTH_H_

#include "EstopSelf.h"
#include "EstopExt.h"
#include "ExitEstop.h"
#include "../gof/BaseState.h"
#include "../gof/SubEndState.h"

class EstopBoth: public BaseState {
public:
	EstopBoth();
	virtual ~EstopBoth();

	void entry() override;
	// bool handleStopLp() override;
	bool handleEstopSelfReleased() override;
	bool handleEstopExtReleased() override;
};

#endif /* SRC_FSM_ESTOP_ESTOPBOTH_H_ */
