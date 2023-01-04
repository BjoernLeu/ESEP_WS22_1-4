/*
 * Metal.h
 *
 *  Created on: Dec 07, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_

#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"

class Metal : public BaseState {
public:
	Metal();
	virtual ~Metal();

	//transition
	bool handleNoMetal();
	bool handleMetalDetected();

	//methods
	void entry() override;

private:
	void setMType();

};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_ */
