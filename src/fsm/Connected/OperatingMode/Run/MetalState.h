/*
 * MetalState.h
 *
 *  Created on: Dec 07, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METALSTATE_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METALSTATE_H_

#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"
#include "MetalState/IdleMetal.h"

class MetalState : public BaseState {
public:
	MetalState();
	virtual ~MetalState();

	//transition
	bool handleNoMetal() override;
	bool handleWpMetal() override;

	//methods
	void entry() override;
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METALSTATE_H_ */
