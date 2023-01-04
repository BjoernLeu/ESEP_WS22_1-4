/*
 * ManageWP.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_H_

#include "../../../gof/BaseState.h"

class ManageWP: public BaseState {
public:
	ManageWP();
	virtual ~ManageWP();

	//transitions
	bool handleWpEarly();
	bool handleWpLate();
	bool handleEarly();
	bool handleLate();
	bool handleLbI();

	//methods
	bool watchWS();
	void sendErrorEarly();
	void sendErrorLate(); 
	void entry();
	void increaseCurrentCount();

	//thread
	void watchWPLate();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_H_ */
