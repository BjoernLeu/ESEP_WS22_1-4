/*
 * Events.h
 *
 * @author Björn Leuendorf 
 */

#ifndef SRC_UTILS_EVENTS_H_
#define SRC_UTILS_EVENTS_H_

enum Event {
// HAL Events
	MOTOR_ON,
	MOTOR_OFF,
	MOTOR_STOP_ON,
	MOTOR_STOP_OFF,
	MOTOR_SLOW_ON,
	MOTOR_SLOW_OFF,
	LIGHT_RED_ON,
	LIGHT_RED_OFF,
	LIGHT_YELLOW_ON,
	LIGHT_YELLOW_OFF,
	LIGHT_GREEN_ON,
	LIGHT_GREEN_OFF,
	LED_START_ON,
	LED_START_OFF,
	LED_RESET_ON,
	LED_RESET_OFF,
	LIGHT_Q1_ON,
	LIGHT_Q1_OFF,
	LIGHT_Q2_ON,
	LIGHT_Q2_OFF,
//Switch
	SWITCH_OFF,			//Steuerung d. Switch
	SWITCH_OPEN,		//ISR
	SWITCH_CLOSE,		//ISR
	SET_SW_TYPE,
	THROW_WP,
	PASS_WP,
//Pressable
	START_SP,
	START_LP,
	START_RELEASED,
	STOP_SP,
	STOP_LP,
	STOP_RELEASED,
	RESET_SP,
	RESET_LP,
	RESET_RELEASED,
//EStop
	ESTOP_SELF_PRESSED,
	ESTOP_EXT_PRESSED,
	ESTOP_SELF_RELEASED,
	ESTOP_EXT_RELEASED,
	ESTOP_DONE,
	STOP_ALL,
//Lightbarrier
	LB_I,
	LB_I_FREE,
	LB_SW,
	LB_SW_FREE,
	LB_SL,
	LB_SL_FREE,
	LB_O,
	LB_O_FREE,
//ADC Events
	HS_WP,
	HS_BELT,
//	ADC_SET_ZERO,
//	ADC_SET_HIGH,
//	ADC_SAMPLE,
//	ADC_DONE,
//Workpiece
	WP_DRILLING,
	WP_FLAT,
	WP_HIGH,
	WP_METAL,
	WP_CODE,		//Event for all coded workpieces
	WP_ID,
	PLACEHOLDER,
	REMOVE_FROM_LIST,
	ADD_TO_LIST,
	ADD_WATCHER,
	WP_ARRIVED,
	WP_TRANSFER,
	TRANSFER_WAIT,
	TRANSFER_OK,
// custom
	HIGHVALUE,
	HEARTBEAT,
	KILL_SERVER,
//Festo2
	FESTO2_SORT,
	FESTO2_NOT_SORT,
	FESTO_EXT_FREE,
	FESTO_EXT_FULL,
//Slide
	LB_SL_SELF_FULL,
	LB_SL_SELF_FREE,
	LB_SL_EXT_FULL,
	LB_SL_EXT_FREE,
//Custom
	CON_ESTABLISHED,
	CALC_DONE,
	SAVING_DONE,
	WP_EXPECTED,
	PRINT_ERROR,
	RECEIPTED, 
	SEND_SIGNAL_SLIDE,
	ERROR,
	EMPTY_BELT,
};

#endif /* SRC_UTILS_EVENTS_H_ */
