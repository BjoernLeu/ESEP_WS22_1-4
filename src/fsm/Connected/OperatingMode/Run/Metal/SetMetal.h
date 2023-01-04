/*
 * SetMetal.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METAL_SETMETAL_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METAL_SETMETAL_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class SetMetal : public BaseState{
public:
	SetMetal();
	virtual ~SetMetal();

	//transitions
	bool no_Metal();

	//methods
	void entry() override;
	void setMType();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METAL_SETMETAL_H_ */
