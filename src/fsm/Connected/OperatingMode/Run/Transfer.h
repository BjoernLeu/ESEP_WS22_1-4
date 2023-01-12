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
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_H_ */
