/*
 * OperatingMode.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_H_

#include "../gof/BaseState.h"
#include "../gof/SubEndState.h"
#include "Error.h"
#include "Idle.h"
#include "OperatingMode/IdleRun.h"
#include "OperatingMode/Run.h"
#include "../Estop.h"
#include <string>

class OperatingMode : public BaseState {
public:
	OperatingMode();
	virtual ~OperatingMode();

	//transition
	bool handleStopSp();
	bool handleError();
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
	bool handleWPExpected();
	bool handleSLSelfFree();
	bool handleSLbothFree();
	bool handleWpEarly();
	bool handleWpLate();
	bool handleEarly();
	bool handleLate();
	bool handleLbO();
	bool handleLbSL();
	bool handleHsBelt();
	bool handleHsWP();
	bool handleNoMetal();
	bool handleEmptyBelt();
	bool handleInOrder();
	bool handleLbI();
	bool handleMetalDetected();

	//methods
	void entry() override;
	void exit() override;
	bool entryHistory() override;

public: 
	void lightOn(int color);
	void lightOff(int color);
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_H_ */
