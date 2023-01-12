#include <iostream>

// custom
#include "./hal/Hal.h"
#include "hal/HalControl.h"
#include "hal/ISR.h"
#include "dispatcher/Dispatcher.h"
#include "com/Com.h"
#include "utils/Gpio.h"
#include "fsm/gof/Context.h"
#include "fsm/Connected/OperatingMode/Run/MeasurePolling.h"


#include "fsm/gof/BaseState.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dispatch.h>

/**
 * @author Björn Leuendorf
 * @author Daniel Dichhte
 * @author Johannes Oehlers
 * @author Pascal Kießler
 */

int main(int argc, char* argv[]) {
	/**
	 * Abkürzungen:
	 * ar = ADC-Receive
	 * dr = Dispatcher-Receive
	 * cr = Context-Receive
	 * hr = HalControl-Receive
	 */
	int festo = 0;

	if ((argc >= 2) && (strcmp(argv[1], "-1") == 0)) {
		festo = 1;
	}else if ((argc >= 2) && (strcmp(argv[1], "-2") == 0)) {
		festo = 2;
	}

	Hal::init();


	Dispatcher dsp("dr", "dr2", festo);
	Com com(festo, &dsp);
	ISR isr("dr", "dr2");
	HalControl hc("hr", "dr");
	Context ctx("cr", "cr2", "dr", "dr2", NULL, festo);

//cr-ISR Events
 	dsp.subscribe("cr", HIGHVALUE);
	dsp.subscribe("cr", SWITCH_OPEN);
	dsp.subscribe("cr", SWITCH_CLOSE);
//cr-Pressable
 	dsp.subscribe("cr", START_SP);			//Start Short-Pressed
 	dsp.subscribe("cr", START_LP);			//Start Long-Pressed
	dsp.subscribe("cr", START_RELEASED);	//Start Released

 	dsp.subscribe("cr", STOP_SP);			//Stop Short-Pressed
	dsp.subscribe("cr", STOP_LP);			//Stop Long-Pressed
	dsp.subscribe("cr", STOP_RELEASED);		//Stop Released

 	dsp.subscribe("cr", RESET_SP);			//Reset Short-Pressed
	dsp.subscribe("cr", RESET_LP);			//Reset Long-Pressed
	dsp.subscribe("cr", RESET_RELEASED);	//Reset Released
//cr-Estop
 	dsp.subscribe("cr", ESTOP_SELF_PRESSED);
 	dsp.subscribe("cr", ESTOP_EXT_PRESSED);
 	dsp.subscribe("cr", ESTOP_SELF_RELEASED);
 	dsp.subscribe("cr", ESTOP_EXT_RELEASED);
 	dsp.subscribe("cr", ESTOP_DONE);
//cr-Lightbarrier
 	dsp.subscribe("cr", LB_I);				//Lightbarrier Inlet
	dsp.subscribe("cr", LB_I_FREE);
 	dsp.subscribe("cr", LB_SW);				//Lightbarrier Switch
	dsp.subscribe("cr", LB_SW_FREE);
 	dsp.subscribe("cr", LB_SL);				//Lightbarrier Slide
	dsp.subscribe("cr", LB_SL_FREE);
 	dsp.subscribe("cr", LB_SL_SELF_FULL);
 	dsp.subscribe("cr", LB_SL_SELF_FREE);
	dsp.subscribe("cr", LB_SL_EXT_FULL);
	dsp.subscribe("cr", LB_SL_EXT_FREE);
 	dsp.subscribe("cr", LB_O);				//Lighbarrier Outlet
 	dsp.subscribe("cr", LB_O_FREE);
//cr-ADC Events
// 	dsp.subscribe("cr", ADC_DONE);
//cr-Workpiece
 	dsp.subscribe("cr", WP_DRILLING);
 	dsp.subscribe("cr", WP_FLAT);
 	dsp.subscribe("cr", WP_METAL);
 	dsp.subscribe("cr", WP_HIGH);
	dsp.subscribe("cr", WP_CODE);
	dsp.subscribe("cr", ADD_TO_LIST);
	dsp.subscribe("cr", ADD_WATCHER);
	dsp.subscribe("cr", REMOVE_FROM_LIST); 
	dsp.subscribe("cr", WP_ID);
	dsp.subscribe("cr", WP_ARRIVED);
	dsp.subscribe("cr", WP_TRANSFER);
	dsp.subscribe("cr", TRANSFER_WAIT);
	dsp.subscribe("cr", TRANSFER_OK);
	
//cr-Festo2
 	dsp.subscribe("cr", FESTO2_SORT);
 	dsp.subscribe("cr", FESTO2_NOT_SORT);
//dr-Festo2
 	dsp.subscribe("hr", FESTO_EXT_FREE);
 	dsp.subscribe("hr", FESTO_EXT_FULL);
//hr-HAL Events
 	dsp.subscribe("hr", MOTOR_ON);
 	dsp.subscribe("hr", MOTOR_OFF);
 	dsp.subscribe("hr", MOTOR_STOP_ON);
 	dsp.subscribe("hr", MOTOR_STOP_OFF);
 	dsp.subscribe("hr", MOTOR_SLOW_ON);
 	dsp.subscribe("hr", MOTOR_SLOW_OFF);
 	dsp.subscribe("hr", LIGHT_RED_ON);
 	dsp.subscribe("hr", LIGHT_RED_OFF);
 	dsp.subscribe("hr", LIGHT_YELLOW_ON);
 	dsp.subscribe("hr", LIGHT_YELLOW_OFF);
 	dsp.subscribe("hr", LIGHT_GREEN_ON);
 	dsp.subscribe("hr", LIGHT_GREEN_OFF);
 	dsp.subscribe("hr", LED_START_ON);
 	dsp.subscribe("hr", LED_START_OFF);
 	dsp.subscribe("hr", LED_RESET_ON);
 	dsp.subscribe("hr", LED_RESET_OFF);
 	dsp.subscribe("hr", LIGHT_Q1_ON);
 	dsp.subscribe("hr", LIGHT_Q1_OFF);
 	dsp.subscribe("hr", LIGHT_Q2_ON);
 	dsp.subscribe("hr", LIGHT_Q2_OFF);
	dsp.subscribe("hr", SWITCH_OFF);
	dsp.subscribe("hr", STOP_ALL);
	dsp.subscribe("hr", THROW_WP);
	dsp.subscribe("hr", PASS_WP);
	dsp.subscribe("hr", SET_SW_TYPE);

//Custom
	dsp.subscribe("cr", CON_ESTABLISHED);
	dsp.subscribe("cr", HS_WP);
	dsp.subscribe("cr", CALC_DONE);
	dsp.subscribe("cr", SAVING_DONE);
	dsp.subscribe("cr", WP_EXPECTED);
	dsp.subscribe("cr", PRINT_ERROR);
	dsp.subscribe("cr", SEND_SIGNAL_SLIDE);
	dsp.subscribe("cr", ERROR);
	dsp.subscribe("cr", EMPTY_BELT);
	dsp.subscribe("cr", BOTH_FULL);
	dsp.subscribe("cr", EXT_FULL);
	dsp.subscribe("cr", SELF_FULL);
	dsp.subscribe("cr", BOTH_FREE);
	
	

 	std::cout << "Subscribing done" << std::endl;
 	isr.startISR();

 	dsp.startThreads("cr2");	//TODO: eventuell woanders starten

 	 //  sleep(10);
 	 //  ctx.start();

 	ctx.start();

 	 //  std::list<int> l = adcC.meassure();
 	 //  for(int n : l) {
 	 //	  std::cout << "meassure vlaue: " << n << std::endl;
 	 //  }

 	 while (1) {
 	 }

 	return 0;
}
