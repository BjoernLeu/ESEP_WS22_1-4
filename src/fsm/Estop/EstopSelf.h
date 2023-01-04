/*
 * EstopSelf.h
 *
 *  Created on: Dec 8, 2022
 *      Author: daniel
 */


#ifndef SRC_FSM_ESTOP_ESTOPSELF_H_
#define SRC_FSM_ESTOP_ESTOPSELF_H_

#include "EstopBoth.h"
#include "ExitEstop.h"
#include "../gof/BaseState.h"
#include "../gof/SubEndState.h"

class EstopSelf: public BaseState {
public:
	EstopSelf();
	virtual ~EstopSelf();

	void entry() override;
	// bool handleStopLp() override;
	bool handleEstopExtPressed() override;
	bool handleEstopSelfReleased() override;

private:
	void printEstopStates();
};

#endif /* SRC_FSM_ESTOP_ESTOPSELF_H_ */
