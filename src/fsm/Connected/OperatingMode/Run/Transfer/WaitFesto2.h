/*
 * WaitFesto2.h
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_WAITFESTO2_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_WAITFESTO2_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class WaitFesto2 : public BaseState{
public:
	WaitFesto2();
	virtual ~WaitFesto2();

	void entry() override;

	//Transisions
	bool handleLbOFree() override;
	bool handleLbSl() override;
	bool handleLbO() override;

	//Methods
	void sendTransferWait();
	void sendTransferOK();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_WAITFESTO2_H_ */
