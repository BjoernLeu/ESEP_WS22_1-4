/*
 * IdleMeasureHeight.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREHEIGHT_IDLEMEASUREHEIGHT_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREHEIGHT_IDLEMEASUREHEIGHT_H_

#include "../../Error.h"
//#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "Measure.h"

class IdleMeasureHeight : public BaseState {
	public:
		IdleMeasureHeight();
		virtual ~IdleMeasureHeight();

		//transition
		bool handleHsWP() override;

		//methods
		void entry() override;
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MEASUREHEIGHT_IDLEMEASUREHEIGHT_H_ */
