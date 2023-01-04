/*
 * IdleWatch.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_IDLEWATCH_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_IDLEWATCH_H_

class IdleWatch {
public:
	IdleWatch();
	virtual ~IdleWatch();
	void entry();
	
	//transitions
	bool handleWpEarly();
	bool handleWpLate();

	//methods
	bool watchWS();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_MANAGEWP_IDLEWATCH_H_ */
