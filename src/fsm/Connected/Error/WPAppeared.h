/*
 * WPAppeared.h
 *
 *  Created on: Dec 3, 2022
 *      Author: daniel
 */

#ifndef SRC_FSM_CONNECTED_ERROR_WPAPPEARED_H_
#define SRC_FSM_CONNECTED_ERROR_WPAPPEARED_H_

#include "../../gof/BaseState.h"
#include "../../gof/SubEndState.h"
#include "../../Estop.h"

class WPAppeared : public BaseState{
public:
public:
	WPAppeared();
	virtual ~WPAppeared();

	//transitions
	bool handleStartSp() override;

	//methods
	void entry() override;
	void exit() override;

private:
	void addToList();
	void addWatcher(bool current_lb);
	void motorOn();
};

#endif /* SRC_FSM_CONNECTED_ERROR_WPAPPEARED_H_ */