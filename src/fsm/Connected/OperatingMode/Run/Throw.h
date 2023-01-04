/*
 * Throw.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_H_

#include "../../Error.h"
#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"

class Throw : public BaseState {
public:
	Throw();
	virtual ~Throw();

	//transition
	bool handleSignalReceipted();
	bool handleThrown();
	bool handleOutOfOrder();
	bool handleFlat();
	bool handleLbSwFree();
	bool handleLbSW();
	bool handleSLSelfFull();
	bool handleSlFree();
	bool handleSLExtFull();
	bool handleBothFull();
	bool handleInOrder();
	
	//methods
	void entry();
	void sendError();
	void blinkingOff(int color);
	void throwWP();
	void open();
	void checkWP();
	void checkFesto();
	void checkSlide();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_H_ */
