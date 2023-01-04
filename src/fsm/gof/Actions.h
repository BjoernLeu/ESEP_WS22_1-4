/*
 * Actions.h
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

#ifndef SRC_STM_GOF_ACTIONS_H_
#define SRC_STM_GOF_ACTIONS_H_

// custom
#include "ContextData.h"
#include "../../hal/Hal.h"
#include "../../utils/Events.h"
#include<iostream>
#include<chrono>
#include <thread>

/*
 * (vgl. GOF Pattern)
 * Beinhaltet mögliche Transitionen.
 */
class Actions {
public:
	Actions(); // Konstruktor
	virtual ~Actions(); // Destruktor


	void lightOn(int light);
	void lightOff(int light);
	void blinkingOn(int light, int speed);
	void blinking(int light, int speed);
	void blinkingOn(int light, int speed, int seconds);
	void timeBlinking(int light, int speed, int seconds);
	void blinkingOff(int light);

private:
};

#endif /* SRC_STM_GOF_ACTIONS_H_ */
