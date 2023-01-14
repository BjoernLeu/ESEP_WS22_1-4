/*
 * Measure.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREHEIGHT_MEASURE_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREHEIGHT_MEASURE_H_

#include "../../Error.h"
//#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class Measure: public BaseState {
public:
	Measure();
	virtual ~Measure();

	//methods
	void entry() override;
	void exit() override;

	bool handleHsBelt() override;
	bool handleWpHigh() override;
	bool handleWpFlat() override;
	bool handleWpDrilling() override;
	bool handleWpID() override;
private: 
	void motorSlowOn();
	void motorSlowOff();
	void setHType();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREHEIGHT_MEASURE_H_ */
