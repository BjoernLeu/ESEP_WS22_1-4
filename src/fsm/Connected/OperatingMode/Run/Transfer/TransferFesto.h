/*
 * TransferFesto.h
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_TRANSFERFESTO_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_TRANSFERFESTO_H_

#include "../../Error.h"
//#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

#include "IdleTransferFesto1.h"
#include "IdleTransferFesto2.h"

#define FESTOONE 1
#define FESTOTWO 2

class TransferFesto : public BaseState {
public:
	TransferFesto();
	virtual ~TransferFesto();

	void entry() override;
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_TRANSFERFESTO_H_ */
