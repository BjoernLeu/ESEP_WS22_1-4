/*
 * Throw.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_H_

#include "../Run.h"
#include "Throw/IdleThrow.h"
#include "../../Error.h"
#include "../../../gof/BaseState.h"
#include "../../../gof/SubEndState.h"
#include "../../../Estop.h"

class Throw : public BaseState {
public:
	Throw();
	virtual ~Throw();

	void entry() override;

	//transition
	bool handleSlSelfFull() override;
	bool handleSlBothFree() override;
	bool handleSlExtFull() override;
	bool handleSlBothFull() override;
	bool handleOutOfOrder() override;
	bool handleInOrder() override;
	bool handleLbSW() override;
	bool handleLbSwFree() override;
	bool handleFlat() override;	
	bool handleSignalReceipted() override;
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_THROW_H_ */
