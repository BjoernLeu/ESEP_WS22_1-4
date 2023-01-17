/**
 * HalControl.h
 *
 * @author Björn Leuendorf 
 */

#ifndef SRC_HAL_HALCONTROL_H_
#define SRC_HAL_HALCONTROL_H_

// custom
#include "../com/Communication.h"
#include "../hal/Hal.h"
#include "../utils/Events.h"

// map
#include <map>

// GPIO
#define GPIO_DATA_IN 0x138
#define GPIO_REGISTER_LENGHT 0x1000
#define GPIO_PORT0 0x44E07000

/**
 * Schnittstelle für den Dispatcher.
 * Nimmt Events entgegen, mit welchen die HAL angesteuert werden können.
 */
class HalControl: public Communication {
public:
	HalControl(const char* nameReceive, const char* nameSend, const char* nameSend2); // Konstruktor für die Klasse HalControl
	virtual ~HalControl() {}; // Destruktor für die Klasse HalControl
	std::thread receivingThread;

	// static void blinkingOn(std::string light, std::string speed, int seconds);
private:

	/**
	 * Steuert die gewünschte Aktorik an.
	 *
	 * @param msg Nachricht mit Event
	 */
	void handle_pulse(_pulse msg);

//custom Variables

	name_attach_t *attach;

	void throwWP();
	void passWP();
	void getEstop();
	void setSwitchType();

	static bool switchType;	// true if Switch & false if Extruder
	static int coid;
	static int coidExt;
	static void saveState();
};

#endif /* SRC_HAL_HALCONTROL_H_ */
