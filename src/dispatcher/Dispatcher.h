/*
 * Dispatcher.h
 * TODO: Kommunikation mit anderem Fließband.
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

#ifndef SRC_DISPATCHER_DISPATCHER_H_
#define SRC_DISPATCHER_DISPATCHER_H_

// custom
#include "../com/Communication.h"
//#include "../eventhandler/EventHandler.h"
#include "../hal/HalControl.h"
#include "../utils/Events.h"

// system
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <map>
#include <mutex>
#include <thread>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sys/dispatch.h>

/*
 * Verteilt eintreffende Events.
 */
class Dispatcher: public Communication {
public:
	/**
	 * TODO: Kommunikation zum anderen Dispatcher
	 *
	 * Konstruktor der Klasse Dispatcher.
	 * Registriert einen Namen im Pfadbereich und erstellt einen Kanal.
	 * Wirft einen Error, wenn name_attach fehlschlägt.
	 */
	Dispatcher(const char* name, const char* name2, int festo);
	virtual ~Dispatcher() {
	}
	; // Destruktor der Klasse Dispatcher

	/**
	 * Erstellt jeweils einen unabhängigen Thread für die Methoden dispatch und receive.
	 */
	void startThreads(const char* nameSendCtx2);

	/**
	 * Stellt die Verbindung zum Server, der den Namen registriert hat, her.
	 * Anschließend wird die bestehende Verbindung in eine Map hinzugefügt.
	 * Wirft einen Error, wenn name_open fehlschlägt.
	 */
	void subscribe(const char* name, Event event);

	/**
	 * Dispatcht die Nachrichten in der Queue an die zugehörigen Empfänger.
	 */
//	void dispatch();
	void sendToServer(int code, int value);

	/**
	 * Stellt eine Verbindung zur anderen Festo her. Hierzu muss der Nutzer den Start-Button betätigen, sobald auf der anderen Festo-Anlage der Server läuft.
	 */
	void connectToServer();

	std::thread dispatcherThread;
	std::thread receivingThread;
private:
	struct my_msg {
		short type;
		struct sigevent event;
	};
	/**
	 * Fügt eintreffende Events ans Ende der Queue ein.
	 * Das Event ISR_ESTOP wird beim Eintreffen direkt an den Anfang der Queue hinzugefügt.
	 */
	void handle_pulse(_pulse msg);
	void handle_pulseOtherFesto(_pulse msg);
	void receive2(name_attach_t *attach);

	void server();

	void heartBeatSend();
	void heartBeatReceive();

	bool receivingConnect = true;
	bool lost = false;
	bool heartBeat = false;
	bool hbthreadsRunning = false;
	bool serverRunning = false;

	std::mutex mutex;
	std::condition_variable cvd;

	std::map<Event, int> dispatch_map;

	const char* attachPointHere = NULL;
	const char* attachPointRemote = NULL;

	int serverCoid = 0;
	int context2Coid = 0;

	name_attach_t *attach = 0;
	name_attach_t *attach2 = 0;
	name_attach_t *attachHere = 0;
	name_attach_t *attachRemote = 0;
};

#endif /* SRC_DISPATCHER_DISPATCHER_H_ */
