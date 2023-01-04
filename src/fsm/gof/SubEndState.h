/*
 * SubEndState.h
 *
 *  @author Johannes Oehlers
 *  @author Björn Leuendorf
 */

#include "BaseState.h"

#ifndef SRC_FSM_SUBENDSTATE_H_
#define SRC_FSM_SUBENDSTATE_H_

class SubEndState: public BaseState {
public:
	bool isSubEndState() override {
		return true;
	};
};

#endif /* SRC_FSM_SUBENDSTATE_H_ */
