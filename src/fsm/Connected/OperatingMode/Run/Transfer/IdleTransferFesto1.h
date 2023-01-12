/*
 * IdleTransferFesto1.h
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_IDLETRANSFERFESTO1_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_IDLETRANSFERFESTO1_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "CheckFesto2.h"

class IdleTransferFesto1 : public BaseState{
	public:
		IdleTransferFesto1();
		virtual ~IdleTransferFesto1();

		void entry() override;

		//transitions
		bool handleLbSl() override;
		bool handleLbO() override;
		bool handleWpArrived() override;

	private:
		void checkEmptyBelt();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_IDLETRANSFERFESTO1_H_ */
