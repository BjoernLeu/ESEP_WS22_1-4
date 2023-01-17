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
	bool handleHsWP() override;
	bool handleHsBelt() override;
	bool handleWpCode(int height) override;
	bool handleWpDrilling(int height) override;
	bool handleWpFlat(int height) override;
	bool handleWpHigh(int height) override;

	//methods
	void entry() override;
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_COUNTDOWN_H_ */
