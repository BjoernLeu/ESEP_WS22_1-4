/*
 * ManageWP.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_H_

#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"

class ManageWP: public BaseState {
public:
	ManageWP();
	virtual ~ManageWP();

	void entry() override;
	//transitions
	bool handleLbI() override;
	bool handleManageDone() override;
	bool handleHsWP() override;
	bool handleLbSW() override;
	bool handleLbO() override;

	//methods
	void addWP();

	//thread
	void watchWPLate();
	void startWatchLateThread();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_H_ */
