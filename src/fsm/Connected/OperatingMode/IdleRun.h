/*
 * IdleRun.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_IDLERUN_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_IDLERUN_H_

#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "Run.h"
//#include "../Error.h"
#include "Error.h"

class IdleRun: public BaseState {
public:
	IdleRun();
	virtual ~IdleRun();

	//transition
	bool handleLbI() override;
	bool hadleWpTransfer() override;

	void entry() override;

	void sendTransferOK();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_IDLERUN_H_ */
