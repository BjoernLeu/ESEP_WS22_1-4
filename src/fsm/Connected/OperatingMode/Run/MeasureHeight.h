/*
 * MeasureHeight.h
 *
 *  Created on: Dec 07, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_

#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"
#include "MeasureHeight/IdleMeasureHeight.h"

class MeasureHeight : public BaseState {
public:
	MeasureHeight();
	virtual ~MeasureHeight();

	//transition
	bool handleHsBelt() override;
	bool handleHsWP() override;
	bool handleWpHigh() override;
	bool handleWpFlat() override;
	bool handleWpDrilling() override;
	bool handleWpID() override;

	//methods
	void entry();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_ */
