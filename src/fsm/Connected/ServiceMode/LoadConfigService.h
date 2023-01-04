/*
 * LoadConfigService.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_SERVICEMODE_LOADCONFIGSERVICE_H_
#define SRC_FSM_CONNECTED_SERVICEMODE_LOADCONFIGSERVICE_H_

#include "IdleService.h"
#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class LoadConfigService : public BaseState {
public:
	LoadConfigService();
	virtual ~LoadConfigService();
	void entry() override;

	//Transitions
	bool handleLoadingCompleted() override;
	
private:
	//Methods
	bool loadCfg();

};

#endif /* SRC_FSM_CONNECTED_SERVICEMODE_LOADCONFIGSERVICE_H_ */