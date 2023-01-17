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
	virtual bool handleWpCode0();
	virtual bool handleWpCodeGroesser0();
	virtual bool handleWpNoDrilling();
	virtual bool handleManageDone();

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
	virtual bool handleWpComes();

//Slide
	virtual bool handleSlSelfFree();
	virtual bool handleSlSelfFull();
	virtual bool handleSlExtFree();
	virtual bool handleSlExtFull();
	virtual bool handleSlFree();

//WP
	virtual bool handleWpCode(int height);
	virtual bool handleWpDrilling(int height);
	virtual bool handleWpFlat(int height);
	virtual bool handleWpHigh(int height);

//custom new
	virtual bool handleHsBelt();
	virtual bool handleDone();
	virtual bool handleWpExpected();
	virtual bool handleNoMetal();
	virtual bool handleHsWP();
	virtual bool handleOutOfOrder();
	virtual bool handleFlat();
	virtual bool handleSignalReceipted();
	virtual bool handleInOrder();
	virtual bool handleSlBothFull();
	virtual bool handleSlBothFree();
	virtual bool handleEmptyBelt();
	virtual bool handlePrinted();
	virtual bool handleErrorGone();
	virtual bool handleLoadingCompleted();
	virtual bool handleCalcDone();
	virtual bool handleError();
	virtual bool handleConEstablished();
	virtual bool handleConLost();
	virtual bool handleSavingDone();
	virtual bool handleWpArrived();
	virtual bool handleTransferOK();
	virtual bool handleTransferWait();
	virtual bool handleWpTransfer();
	
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
