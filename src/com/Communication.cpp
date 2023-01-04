/**
 * Communication.cpp
 *
 * @author Johannes Oehlers
 * @author Björn Leuendorf
 */

// custom
#include "Communication.h"

Communication::Communication() {
}
Communication::~Communication() {
}

void Communication::startReceive(name_attach_t *attach) {
	std::thread receivingThread(&Communication::receive, this, attach);
	receivingThread.detach();
}

void Communication::receive(name_attach_t *attach) {
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
			this->handle_pulse(msg);
		}
	}
}

void Communication::send(int coid, int msgCode, int msgValue) {
	if (MsgSendPulse(coid, -1, msgCode, msgValue) == -1) {
		perror("MsgSendPulse failed");
		exit(EXIT_FAILURE);
	}
}

void Communication::handle_pulse(_pulse msg) {
}
