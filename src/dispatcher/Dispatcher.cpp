/*
 * Dispatcher.cpp
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

// custom
#include "Dispatcher.h"


Dispatcher::Dispatcher(const char* name, const char* name2, int festo) {

	attach = name_attach(NULL, name, 0);
	if (attach == NULL) {
		perror("name_attach failed");
		exit(EXIT_FAILURE);
	}

	attach2 = name_attach(NULL, name2, 0);
	if (attach2 == NULL) {
		perror("name_attach failed");
		exit(EXIT_FAILURE);
	}
}

void Dispatcher::startThreads(const char* nameSendCtx2, const char* nameSendCom) {
	context2Coid = name_open(nameSendCtx2, 0);
	if (context2Coid == -1) {
		perror("name_open failed");	//loglevel replace
		exit(EXIT_FAILURE);
	}

	comCoid = name_open(nameSendCom, 0);
	if (comCoid == -1) {
		perror("name_open failed");	//loglevel replace
		exit(EXIT_FAILURE);
	}

	std::thread receivingThread2(&Dispatcher::receive2, this, attach2);
	std::thread receivingThread(&Dispatcher::receive, this, attach);
	receivingThread2.detach();
	receivingThread.detach();
}

void Dispatcher::receive2(name_attach_t *attach) {
	_pulse msg;
	while (1) {
		int recvid = MsgReceivePulse(attach->chid, &msg, sizeof(_pulse),
				nullptr); // recvid < 0 Pulse failed, == 0 success
		if (recvid < 0) {
			perror("MsgReceivePulse failed!");
			exit(EXIT_FAILURE);
		}

		if (recvid == 0) {	//pulse received.
//			printf("Success");
			this->send(comCoid, msg.code, msg.value.sival_int);
		}
	}
}

void Dispatcher::subscribe(const char* name, Event event) {
	int coid = name_open(name, 0);
	if (coid == -1) {
		perror("name_open failed");
		exit(EXIT_FAILURE);
	}
	dispatch_map[event] = coid;
}

void Dispatcher::handle_pulse(_pulse msg) {
//	for(int value : dispatch_map[static_cast<Event>(msg.code)]) {
		this->send(dispatch_map[static_cast<Event>(msg.code)], msg.code, msg.value.sival_int);
//	}
}

