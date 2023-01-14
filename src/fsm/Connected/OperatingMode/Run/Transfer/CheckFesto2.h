/*
 * CheckFesto2.h
 *
 *  Created on: Jan 12, 2023
 *      Author: pki
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_CHECKFESTO2_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_CHECKFESTO2_H_

#include "../../Error.h"
//#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "IdleTransferFesto1.h"
#include "WaitFesto1.h"


class CheckFesto2 : public BaseState{
	public:
		CheckFesto2();
		virtual ~CheckFesto2();

		void entry() override;

		//Transisions
		bool handleTransferOK() override; 
		bool handleTransferWait() override;

		//Methods
		void sendWpTransfer();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_TRANSFER_CHECKFESTO2_H_ */
