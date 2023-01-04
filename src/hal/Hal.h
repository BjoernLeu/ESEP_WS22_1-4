/**
 * Hardware Abstraction Layer Header
 *
 * @author Björn Leuendorf 
 * @author Johannes Oehlers
 */

// system
#include <iostream>
#include <stdint.h>
#include <sys/mman.h>
#include <hw/inout.h>
#include <sys/neutrino.h>

#ifndef SRC_HAL_H_
#define SRC_HAL_H_

//Klasse fuer HAL zum Kommunizieren mit der Hardware
class Hal {
public:
	Hal(); // Konstruktor der Klasse Hal
	virtual ~Hal(); // Destruktor der Klasse Hal

	static void init();
	/*
	 * Schaltet den  Motor vom Förderband ein.
	 * Das Förderband läuft nur nach rechts.
	 */
	static void motorOn();

	/*
	 * Schaltet den Motor vom Förderband ab.
	 */
	static void motorOff();

	/*
	 * Reduziert die Geschwindigkeit vom Förderband Motor.
	 */
	static void motorSlowOn();

	/*
	 * Hebt die Geschwindigkeitsreduktion auf.
	 */
	static void motorSlowOff();

	/*
	 * Stopt den Förderbandmotor.
	 * Anders als bei motorOff wird der Motor nicht abgeschaltet.
	 */
	static void motorStopOn();

	/*
	 * Hebt den Motorstop auf und lässt den Motor weiterlaufen.
	 */
	static void motorStopOff();

	/*
	 * Schaltet das rote Ampellicht ein.
	 */
	static void lightRedOn();

	/*
	 * Schaltet das rote Ampellicht aus.
	 */
	static void lightRedOff();

	/*
	 * Schaltet das gelbe Ampellicht ein.
	 */
	static void lightYellowOn();

	/*
	 * Schaltet das gelbe Ampellicht aus.
	 */
	static void lightYellowOff();

	/*
	 * Schaltet das grüne Ampellicht ein.
	 */
	static void lightGreenOn();

	/*
	 * Schaltet das grüne Ampellicht aus.
	 */
	static void lightGreenOff();

	/*
	 * Je nach ausstattung der Anlage wird entweder die Weiche geöffnet, oder der Auswerfer aktiviert.
	 */
	static void switchOn();

	/*
	 * Je nach ausstattung der Anlage wird entweder die Weiche geschlossen, oder der Auswerfer deaktiviert.
	 */
	static void switchOff();

	/*
	 * Schaltet die LED am Startknopf ein.
	 */
	static void ledStartOn();

	/*
	 * Schaltet die LED am Startknopf aus.
	 */
	static void ledStartOff();

	/*
	 * Schaltet die LED am Resetknopf ein.
	 */
	static void ledResetOn();

	/*
	 * Schaltet die LED am Reset-Knopf aus.
	 */
	static void ledResetOff();

	/*
	 * Schaltet das Signallicht an Q1 ein.
	 */
	static void signalFirstOn();

	/*
	 * Schaltet das Signallicht an Q1 aus.
	 */
	static void signalFirstOff();

	/*
	 * Schaltet das Signallicht an Q2 ein.
	 */
	static void signalSecondOn();

	/*
	 * Schaltet das Signallicht an Q2 aus.
	 */
	static void signalSecondOff();
};

#endif /* SRC_HAL_H_ */
