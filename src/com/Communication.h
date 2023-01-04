/*
 * Communication.h
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

#ifndef SRC_COM_COMMUNICATION_H_
#define SRC_COM_COMMUNICATION_H_

// custom
#include "../utils/Events.h"

// system
#include <iostream>
#include <thread>
#include <string>
#include <sys/dispatch.h>

class Communication {
public:
	// Konstruktor der Klasse Communication
	Communication();
	// Destruktor der Klasse Communication
	virtual ~Communication();
	std::thread receivingThread;
protected:
	/**
	 * Startet einen Thread mit der Methode receive.
	 */
	void startReceive(name_attach_t *attach);

	/**
	 * Schnittstelle zum Empfangen von Pulse Messages.
	 * Wirft einen Error, wenn das Senden einer Pulse Message fehlgeschlagen ist.
	 *
	 * @param *attach
	 */
	void receive(name_attach_t *attach);

	/**
	 * Sendet die Übergebene Nachricht in Form einer Pulse Message.
	 * Wirft einen Error, wenn name_open, oder das Senden der Nachricht fehlschlägt.
	 *
	 * @param coid
	 * @param msgCode
	 * @param msgValue
	 */
	static void send(int coid, int msgCode, int msgValue);

	/**
	 * Methode zum behandeln empfangener Nachrichten.
	 *
	 * @param msg empfangene Nachricht.
	 */
	virtual void handle_pulse(_pulse msg);
};

#endif /* SRC_COM_COMMUNICATION_H_ */
