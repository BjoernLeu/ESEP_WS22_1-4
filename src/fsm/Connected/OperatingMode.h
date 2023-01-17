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
#include "Idle.h"
//#include "Error.h"
#include "OperatingMode/IdleRun.h"
#include "../Estop.h"
#include <string>

class OperatingMode : public BaseState {
public:
	OperatingMode();
	virtual ~OperatingMode();

	//transition
	bool handleStopSp()override;

	bool handleSignalReceipted()override;
	bool handleOutOfOrder()override;
	bool handleFlat()override;
	bool handleLbSwFree()override;
	bool handleLbSW()override;
	bool handleSlSelfFull()override;
	bool handleSlFree()override;
	bool handleSlExtFull()override;
	bool handleSlBothFree() override;
	bool handleSlBothFull()override;
	bool handleWpExpected()override;
	bool handleSlSelfFree()override;
	bool handleLbO()override;
	bool handleLbSL()override;
	bool handleHsBelt()override;
	bool handleHsWP()override;
	bool handleNoMetal()override;
	bool handleEmptyBelt()override;
	bool handleInOrder()override;
	bool handleLbI()override;
	bool handleMetalDetected()override;
	bool handleWpArrived() override;
	bool handleTransferOK() override; 
	bool handleTransferWait() override;
	bool handleLbOFree() override;
	bool handleWpTransfer() override;
	//bool handleError()override;
	bool handleManageDone() override;
	bool handleWpCode(int height) override;
	bool handleWpDrilling(int height) override;
	bool handleWpFlat(int height) override;
	bool handleWpHigh(int height) override;
	bool handleSlExtFree() override;

	//methods
	void entry() override;
	void exit() override;
	//bool entryHistory() override;

};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_H_ */
