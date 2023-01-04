/*
 * IdleThrow.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_IDLETHROW_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_IDLETHROW_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class IdleThrow : public BaseState{
public:
	IdleThrow();
	virtual ~IdleThrow();

	void entry() override;

	//transition
	bool handleLbSW();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_IDLETHROW_H_ */
