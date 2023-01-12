/*
 * BaseState.h
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */


#ifndef SRC_FSM_GOF_BASESTATE_H_
#define SRC_FSM_GOF_BASESTATE_H_

#include <iostream>
#include <thread>
#include <sys/dispatch.h>

// custom
#include "ContextData.h"
#include "Actions.h"
#include "../../utils/Events.h"


/* Defines */
//LED's 
#define GREEN 		1
#define YELLOW 		2
#define RED 		3
#define Q1			4
#define Q2			5
#define START_LED	6
#define RESET_LED	7
#define ALL 		8

// Belt speed
#define SLOW		1000000
#define FAST		500000



/*
 * (vgl. GOF Pattern)
 * Vererbende Klasse für alle States.
 * Beinhaltet auch handle Funktionen anderer States.
 */
class BaseState {

public:
	virtual ~BaseState(); // Destruktor für die Klasse BaseState
	void setData(ContextData *data) {
		this->data = data;
	}

	void setAction(Actions *action) {
		this->action = action;
	}
	virtual void initSubstate();
	virtual bool isSubEndState();
	virtual bool isSubExitWithLast();
	virtual void entryStartNode();
	virtual bool entryHistory();
	virtual void entryUp();
	virtual void entry();
	virtual void exit();

// handle-Methoden
	virtual bool handleEvent(int value);
	virtual bool handleEntry();
	virtual bool handleExit();

//Height
	virtual bool handleHeight();
	virtual bool handleHeightOut();
	virtual bool handleHighValue();

//Festo2
	virtual bool handleFestoExtFree();
	virtual bool handleFestoExtFull();

//Weiche


//custom
	virtual bool handleKaliDone();
	virtual bool handleSMDone();
	virtual bool handleSorted();

//Werkstueck
	virtual bool handleWpMetal();
	virtual bool handleWsCode0();
	virtual bool handleWsCodeGroesser0();
	virtual bool handleWpDrilling();
	virtual bool handleWsNoDrilling();
	virtual bool handleWpFlat();
	virtual bool handleWpHigh();
	virtual bool handleWpID();
	virtual bool handleEarly();
	virtual bool handleWpEarly();
	virtual bool handleLate();
	virtual bool handleWpLate();

//Lightbarier
	virtual bool handleLbI();
	virtual bool handleLbIFree();
	virtual bool handleLbSW();
	virtual bool handleLbSwFree();
	virtual bool handleLbSL();
	virtual bool handleLbSLFree();
	virtual bool handleLbO();
	virtual bool handleLbOFree();

//Pressable	
	virtual bool handleStartSp();
	virtual bool handleStartLp();
	virtual bool handleStartReleased();
	virtual bool handleStopSp();
	virtual bool handleStopLp();
	virtual bool handleStopReleased();
	virtual bool handleResetSp();
	virtual bool handleResetLp();
	virtual bool handleResetReleased();

//Estop
	virtual bool handleEstopSelfPressed();
	virtual bool handleEstopSelfReleased();
	virtual bool handleEstopExtPressed();
	virtual bool handleEstopExtReleased();
	virtual bool handleEstopDone();
	virtual bool handleWsComes();

//Slide
	virtual bool handleSLSelfFree();
	virtual bool handleSLSelfFull();
	virtual bool handleSLExtFree();
	virtual bool handleSLExtFull();
	virtual bool handleSlFree();
	virtual bool handleSLbothFree();

//custom new
	virtual bool handleHsBelt();
	virtual bool handleDone();
	virtual bool handleWPExpected();
	virtual bool handleNoMetal();
	virtual bool handleMetalDetected();
	virtual bool handleHsWP();
	virtual bool handleOutOfOrder();
	virtual bool handleFlat();
	virtual bool handleSignalReceipted();
	virtual bool handleThrown();
	virtual bool handleInOrder();
	virtual bool handleBothFull();
	virtual bool handleEmptyBelt();
	virtual bool handlePrinted();
	virtual bool handleErrorGone();
	virtual bool handleLoadingCompleted();
	virtual bool handleCalcDone();
	virtual bool handleError();
	virtual bool handleConEstablished();
	virtual bool handleConLost();
	virtual bool handleSavingDone();
	
	static int coid;
	static int coidExt;

protected:
	ContextData *data;
	Actions *action;
	BaseState *substate;
	BaseState *multiSubstateManage;
	BaseState *multiSubstateHeight;
	BaseState *multiSubstateMetal;
	BaseState *multiSubstateThrow;
	BaseState *multiSubstateSlide;
	BaseState *multiSubstateTransfer;
};

#endif /* SRC_STM_GOF_BASESTATE_H_ */
