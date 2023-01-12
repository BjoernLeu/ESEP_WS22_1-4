/*
 * Context.h
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

#ifndef SRC_FSM_GOF_CONTEXT_H_
#define SRC_FSM_GOF_CONTEXT_H_

#include <map>
#include "../../com/Communication.h"
#include "../Connecting.h"
#include "../../utils/Events.h"
#include "Actions.h"
#include "BaseState.h"
#include "../Connected/OperatingMode/Run/MeasurePolling.h"

/*
 * (vgl. GOF Pattern)
 * Schnittstelle für Zugriffe auf die stm
 */
class Context: public Communication {
public:
	Context(const char* nameReceive, const char* nameReceive2, const char* nameSend, const char* nameSend2,
			Actions *shared_action, int festo); // Konstruktor für die Klasse Context
	virtual ~Context(); // Destruktor für die Klasse Context
	void start();

protected:
	name_attach_t *attach;
	name_attach_t *attach2;

private:
	BaseState *state; // current state of state machine
	Actions *action;
	ContextData data;

	std::thread receivingThread2;

	void handle_pulse(_pulse msg);
	void receive2();
	void handle_pulse2(_pulse msg);
};

#endif /* SRC_FSM_GOF_CONTEXT_H_ */
