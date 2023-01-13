/*
 * Transfer.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_H_

#include "../../Error.h"
#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "Transfer/TransferFesto.h"

class Transfer : public BaseState {
public:
	Transfer();
	virtual ~Transfer();

	void entry() override;

	//Transitions
	bool handleLbSL() override;
	bool handleLbO() override;
	bool handleWpArrived() override;
	bool handleTransferOK() override; 
	bool handleTransferWait() override;
	bool handleLbOFree() override;
	bool handleWpTransfer() override;
	bool handleLbI() override;

};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_H_ */
