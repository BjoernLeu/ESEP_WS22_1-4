/*
 * SetMetal.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METAL_SETMETAL_H_
#define SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METAL_SETMETAL_H_

#include "../../Error.h"
//#include "../../../Error.h"
#include "../../../../gof/BaseState.h"
#include "../../../../gof/SubEndState.h"
#include "IdleMetal.h"

class SetMetal : public BaseState{
public:
	SetMetal();
	virtual ~SetMetal();

	void entry() override;

	//transitions
	bool handleNoMetal() override;

private:
	void setMType();
};

#endif /* SRC_FSM_CONNECTED_OPERATINGMODE_RUN_METAL_SETMETAL_H_ */
