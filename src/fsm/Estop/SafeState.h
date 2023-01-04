/*
 * SafeState.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_ESTOP_SAFESTATE_H_
#define SRC_FSM_ESTOP_SAFESTATE_H_

#include "EstopSelf.h"
#include "EstopExt.h"
#include "../gof/BaseState.h"
#include "../gof/SubEndState.h"

class SafeState: public BaseState {
public:
	SafeState();
	virtual ~SafeState();

	void entry() override;
	bool handleEstopSelfPressed() override;
	bool handleEstopExtPressed() override;
};

#endif /* SRC_FSM_ESTOP_SAFESTATE_H_ */
