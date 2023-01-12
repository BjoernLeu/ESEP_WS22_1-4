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
	bool handleStopSp()override;
	bool handleError()override;
	bool handleSignalReceipted()override;
	bool handleThrown()override;
	bool handleOutOfOrder()override;
	bool handleFlat()override;
	bool handleLbSwFree()override;
	bool handleLbSW()override;
	bool handleSLSelfFull()override;
	bool handleSlFree()override;
	bool handleSLExtFull()override;
	bool handleBothFull()override;
	bool handleWPExpected()override;
	bool handleSLSelfFree()override;
	bool handleSLbothFree()override;
	bool handleWpEarly()override;
	bool handleWpLate()override;
	bool handleEarly()override;
	bool handleLate()override;
	bool handleLbO()override;
	bool handleLbSL()override;
	bool handleHsBelt()override;
	bool handleHsWP()override;
	bool handleNoMetal()override;
	bool handleEmptyBelt()override;
	bool handleInOrder()override;
	bool handleLbI()override;
	bool handleMetalDetected()override;
	bool handleWpHigh() override;
	bool handleWpFlat() override;
	bool handleWpDrilling() override;
	bool handleWpID() override;

	//methods
	void entry() override;
	void exit() override;
	bool entryHistory() override;

public: 
	void lightOn(int color);
	void lightOff(int color);
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_H_ */
