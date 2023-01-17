/*
 * CheckWP.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKWP_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKWP_H_

#include "../../Error.h"
//#include "../../../Error.h"
#include "CheckSlide.h"
#include "Pass.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

#define EXP_HEIGHT 0
#define EXP_METAL 1
#define EXP_ISDRILLING 2

class CheckWP : public BaseState{
public:
	CheckWP();
	virtual ~CheckWP();

	//transition
	bool handleOutOfOrder() override;
	bool handleInOrder() override;

	//methods
	void entry() override;
	void checkWP();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKWP_H_ */
