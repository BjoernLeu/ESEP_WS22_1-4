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
#include "Run/Transfer.h"
#include "Run/MeasureHeight/IdleMeasureHeight.h"
#include "Run/Metal/IdleMetal.h"
#include "Run/Throw/IdleThrow.h"
#include "Run/Slide/IdleSlide.h"
#include "Run/CountUp.h"
#include "Run/CountDown.h"
#include "Run.h"
#include "../Error.h"

class Run : public BaseState {
public:
	Run();
	virtual ~Run();

	//transition
	bool handleSignalReceipted() override;
	bool handleThrown() override;
	bool handleOutOfOrder() override;
	bool handleFlat() override;
	bool handleLbSwFree() override;
	bool handleLbSW() override;
	bool handleSLSelfFull() override;
	bool handleSlFree() override;
	bool handleSLExtFull() override;
	bool handleBothFull() override;
	bool handleWPExpected() override;
	bool handleSLSelfFree() override;
	bool handleSLbothFree() override;
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
	bool handleInOrder() override;
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


	//methods
	void entry() override;
	bool entryHistory() override;
	void exit() override;

private: 
	void motorOff();
	void motorOn();	
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_H_ */
