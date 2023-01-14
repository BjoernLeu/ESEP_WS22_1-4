/*
 * ArrivedOut.h
 *
 *  Created on: 21 Dec 2022
 *      Author: j-oeh
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_ARRIVEDOUT_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_ARRIVEDOUT_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "IdleWatch.h"

class ArrivedOut : public BaseState{
public:
	ArrivedOut();
	virtual ~ArrivedOut();

	void entry() override;

	//transitions
	bool handleManageDone() override;

	//methods
	void checkEarly();
	void manageList();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_ARRIVEDOUT_H_ */
