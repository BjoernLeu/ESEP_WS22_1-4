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
#include "mqtt/MQTTClient.h"
#include<iostream>
#include<chrono>
#include <thread>

// just for testing, can be moved later
#define ADDRESS     "tcp://192.168.101.7:1883"
#define CLIENTID    "ClientPub"
#define TOPIC       "MQTT"
#define PAYLOAD     "Hello World!"
#define QOS         1
#define TIMEOUT     10000L
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
	int sendMQTT();

private:
};

#endif /* SRC_STM_GOF_ACTIONS_H_ */
