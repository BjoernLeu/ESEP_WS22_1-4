/*
 * CeckSlide.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKSLIDE_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKSLIDE_H_

#include "SortWPBothFull.h"
#include "TooFull.h"
#include "ThrowWP.h"
#include "SortWPFree.h"
#include "Pass.h"
#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class CheckSlide : public BaseState{
public:
	CheckSlide();
	virtual ~CheckSlide();

	//transition
	bool handleSlSelfFull() override;
	bool handleSlBothFree() override;
	bool handleSlExtFull() override;
	bool handleSlBothFull() override;

	//methods
	void entry() override;
	int checkFesto();
	int checkSlide();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKSLIDE_H_ */
