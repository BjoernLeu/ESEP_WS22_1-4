/*
 * Pass.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_PASS_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_PASS_H_

#include "IdleThrow.h"
#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class Pass : public BaseState{
public:
	Pass();
	virtual ~Pass();

	//transition
	bool handleLbSwFree() override;

	//methods
	void entry() override;
	void passWP();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_PASS_H_ */
