/*
 * Dispatcher.cpp
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

// custom
#include "Dispatcher.h"


Dispatcher::Dispatcher(const char* name, const char* name2, int festo) {
	std::cout << "d: hi" << std::endl;

	if (festo == 1) {
		attachPointHere = "festo1";
		attachPointRemote = "festo2";
		system("gns -s");
	} else if(festo == 2){
		attachPointHere = "festo2";
		attachPointRemote = "festo1";
		system("gns");
	}
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
	std::cout << "d: bye" << std::endl;
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

//	if(attachPointHere != NULL) {
//		std::thread serverThread(&Dispatcher::server, this);
//		serverThread.detach();
//		connectToServer();
//	}
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

void Dispatcher::handle_pulseOtherFesto(_pulse msg) {
	if(msg.code == HEARTBEAT) {
		heartBeat = true;
//		std::cout << "got hb" << std::endl;
	}else if(msg.code == KILL_SERVER){
		std::cout << "kill received" << std::endl;
		serverRunning = false;
	}else {
		std::cout << "Dispatcher: sending to ctx2" << std::endl;
		this->send(context2Coid, msg.code, msg.value.sival_int);
	}
}

void Dispatcher::connectToServer() {
	_pulse msg;
	bool received = false;
	receivingConnect = true;
	while (receivingConnect) {
		std::cout << "Press start when server is ready" << std::endl;
		int recvid = MsgReceivePulse(attach->chid, &msg, sizeof(_pulse),
				nullptr); // recvid < 0 Pulse failed, == 0 success
		if (recvid < 0) {
			perror("MsgReceivePulse failed!");
			exit(EXIT_FAILURE);
		}

		if (recvid == 0) {	//pulse received.
			if (msg.code == START_SP) {
				received = true;
			}
		}


		if (received) {
			serverCoid = name_open(attachPointRemote, NAME_FLAG_ATTACH_GLOBAL);
			if (serverCoid == -1) {
				std::cout << attachPointHere << std::endl;
				std::cout << attachPointRemote << std::endl;
				perror("Client: name_open failed");
				std::cout << "try again" << std::endl;
				received = false;
			}else {
				receivingConnect = false;
			}
		}
	}
	if(!hbthreadsRunning) {
		std::thread heartBeatSendT(&Dispatcher::heartBeatSend, this);
		std::thread heartBeatReceiveT(&Dispatcher::heartBeatReceive, this);
		heartBeatSendT.detach();
		heartBeatReceiveT.detach();
		hbthreadsRunning = true;
	}
}

void Dispatcher::heartBeatSend() {
	while(1) {
		sleep(1);
		if(!lost) {
			this->sendToServer(HEARTBEAT, 0);
//			std::cout << "hb" << std::endl;
		}
	}
}

//TODO just go into ESTOP
void Dispatcher::heartBeatReceive() {

	auto start = std::chrono::system_clock::now();
	std::chrono::duration<double> diff;
	do {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		if(heartBeat) {
			std::cout << "hbr" << std::endl;
			start = std::chrono::system_clock::now();
			heartBeat = false;
		}
		diff = std::chrono::system_clock::now() - start;
	} while(diff.count() < 5);

	this->send(dispatch_map[static_cast<Event>(ESTOP_SELF_PRESSED)], ESTOP_SELF_PRESSED, 0);
	lost = true;

//		std::cout << "heart beat lost" << std::endl;
//		//TODO stop everything, then try to connect again
//		lost = true;
//		while(lost) {
//			sleep(1);
//			//name_detach() or name_close()
////			name_detach(attachRemote, 0)
//			serverCoid = name_open(attachPointRemote, NAME_FLAG_ATTACH_GLOBAL);;
//			attachHere = name_attach(NULL, attachPointHere, NAME_FLAG_ATTACH_GLOBAL);
//			if (serverCoid != -1) {
//				std::cout << "name_open success" << std::endl;
//				if (MsgSendPulse(serverCoid, -1, HEARTBEAT, 0) != -1) {
//					std::cout << "reconnected" << std::endl;
//					lost = false;
//				}
//			}else {
//				std::cout << "name_open failed: " << attachPointRemote << std::endl;
//			}
//		}
//		std::cout << "left lost loop" << std::endl;
}

void Dispatcher::server() {
	attachHere = name_attach(NULL, attachPointHere, NAME_FLAG_ATTACH_GLOBAL);
	if (attachHere == NULL) {
		perror("Server: name_attach failed");
		exit(EXIT_FAILURE);
	}
	std::unique_lock<std::mutex> lk(mutex);
	serverRunning = true;
	_pulse msg;
	while (1) {
//		std::cout << "server receiving" << std::endl;
		int recvid = MsgReceive(attachHere->chid, &msg, sizeof(msg), NULL); // recvid < 0 Pulse failed, == 0 success
//		std::cout << "server received msg" << std::endl;
		if (recvid < 0) {
			perror("Server: MsgReceive failed!");
			exit(EXIT_FAILURE);
		}

		if (recvid == 0) {	//pulse received.
//			std::cout << "Server: MsgReceive success!" << std::endl;
			this->handle_pulseOtherFesto(msg);
//			std::cout << "received: " << (int) msg.code << std::endl;
//			std::cout << "received: " << msg.value.sival_int << std::endl;
		}

		if((_IO_BASE <= msg.type) && (msg.type <= _IO_MAX)) {
			if(msg.type == _IO_CONNECT) {
				std::cout << "_IO_CONNECT received" << std::endl;
				MsgReply(recvid, EOK, NULL, 0);
				std::cout << "replied" << std::endl;
			}
		}
		if(!serverRunning) {
			cvd.wait(lk);
			serverRunning = true;
		}
	}
}

void Dispatcher::sendToServer(int code, int value) {
	if (MsgSendPulse(serverCoid, -1, code, value) == -1) {
		perror("Client: MsgSendPulse failed");
//		exit(EXIT_FAILURE);
	}
//	std::cout << "send success!" << std::endl;
}
