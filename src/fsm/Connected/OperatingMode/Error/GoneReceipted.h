/*
 * GoneReceipted.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_ERROR_GONERECEIPTED_H_
#define SRC_FSM_CONNECTED_ERROR_GONERECEIPTED_H_

#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"

//#include "../../gof/BaseState.h"
//#include "../../gof/SubEndState.h"
//#include "../../Estop.h"

class GoneReceipted : public BaseState{
public:
	GoneReceipted();
	virtual ~GoneReceipted();

	//transitions
	bool handleStartSp() override;

	//methods
	void entry() override;
	void exit() override;

private:
	void lightOn(int color);
	void receipted();
	void sendSignalSlide();
	void motorOn();
};


#endif /* SRC_FSM_CONNECTED_ERROR_GONERECEIPTED_H_ */
