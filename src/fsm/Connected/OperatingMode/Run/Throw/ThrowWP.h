/*
 * Throw.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_TROWWP_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_TROWWP_H_

#include "IdleThrow.h"
#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class ThrowWP : public BaseState{
public:
	ThrowWP();
	virtual ~ThrowWP();

	//transition
	bool handleLbSwFree() override;

	//method
	void entry() override;
	void exit() override;
	bool throwWP();
	void throwWPOff();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_TROWWP_H_ */
