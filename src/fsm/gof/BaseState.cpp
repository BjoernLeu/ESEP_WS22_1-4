/*
 * BaseState.cpp
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

#include "BaseState.h"

BaseState::~BaseState() {}

void BaseState::initSubstate() {}
bool BaseState::isSubEndState() {return false;}
bool BaseState::isSubExitWithLast() {return false;}
void BaseState::entryStartNode() {}
bool BaseState::entryHistory() {return false;}
void BaseState::entryUp() {}
void BaseState::entry() {}
void BaseState::exit() {}

// handle-Methoden
bool BaseState::handleEvent(int value){return false;}
bool BaseState::handleEntry(){return false;}
bool BaseState::handleExit(){return false;}

//Height
bool BaseState::handleHeight(){return false;}
bool BaseState::handleHeightOut(){return false;}
bool BaseState::handleHighValue(){return false;}

//Festo2
bool BaseState::handleFestoExtFree(){return false;}
bool BaseState::handleFestoExtFull(){return false;}

//custom
bool BaseState::handleKaliDone(){return false;}
bool BaseState::handleSMDone(){return false;}
bool BaseState::handleSorted(){return false;}

//Werkstueck
bool BaseState::handleWpMetal(){return false;}
bool BaseState::handleWpCode0(){return false;}
bool BaseState::handleWpCodeGroesser0(){return false;}
bool BaseState::handleWpDrilling(){return false;}
bool BaseState::handleWpNoDrilling(){return false;}
bool BaseState::handleWpFlat(){return false;}
bool BaseState::handleWpHigh(){return false;}
bool BaseState::handleWpID(){return false;}
bool BaseState::handleEarly(){return false;}
bool BaseState::handleWpLate(){return false;}
bool BaseState::handleWpEarly(){return false;}
bool BaseState::handleLate(){return false;}
bool BaseState::handleManageDone(){return false;}

//Lightbarier
bool BaseState::handleLbI(){return false;}
bool BaseState::handleLbIFree(){return false;}
bool BaseState::handleLbSW(){return false;}
bool BaseState::handleLbSwFree(){return false;}
bool BaseState::handleLbSL(){return false;}
bool BaseState::handleLbSLFree(){return false;}
bool BaseState::handleLbO(){return false;}
bool BaseState::handleLbOFree(){return false;}

//Pressable	
bool BaseState::handleStartSp(){return false;}
bool BaseState::handleStartLp(){return false;}
bool BaseState::handleStartReleased(){return false;}
bool BaseState::handleStopSp(){return false;}
bool BaseState::handleStopLp(){return false;}
bool BaseState::handleStopReleased(){return false;}
bool BaseState::handleResetSp(){return false;}
bool BaseState::handleResetLp(){return false;}
bool BaseState::handleResetReleased(){return false;}

//Estop
bool BaseState::handleEstopSelfPressed(){return false;}
bool BaseState::handleEstopSelfReleased(){return false;}
bool BaseState::handleEstopExtPressed(){return false;}
bool BaseState::handleEstopExtReleased(){return false;}
bool BaseState::handleEstopDone(){return false;}
bool BaseState::handleWpComes(){return false;}

//Slide
bool BaseState::handleSLSelfFree(){return false;}
bool BaseState::handleSlSelfFull(){return false;}
bool BaseState::handleSLExtFree(){return false;}
bool BaseState::handleSlExtFull(){return false;}
bool BaseState::handleSlFree(){return false;}
bool BaseState::handleSlBothFree(){return false;}

//WP
bool BaseState::handleWpCode(int height){return false;}
bool BaseState::handleWpDrilling(int height){return false;}
bool BaseState::handleWpFlat(int height){return false;}
bool BaseState::handleWpHigh(int height){return false;}

//Custom new
bool BaseState::handleHsBelt(){return false;}
bool BaseState::handleDone(){return false;}
bool BaseState::handleWPExpected(){return false;}
bool BaseState::handleNoMetal(){return false;}
bool BaseState::handleMetalDetected(){return false;}
bool BaseState::handleHsWP(){return false;}
bool BaseState::handleOutOfOrder(){return false;}
bool BaseState::handleFlat(){return false;}
bool BaseState::handleSignalReceipted(){return false;}
bool BaseState::handleThrown(){return false;}
bool BaseState::handleInOrder(){return false;}
bool BaseState::handleSlBothFull(){return false;}
bool BaseState::handleEmptyBelt(){return false;}
bool BaseState::handlePrinted(){return false;}
bool BaseState::handleErrorGone(){return false;}
bool BaseState::handleLoadingCompleted(){return false;}
bool BaseState::handleCalcDone(){return false;}
bool BaseState::handleError(){return false;}
bool BaseState::handleConEstablished(){return false;}
bool BaseState::handleConLost(){return false;}
bool BaseState::handleSavingDone(){return false;}
bool BaseState::handleWpArrived(){return false;}
bool BaseState::handleTransferOK(){return false;} 
bool BaseState::handleTransferWait(){return false;}
bool BaseState::handleWpTransfer(){return false;}
