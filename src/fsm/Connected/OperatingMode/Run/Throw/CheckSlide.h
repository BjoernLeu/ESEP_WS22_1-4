/*
 * CeckSlide.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKSLIDE_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKSLIDE_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class CheckSlide : public BaseState{
public:
	CheckSlide();
	virtual ~CheckSlide();

	//transition
	bool handleSLSelfFull();
	bool handleSlFree();
	bool handleSLExtFull();
	bool handleBothFull();

	//methods
	void entry() override;
	void checkFesto();
	void checkSlide();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_CHECKSLIDE_H_ */
