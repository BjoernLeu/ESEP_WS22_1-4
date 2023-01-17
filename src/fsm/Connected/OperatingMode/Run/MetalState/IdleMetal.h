/*
 * IdleMetal.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METAL_IDLEMETAL_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METAL_IDLEMETAL_H_

#include "../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "SetMetal.h"

class IdleMetal : public BaseState{
public:
	IdleMetal();
	virtual ~IdleMetal();

	void entry() override;

	//transitions
	bool handleWpMetal() override;
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METAL_IDLEMETAL_H_ */
