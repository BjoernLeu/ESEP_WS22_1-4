/**
 * Context.cpp
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

#include "Context.h"

int BaseState::coid;
int BaseState::coidExt;

//Old-Method
//Context::Context(const char* nameReceive, const char* nameSend, Actions *shared_action) : action(shared_action) {
//	if ((attach = name_attach(NULL, nameReceive, 0)) == NULL) {
//		perror("name_attach failed");
//		return;
//	}
//	startReceive(attach);
//	BaseState::coid = name_open(nameSend, 0);
//	if (BaseState::coid == -1) {
//		perror("name_open failed");	//loglevel replace
//		exit(EXIT_FAILURE);
//	}
//
//	data.setCoid(BaseState::coid);
//	send(BaseState::coid, static_cast<int>(ADC_SET_ZERO), 0);
//	state = new Connecting();
//	state->setData(&data);
//	state->setAction(shared_action);
//	state->entry();
//}

Context::Context(const char* nameReceive, const char* nameReceive2, const char* nameSend, const char* nameSend2, Actions *shared_action, int festo) : action(shared_action) {
	data.setFesto(festo);
	if ((attach = name_attach(NULL, nameReceive, 0)) == NULL) {
		perror("name_attach failed");
		return;
	}
	startReceive(attach);
	if ((attach2 = name_attach(NULL, nameReceive2, 0)) == NULL) {
		perror("name_attach failed");
		return;
	}
	std::thread receivingThread2(&Context::receive2, this);
	receivingThread2.detach();

	BaseState::coid = name_open(nameSend, 0);
	if (BaseState::coid == -1) {
		perror("name_open failed");	//loglevel replace
		exit(EXIT_FAILURE);
	}
	BaseState::coidExt = name_open(nameSend2, 0);
	if (BaseState::coidExt == -1) {
		perror("name_open failed");	//loglevel replace
		exit(EXIT_FAILURE);
	}

	data.mp = new MeasurePolling("cr");
	data.mp->init();

	data.setCoid(BaseState::coid);
	data.setCoidExt(BaseState::coidExt);
	state = new Connecting();
	state->setData(&data);
	state->setAction(shared_action);
//	state->entry();
}

void Context::start() {
	state->entry();
}

Context::~Context() {
	delete state;
}

void Context::receive2() {
	_pulse msg;
	while (1) {
		int recvid = MsgReceivePulse(attach2->chid, &msg, sizeof(_pulse),
				nullptr); // recvid < 0 Pulse failed, == 0 success
		if (recvid < 0) {
			perror("MsgReceivePulse failed!");
			exit(EXIT_FAILURE);
		}

		if (recvid == 0) {	//pulse received.
//			printf("Success");
			this->handle_pulse2(msg);
		}
	}
}

void Context::handle_pulse2(_pulse msg) {
	Event event = static_cast<Event>(msg.code);

	switch (event) {
	case ESTOP_SELF_PRESSED:
		state->handleEstopExtPressed();
		break;
	case ESTOP_SELF_RELEASED:
		state->handleEstopExtReleased();
		break;
	case FESTO_EXT_FREE:
		// std::cout << "Context: FESTO2_FREE" << std::endl;
		data.setFestoExtFree(true);
		state->handleFestoExtFree();
		break;
	case FESTO_EXT_FULL:
		state->handleFestoExtFull();
		break;
	default:
		std::cout << "Context pulse2 not handled: " << event << std::endl;
	}
}

void Context::handle_pulse(_pulse msg) {
	Event event = static_cast<Event>(msg.code);

	switch (event) {
//WP Height

//Festo2
	case FESTO_EXT_FREE:
		state->handleFestoExtFree();
		break;
	case FESTO_EXT_FULL:
		state->handleFestoExtFull();
		break;
//Workpiece
	case WP_DRILLING:
		state->handleWpDrilling();
		break;
	case WP_FLAT:
		state->handleWpFlat();
		break;
	case WP_HIGH:
		state->handleWpHigh();
		break;
	case WP_METAL:
		state->handleWpMetal();
		break;
	case WP_ID:
		state->handleWpID();
		break;
	case REMOVE_FROM_LIST:
		state->handleStartSp();
		break;
	case ADD_TO_LIST:
		state->handleStartSp();
		break;
	case ADD_WATCHER:
		state->handleStartSp();
		break;
	case WP_ARRIVED:
		state->handleWpArrived();
		break;
	case WP_TRANSFER:
		state->handleWpTransfer();
		break;
//Lightbarrier
	case LB_I:
		state->handleLbI();
		break;
	case LB_I_FREE:
		state->handleLbIFree();
		break;
	case LB_SW:
		state->handleLbSW();
		break;
	case LB_SW_FREE:
		state->handleLbSwFree();
		break;
	case LB_SL:
		state->handleLbSL();
		break;
	case LB_SL_FREE:
		state->handleLbSLFree();
		break;
	case LB_SL_SELF_FULL:
		state->handleSlSelfFull();
		break;
	case LB_SL_SELF_FREE:
		state->handleSLSelfFree();
		break;
	case LB_SL_EXT_FULL:
		state->handleSlExtFull();
		break;
	case LB_SL_EXT_FREE:
		state->handleSLExtFree();
		break;
	case LB_O:
		state->handleLbO();
		break;
	case LB_O_FREE:
		state->handleLbOFree();
		break;
//Pressable
	case START_SP:
		state->handleStartSp();
		break;
	case START_LP:
		state->handleStartLp();
		break;
	case START_RELEASED:
		state->handleStartReleased();
		break;
	case STOP_SP:
		state->handleStopSp();
		break;
	case STOP_LP:
		state->handleStopLp();
		break;
	case STOP_RELEASED:
		state->handleStopReleased();
		break;
	case RESET_SP:
		state->handleResetSp();
		break;
	case RESET_LP:
		state->handleResetLp();
		break;
	case RESET_RELEASED:
		state->handleResetReleased();
		break;
//EStop
	case ESTOP_SELF_PRESSED:
		state->handleEstopSelfPressed();
		break;
	case ESTOP_SELF_RELEASED:
		state->handleEstopSelfReleased();
		break;
	case ESTOP_EXT_PRESSED:
		state->handleEstopExtPressed();
		break;
	case ESTOP_EXT_RELEASED:
		state->handleEstopExtReleased();
		break;
	case ESTOP_DONE:
		state->handleEstopDone();
		break;
//Custom
	case CON_ESTABLISHED:
		state->handleConEstablished();
		break;
	case HS_WP:
		state->handleHsWP();
		break;
	case CALC_DONE:
		state->handleCalcDone();
		break;
	case WP_EXPECTED:
		state->handleWPExpected();
		break;
	case PRINT_ERROR:
		state->handlePrinted();
		break;
	case RECEIPTED:
		state->handleStartSp();
		break;
	case SEND_SIGNAL_SLIDE:
		state->handleStartSp();
		break;
	case ERROR:
		state->handleError();
		break;
	case EMPTY_BELT:
		state->handleEmptyBelt();
		break;

	default:
		std::cout << "not handled:" << event << std::endl;
	}
}

