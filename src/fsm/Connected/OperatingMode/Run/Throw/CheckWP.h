/*
 * CheckWP.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKWP_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKWP_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class CheckWP : public BaseState{
public:
	CheckWP();
	virtual ~CheckWP();

	//transition
	bool handleOutOfOrder();
	bool handleFlat();
	bool handleInOrder();

	//methods
	void entry() override;
	void checkWP();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKWP_H_ */
