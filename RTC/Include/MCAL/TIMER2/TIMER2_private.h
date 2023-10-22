/*
 * TIMER2_private.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_MCAL_TIMER2_TIMER2_PRIVATE_H_
#define INCLUDE_MCAL_TIMER2_TIMER2_PRIVATE_H_


#define TCCR2					(*(volatile uint8 *)0x45)
#define FOC2					7
#define WGM20					6
#define COM2_B0					4
#define WGM21					3
#define CS2_B0					0


#define TCNT2					(*(volatile uint8 *)0x44)

#define OCR2					(*(volatile uint8 *)0x43)


#define ASSR					(*(volatile uint8 *)0x42)
#define AS2						3
#define TCN2UB					2
#define OCR2UB					1
#define TCR2UB					0

#define TIMSK					(*(volatile uint8 *)0x59)
#define TOIE2					6
#define OCIE2					7

#define TIFR					(*(volatile uint8 *)0x58)
#define TOV2					6
#define OCF2					7


#define TWO_BIT_MASK			0b11
#define THREE_BIT_MASK			0b111


#define NORMAL_MODE					1
#define PHASE_CORRECT_PWM_MODE		2
#define CTC_MODE					3
#define FAST_PWM_MODE				4


#define NORMAL_DIO					0
#define TOGGLE_PIN					1
#define CLR_PIN						2
#define SET_PIN						3

#define NORMAL_DIO					0
#define NON_INVERTING				2
#define INVERTING					3

#define TIMER2_INTERRUPT_ON			1
#define TIMER2_INTERRUPT_OFF		0

#define TIMER2_RES					256

#define TIMER2_SYNC					0
#define TIMER2_ASYNC				1


#endif /* INCLUDE_MCAL_TIMER2_TIMER2_PRIVATE_H_ */
