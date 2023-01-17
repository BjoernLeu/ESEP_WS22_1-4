/*
 * Com.h
 *
 *  Created on: 12 Jan 2023
 *      Author: j-oeh
 */


#ifndef SRC_COM_COM_H_
#define SRC_COM_COM_H_

#include "Communication.h"
#include "../dispatcher/Dispatcher.h"

class Com: public Communication {
public:
	Com(const char* name, int festo, Dispatcher* disp);
	virtual ~Com();

	void handle_pulse(_pulse msg);
	void connectToServer();
	void handle_pulseOtherFesto(_pulse msg);
	void heartBeatReceive();
	void heartBeatSend();
	void server();
	void sendToServer(int code, int value);

private:
	Dispatcher* dp;
	const char* attachPointHere = NULL;
	const char* attachPointRemote = NULL;

	name_attach_t *attach = 0;
	name_attach_t *attach2 = 0;
	name_attach_t *attachHere = 0;
	name_attach_t *attachRemote = 0;

	int serverCoid = 0;


	bool receivingConnect = true;
	bool lost = true;
	bool heartBeat = false;
	bool hbthreadsRunning = false;
	bool serverRunning = false;
};

#endif /* SRC_COM_COM_H_ */
