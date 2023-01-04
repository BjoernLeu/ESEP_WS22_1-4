/*
 * Error.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_ERROR_H_
#define SRC_FSM_CONNECTED_ERROR_H_

#include "../gof/SubEndState.h"
#include "../gof/BaseState.h"
#include "Error/PendingUnreceipted.h"
#include "OperatingMode.h"
#include "../Estop.h"

class Error : BaseState {
public:
	Error();
	virtual ~Error();
	
	//transitions
	bool handleStartSp();
	bool handlePrinted();
	bool handleErrorGone();
	bool handleResetSp();

	//methods
	bool entryHistory() override;
	void entry() override;

}; 

#endif /* SRC_FSM_CONNECTED_ERROR_H_ */
