/*
 * TIMER2_Configurations.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_MCAL_TIMER2_TIMER2_CONFIGURATIONS_H_
#define INCLUDE_MCAL_TIMER2_TIMER2_CONFIGURATIONS_H_

/*
	 *  TIMER2_MODE :-
	 *  NORMAL_MODE
	 *  PHASE_CORRECT_PWM_MODE
	 *  CTC_MODE
	 *  FAST_PWM_MODE
 */

#define TIMER2_MODE			NORMAL_MODE

/*  TIMER2_CLK_MODE :-
 	 *  TIMER2_SYNC
 	 *  TIMER2_ASYNC
 */

#define TIMER2_CLK_MODE		TIMER2_ASYNC

/* TIMER0_OC2_MODE   (NO PWM) :-                                                               * TIMER0_OC2_MODE   (PWM) :-
	 * NORMAL_DIO                                                                                  * NORMAL_DIO
	 * TOGGLE_PIN                                                                                  * NON_INVERTING
	 * CLR_PIN                                                                                     * INVERTING
	 * SET_PIN
 */

#define TIMER2_OC2_MODE		NORMAL_DIO

/* Clock Modes :-
 	 	 	                   Description
		0 0 0          No clock source (Timer/Counter stopped).
		0 0 1          clk T2S /(No prescaling)
		0 1 0          clk T2S /8 (From prescaler)
		0 1 1          clk T2S /32 (From prescaler)
		1 0 0          clk T2S /64 (From prescaler)
		1 0 1          clk T2S /128 (From prescaler)
		1 1 0          clk T2S /256 (From prescaler)
		1 1 1          clk T2S /1024 (From prescaler)
 */

#define TIMER2_CLK			0b101


/*
 *  TIMER0_OVERFLOW_INTERRUPT_STATE :-
 	 *  TIMER2_INTERRUPT_ON
 	 *  TIMER2_INTERRUPT_OFF
 */

#define TIMER2_OVERFLOW_INTERRUPT_STATE					TIMER2_INTERRUPT_ON

/*
 *  TIMER0_COMPARE_MATCH_INTERRUPT_STATE :-
 	 *  TIMER2_INTERRUPT_ON
 	 *  TIMER2_INTERRUPT_OFF
 */

#define TIMER2_COMPARE_MATCH_INTERRUPT_STATE			TIMER2_INTERRUPT_OFF

#endif /* INCLUDE_MCAL_TIMER2_TIMER2_CONFIGURATIONS_H_ */
