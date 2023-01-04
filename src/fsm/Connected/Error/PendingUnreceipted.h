/*
 * PendingUnreceipted.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_ERROR_PENDINGUNRECEIPTED_H_
#define SRC_FSM_CONNECTED_ERROR_PENDINGUNRECEIPTED_H_

#include "GoneReceipted.h"
#include "GoneUnreceipted.h"
#include "WPAppeared.h"
#include "WPDisappeared.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class PendingUnreceipted : public BaseState{
public:
	PendingUnreceipted();
	virtual ~PendingUnreceipted();

	//transitions
	bool handleErrorGone() override;
	bool handleResetSp() override;

	//methods
	void entry() override;
	void exit() override;

private:
	void blinkingOn(int color, int speed);
	void motorOff();
	void blinkingOff(int color);
};


#endif /* SRC_FSM_CONNECTED_ERROR_PENDINGUNRECEIPTED_H_ */