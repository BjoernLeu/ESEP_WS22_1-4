/*
 * CountDown.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_

#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"

class CountDown : public BaseState {
public:
	CountDown();
	virtual ~CountDown();

	//transition
	bool handleLbO();
	bool handleLbSL();

	//methods
	void entry() override;
	void exit() override;

private:
	void lowerCurrentCount();
	void checkCount();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_ */
