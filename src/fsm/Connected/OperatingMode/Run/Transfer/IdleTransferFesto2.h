/*
 * IdleTransferFesto2.h
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_IDLETRANSFERFESTO2_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_IDLETRANSFERFESTO2_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "WaitFesto2.h"

class IdleTransferFesto2 : public BaseState{
	public:
		IdleTransferFesto2();
		virtual ~IdleTransferFesto2();

		void entry() override;

		//transitions
		bool handleLbSl() override;
		bool handleLbO() override;
		bool handleLbOFree() override;
		bool handleWpTransfer() override;
		bool handleLbI() override;

	private:
		void emptyBelt();
		void motorOff();
		void sendWpArrived();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_IDLETRANSFERFESTO2_H_ */
