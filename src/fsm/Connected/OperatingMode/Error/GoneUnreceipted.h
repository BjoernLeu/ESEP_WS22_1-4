/*
 * GoneUnreceipted.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_ERROR_GONEUNRECEIPTED_H_
#define SRC_FSM_CONNECTED_ERROR_GONEUNRECEIPTED_H_

#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"
#include "IdleError.h"

//#include "../../gof/BaseState.h"
//#include "../../gof/SubEndState.h"
//#include "../../Estop.h"

class GoneUnreceipted : public BaseState{
public:
	GoneUnreceipted();
	virtual ~GoneUnreceipted();

	//transition
	bool handlePrinted() override;

	//methods
	void entry() override;
	void exit() override;

private:
	void printError();
	void motorOn();
};


#endif /* SRC_FSM_CONNECTED_ERROR_GONEUNRECEIPTED_H_ */
