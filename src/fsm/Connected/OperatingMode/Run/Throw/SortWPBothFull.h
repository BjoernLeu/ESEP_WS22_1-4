/*
 * SortWPBothFull.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_SORTWPBOTHFULL_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_SORTWPBOTHFULL_H_

#include "TooFull.h"
#include "Pass.h"
#include "../../Error.h"
//#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class SortWPBothFull : public BaseState{
public:
	SortWPBothFull();
	virtual ~SortWPBothFull();

	void entry() override;

	//transition
	bool handleFlat() override;
	bool handleOutOfOrder() override;

	//methods
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_SORTWPBOTHFULL_H_ */
