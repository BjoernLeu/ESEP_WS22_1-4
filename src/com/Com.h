/*
 * Com.h
 *
 *  Created on: 12 Jan 2023
 *      Author: j-oeh
 */


#ifndef SRC_COM_COM_H_
#define SRC_COM_COM_H_

#include "../dispatcher/Dispatcher.h"

class Com {
public:
	Com(int festo, Dispatcher* disp);
	virtual ~Com();

private:
	Dispatcher* dp;
};

#endif /* SRC_COM_COM_H_ */
