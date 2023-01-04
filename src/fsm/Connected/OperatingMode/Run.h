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
	bool handleMetalDetected();
	bool handleLbI();	

	//methods
	void entry() override;
	bool entryHistory() override;
	void exit() override;

private: 
	void motorOff();
	void motorOn();	
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_H_ */
