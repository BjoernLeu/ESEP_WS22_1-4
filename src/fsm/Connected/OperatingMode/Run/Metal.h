/*
 * Metal.h
 *
 *  Created on: Dec 07, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_

#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"
#include "Metal/IdleMetal.h"

class Metal : public BaseState {
public:
	Metal();
	virtual ~Metal();

	//transition
	bool handleNoMetal() override;
	bool handleMetalDetected() override;

	//methods
	void entry() override;
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_ */
