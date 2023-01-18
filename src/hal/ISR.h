/**
 * Hardware Abstraction Layer Header
 *
 * @author Björn Leuendorf
 * @author Johannes Oehlers
 */

#ifndef SRC_ISR_H_
#define SRC_ISR_H_
#define _USE_32BIT_TIME_T 1
// custom
#include "../com/Communication.h"
#include "HalControl.h"

// system
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/neutrino.h>
#include <sys/iomsg.h>
#include <sys/procmgr.h>
#include <sys/mman.h>
#include <hw/inout.h>
#include <iostream>
#include <thread>
#include <time.h>
#include <sched.h>

//GPIO 0, folgende Bits sind Eingänge
#define P_IN_INLET 2                //low w.t.
#define P_IN_SWITCH 5                  //low w.t.
#define P_IS_METAL 7                   //high w.t.
#define P_ACTIVE_SWITCH 14             //high w.t.
#define P_LIMIT_SLIDE 15               //low w.t.
#define P_IN_OUTLET 20                   //low w.t.
#define P_START 22                     //high wenn gedrückt
#define P_STOP 23                      //low wenn gedrückt
#define P_RESET 26                     //high wenn gedrückt
#define P_ESTOP 27                     //low wenn gedrückt

/* Implementation */
using namespace std;

class ISR: public Communication {
public:
	ISR(const char* nameSend, const char* nameSend2); // Konstruktor für die Klasse ISR
	virtual ~ISR() {}; // Destruktor für die Klasse ISR
	int startISR();

private:
	void receivingRoutine(int);
	void handleInterrupt(void);
	void handle_pulse(_pulse msg);
	void slideWatchThread();
	void slideWatch();

	name_attach_t *attach = 0;
	int coid, coid2;
	int interruptID = 0;
	int old_level = -1;
	bool receivingRunning = false;
	bool isMetal = false;

	double diff_t_SL;

	double diff_t_start;
	double diff_t_stop;
	double diff_t_reset;

	time_t start_t_SL = 0, end_t_SL = 0;

	time_t start_t_start = 0, end_t_start = 0;
	time_t start_t_stop = 0, end_t_stop = 0;
	time_t start_t_reset = 0, end_t_reset = 0;

	static constexpr uint32_t GPIO_DEBOUNCENABLE = 0x150;
	static constexpr uint32_t GPIO_DEBOUNCINGTIME = 0x154;
	static constexpr int8_t   DEBOUNCETIME = 0x7F; //max is 3.9ms  (Debouncetime+1) * 31 us 7Bit reg

};
#endif /* SRC_ISR_H_ */
