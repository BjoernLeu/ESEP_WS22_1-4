/*
 * IdleWatch.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_IDLEWATCH_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_IDLEWATCH_H_

// #include "../../../Error.h"
#include "../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "ArrivedSwitch.h"
#include "ArrivedOut.h"
#include "ArrivedHeight.h"

class IdleWatch : public BaseState{
public:
	IdleWatch();
	virtual ~IdleWatch();

	void entry();

	// transitions
	bool handleHsWP() override;
	bool handleLbSW() override;
	bool handleLbO() override;
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_IDLEWATCH_H_ */
