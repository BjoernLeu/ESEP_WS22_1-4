/*
 * SortWPFree.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_SORTWPFREE_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_SORTWPFREE_H_

#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"

class SortWPFree : public BaseState{
public:
	SortWPFree();
	virtual ~SortWPFree();

	void entry() override;

	//transition
	bool handleOutOfOrder();
	bool handleFlat();

	//methods
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_SORTWPFREE_H_ */
