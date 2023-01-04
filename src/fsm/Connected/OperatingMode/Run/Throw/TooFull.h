/*
 * TooFull.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_TOOFULL_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_TOOFULL_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class TooFull : public BaseState{
public:
	TooFull();
	virtual ~TooFull();

	//transition
	bool handleSignalReceipted();

	//methods
	void entry() override;
	void sendError();
	void blinkingOff(int color);
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_TOOFULL_H_ */
