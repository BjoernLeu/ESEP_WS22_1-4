/*
 * IdleError.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_ERROR_IDLEERROR_H_
#define SRC_FSM_CONNECTED_ERROR_IDLEERROR_H_

#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"
#include "PendingUnreceipted.h"

//#include "../../gof/BaseState.h"
//#include "../../gof/SubEndState.h"
//#include "../../Estop.h"

class IdleError : public BaseState{
public:
	IdleError();
	virtual ~IdleError();

	//transitions
	bool handleError() override;

	//methods
	void entry() override;

};


#endif /* SRC_FSM_CONNECTED_ERROR_IDLEERROR_H_ */
