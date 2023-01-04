/*
 * Connecting.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTING_H_
#define SRC_FSM_CONNECTING_H_

#include "Connected.h"
#include "gof/BaseState.h"
#include "gof/SubEndState.h"
#include "Estop.h"

class Connecting: public BaseState {
public:
	Connecting();
	virtual ~Connecting();

	//methods
	void entry() override;
	void exit() override;
	
	//transitions
	bool handleConEstablished() override;
	bool handleEstopSelfPressed() override;

private:
	void establishConnection();
};

#endif /* SRC_FSM_CONNECTING_H_ */
