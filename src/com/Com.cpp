/*
 * Com.cpp
 *
 *  Created on: 12 Jan 2023
 *      Author: j-oeh
 */

#include "Com.h"

Com::Com(const char* name, int festo, Dispatcher* disp) {
	dp = disp;
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


	std::thread receivingThread(&Com::receive, this, attach);
	receivingThread.detach();
}

void Com::handle_pulse(_pulse msg) {
	if(msg.code == CONNECT) {
		std::cout << "Com CONNECT" << std::endl;
		if(lost) {
			std::thread serverThread(&Com::server, this);
			serverThread.detach();
			connectToServer();
		}
	}else if(msg.code == KILL_SERVER) {
		lost = true;
	}else {
		this->sendToServer(msg.code, msg.value.sival_int);
	}
//	std::cout << "send success!" << std::endl;
}

void Com::connectToServer() {
	receivingConnect = true;
//	int i = 0;
	lost = false;
	std::cout << "trying to connect" << std::endl;
	while (receivingConnect) {
		usleep(100000);
		serverCoid = name_open(attachPointRemote, NAME_FLAG_ATTACH_GLOBAL);
		if (serverCoid == -1) {
//			perror("Client: name_open failed");
//			std::cout << "try " << i << std::endl;
//			i++;
		}else {
			std::cout << "Connection success" << std::endl;
			receivingConnect = false;
		}
	}
		std::thread heartBeatSendT(&Com::heartBeatSend, this);
		std::thread heartBeatReceiveT(&Com::heartBeatReceive, this);
		heartBeatSendT.detach();
		heartBeatReceiveT.detach();
		hbthreadsRunning = true;

//	for (int value : dp->dispatch_map[static_cast<Event>(CON_ESTABLISHED)]) {
		dp->send(dp->dispatch_map[static_cast<Event>(CON_ESTABLISHED)], CON_ESTABLISHED, 0);
//	}
}

void Com::handle_pulseOtherFesto(_pulse msg) {
	if(msg.code == HEARTBEAT) {
		heartBeat = true;
//		std::cout << "got hb" << std::endl;
//	}else if(msg.code == KILL_SERVER){
//		std::cout << "kill received" << std::endl;
//		serverRunning = false;
	}else {
		std::cout << "Dispatcher: sending to ctx2" << std::endl;
		dp->send(dp->context2Coid, msg.code, msg.value.sival_int);
	}
}

void Com::heartBeatReceive() {

	auto start = std::chrono::system_clock::now();
	std::chrono::duration<double> diff;
	do {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		if(heartBeat) {
			start = std::chrono::system_clock::now();
			heartBeat = false;
		}
		diff = std::chrono::system_clock::now() - start;
	} while((diff.count() < 1.0) && !lost);

	std::cout << "heartbeat lost" << std::endl;

	lost = true;
	serverRunning = false;
	int hereCoid = name_open(attachPointHere, NAME_FLAG_ATTACH_GLOBAL);
	this->send(hereCoid, KILL_SERVER, 0);

//	for (int value : dp->dispatch_map[static_cast<Event>(CON_LOST)]) {
		dp->send(dp->dispatch_map[static_cast<Event>(CON_LOST)], CON_LOST, 0);
//	}
}

void Com::heartBeatSend() {
	while(1) {
		usleep(50000);
		if(lost) {
			break;
		}
		this->sendToServer(HEARTBEAT, 0);
//			std::cout << "hb" << std::endl;
	}
	std::cout << "hbsend terminated" << std::endl;
}

void Com::server() {
	bool failed = false;
	do {
	failed = false;
	attachHere = name_attach(NULL, attachPointHere, NAME_FLAG_ATTACH_GLOBAL);
	if (attachHere == NULL) {
		perror("Server: name_attach failed");
		failed = true;
	}else {
		std::cout << "Server: name_attach success" << std::endl;
	}
	}while(failed);
//	std::unique_lock<std::mutex> lk(mutex);
	serverRunning = true;
	_pulse msg;
	while (serverRunning) {
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
		if(msg.type == KILL_SERVER) {
			serverRunning = false;
		}
	}
	name_detach(attachHere, NAME_FLAG_ATTACH_GLOBAL);
	std::cout << "server terminated" << std::endl;
}

void Com::sendToServer(int code, int value) {
	if (MsgSendPulse(serverCoid, -1, code, value) == -1) {
		perror("Client: MsgSendPulse failed");
//		exit(EXIT_FAILURE);
	}
}

Com::~Com() {
	// TODO Auto-generated destructor stub
}

