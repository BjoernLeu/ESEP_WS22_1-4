/*
 * ExitEstop.h
 *
 *  Created on: Dec 8, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_ESTOP_EXITESTOP_H_
#define SRC_FSM_ESTOP_EXITESTOP_H_

#include "EstopSelf.h"
#include "EstopExt.h"
#include "../gof/BaseState.h"
#include "../gof/SubEndState.h"

class ExitEstop: public BaseState {
public:
	ExitEstop();
	virtual ~ExitEstop();

	void entry() override;
	bool handleEstopExtPressed() override;
	bool handleEstopSelfPressed() override;
	bool handleResetSp() override;
};

#endif /* SRC_FSM_ESTOP_EXITESTOP_H_ */
