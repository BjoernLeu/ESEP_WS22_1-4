/*
 * SaveCali.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

#ifndef SRC_FSM_CONNECTED_CALIBRATION_SAVECALI_H_
#define SRC_FSM_CONNECTED_CALIBRATION_SAVECALI_H_

class SaveCali: public BaseState {
public:
	SaveCali();
	virtual ~SaveCali();

	void entry() override;
	bool handleSavingDone() override;

private:
	void saveDataInFile();
};

#endif /* SRC_FSM_CONNECTED_CALIBRATION_SAVECALI_H_ */
