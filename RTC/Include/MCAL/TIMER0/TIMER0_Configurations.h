/*
 * TIMER0_Configurations.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATIONS_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATIONS_H_

/*
	 *  TIMER0_MODE :-
	 *  NORMAL_MODE
	 *  PHASE_CORRECT_PWM_MODE
	 *  CTC_MODE
	 *  FAST_PWM_MODE
 */

#define TIMER0_MODE			NORMAL_MODE

/* TIMER0_OC0_MODE   (NO PWM) :-                                                               * TIMER0_OC0_MODE   (PWM) :-
	 * NORMAL_DIO                                                                                  * NORMAL_DIO
	 * TOGGLE_PIN                                                                                  * NON_INVERTING
	 * CLR_PIN                                                                                     * INVERTING
	 * SET_PIN
 */

#define TIMER0_OC0_MODE		NORMAL_DIO

/* Clock Modes :-
 	 	 	                   Description
		0 0 0          No clock source (Timer/Counter stopped).
		0 0 1          clk I/O /(No prescaling)
		0 1 0          clk I/O /8 (From prescaler)
		0 1 1          clk I/O /64 (From prescaler)
		1 0 0          clk I/O /256 (From prescaler)
		1 0 1          clk I/O /1024 (From prescaler)
		1 1 0          External clock source on T0 pin. Clock on falling edge.
		1 1 1          External clock source on T0 pin. Clock on rising edge.
 */

#define TIMER0_CLK			0b010


/*
 *  TIMER0_OVERFLOW_INTERRUPT_STATE :-
 	 *  TIMER0_INTERRUPT_ON
 	 *  TIMER0_INTERRUPT_OFF
 */

#define TIMER0_OVERFLOW_INTERRUPT_STATE					TIMER0_INTERRUPT_OFF

/*
 *  TIMER0_COMPARE_MATCH_INTERRUPT_STATE :-
 	 *  TIMER0_INTERRUPT_ON
 	 *  TIMER0_INTERRUPT_OFF
 */

#define TIMER0_COMPARE_MATCH_INTERRUPT_STATE			TIMER0_INTERRUPT_OFF

#endif /* INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATIONS_H_ */
