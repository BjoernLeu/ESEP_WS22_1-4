/*
 * IdleService.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_SERVICEMODE_IDLESERVICE_H_
#define SRC_FSM_CONNECTED_SERVICEMODE_IDLESERVICE_H_

#include "LoadConfigService.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class IdleService : public BaseState {
public:
	IdleService();
	virtual ~IdleService();

	//Transitions
	bool handleResetSp() override;

	void entry() override;
};

#endif /* SRC_FSM_CONNECTED_SERVICEMODE_IDLESERVICE_H_ */