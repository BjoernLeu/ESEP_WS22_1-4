/*
 * Connected.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_H_
#define SRC_FSM_CONNECTED_H_

#include "Connecting.h"
#include "Connected/Idle.h"
#include "gof/BaseState.h"
#include "gof/SubEndState.h"
#include "Estop.h"

class Connected: public BaseState {
public:
	Connected();
	virtual ~Connected();

	void entry() override;	
	void exit() override;

	//transitions
	bool handleConLost() override;
	bool handleEstopSelfPressed() override;
	bool handleEstopExtPressed() override;

	//transitions -> calibration
	bool handleLbI() override;
	bool handleHsWP() override;
	bool handleCalcDone() override;

	//transitions -> error
	bool handleStartSp() override;
	bool handlePrinted() override;
	bool handleErrorGone() override;

	//transitions -> idle
	bool handleStartLp() override;
	bool handleResetLp() override;

	//transition -> operatingMode
	bool handleError() override;
	bool handleSignalReceipted() override;
	bool handleOutOfOrder() override;
	bool handleFlat() override;
	bool handleLbSwFree() override;
	bool handleLbSW() override;
	bool handleSlSelfFull() override;
	bool handleSlFree() override;
	bool handleSlExtFull() override;
	bool handleSlBothFull() override;
	bool handleSlBothFree() override;
	bool handleWpExpected() override;
	bool handleSlSelfFree() override;
	bool handleLbO() override;
	bool handleLbSL() override;
	bool handleHsBelt() override;
	bool handleNoMetal() override;
	bool handleEmptyBelt() override;
	bool handleInOrder() override;
	bool handleWpMetal() override;
	bool handleSlExtFree() override;
	bool handleWpArrived() override;
	bool handleTransferOK() override; 
	bool handleTransferWait() override;
	bool handleLbOFree() override;
	bool handleWpTransfer() override;
	bool handleManageDone() override;
	bool handleStopSp()override;
	
	bool handleWpCode(int height) override;
	bool handleWpDrilling(int height) override;
	bool handleWpFlat(int height) override;
	bool handleWpHigh(int height) override;

	//Transitions -> serviceMode
	bool handleResetSp() override;
	bool handleLoadingCompleted() override;

private:
	void motorOff();
	void switchOff();
};

#endif /* SRC_FSM_CONNECTED_H_ */
