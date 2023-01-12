/*
 * WaitFesto1.h
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_WAITFESTO1_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_WAITFESTO1_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "IdleTransferFesto1.h"


class WaitFesto1 : public BaseState{
public:
	WaitFesto1();
	virtual ~WaitFesto1();

	void entry() override;
	void exit() override;

	//Transitions
	bool handleTransferOK() override;

	//Methods
	void motorOff();
	void closeSwitch();
	void motorOn();
	void restoreSwitch();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_WAITFESTO1_H_ */
