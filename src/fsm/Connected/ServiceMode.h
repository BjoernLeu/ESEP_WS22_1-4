/*
 * ServiceMode.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_SERVICEMODE_H_
#define SRC_FSM_CONNECTED_SERVICEMODE_H_

#include "Idle.h"
#include "ServiceMode/LoadConfigService.h"
#include "../gof/BaseState.h"
#include "../gof/SubEndState.h"
#include "../Estop.h"


class ServiceMode : public BaseState {
public:
	ServiceMode();
	virtual ~ServiceMode();
	
	//Transitions
	bool handleResetSp() override;	
	bool handleLoadingCompleted() override;

	void entry() override;
	void exit() override;

private:

	void blinkingOn(int color, int speed);
	void blinkingOff(int color);
};

#endif /* SRC_FSM_CONNECTED_SERVICEMODE_H_ */
