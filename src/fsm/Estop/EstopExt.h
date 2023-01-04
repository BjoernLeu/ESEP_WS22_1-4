/*
 * EstopExt.h
 *
 *  Created on: Dec 8, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_ESTOP_ESTOPEXT_H_
#define SRC_FSM_ESTOP_ESTOPEXT_H_

#include "EstopBoth.h"
#include "ExitEstop.h"
#include "../gof/BaseState.h"
#include "../gof/SubEndState.h"

class EstopExt: public BaseState {
public:
	EstopExt();
	virtual ~EstopExt();

	void entry() override;
	bool handleEstopExtReleased() override;
	bool handleEstopSelfPressed() override;
	bool handleConLost() override;

private:
	void printEstopStates();
};

#endif /* SRC_FSM_ESTOP_ESTOPEXT_H_ */
