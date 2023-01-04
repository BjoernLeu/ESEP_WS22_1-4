/*
 * Measure.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREHEIGHT_MEASURE_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREHEIGHT_MEASURE_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class Measure: public BaseState {
public:
	//transition

	//methods
	void entry() override;
	void exit() override;

private: 
	void motorSlow();
	void motorFast();
	void setHType();
	bool handleHsBelt() override;
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREHEIGHT_MEASURE_H_ */
