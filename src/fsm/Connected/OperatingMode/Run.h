/*
 * Run.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_H_

#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "Run/ManageWP.h"
#include "IdleRun.h"
#include "Run/Transfer.h"
#include "Run/MeasureHeight.h"
#include "Run/MetalState.h"
#include "Run/Throw.h"
#include "Run/Slide.h"
//#include "../Error.h"
#include "Error.h"

class Run : public BaseState {
public:
	Run();
	virtual ~Run();

	//transition
	bool handleSignalReceipted() override;
	bool handleThrown() override;
	bool handleSlSelfFull() override;
	bool handleSlBothFree() override;
	bool handleSlExtFull() override;
	bool handleSlBothFull() override;
	bool handleOutOfOrder() override;
	bool handleInOrder() override;
	bool handleLbSW() override;
	bool handleLbSwFree() override;
	bool handleFlat() override;	
	bool handleWpExpected() override;
	bool handleSlSelfFree() override;
	bool handleWpEarly() override;
	bool handleWpLate() override;
	bool handleEarly() override;
	bool handleLate() override;
	bool handleLbO() override;
	bool handleLbSL() override;
	bool handleHsBelt() override;
	bool handleHsWP() override;
	bool handleNoMetal() override;
	bool handleEmptyBelt() override;
	bool handleMetalDetected() override;
	bool handleLbI() override;	
	bool handleWpHigh() override;
	bool handleWpFlat() override;
	bool handleWpDrilling() override;
	bool handleWpID() override;
	bool handleWpArrived() override;
	bool handleTransferOK() override; 
	bool handleTransferWait() override;
	bool handleLbOFree() override;
	bool handleWpTransfer() override;
	bool handleError()override;
	bool handleManageDone() override;
	bool handleWpCode(int height) override;
	bool handleWpDrilling(int height) override;
	bool handleWpFlat(int height) override;
	bool handleWpHigh(int height) override;
	bool handleSlExtFree() override;


	//methods
	void entry() override;
	bool entryHistory() override;
	void exit() override;

private: 
	void motorOff();
	void motorOn();	
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_H_ */
