/*
 * TIMER0_private.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_


#define TCCR0					(*(volatile uint8 *)0x53)
#define FOC0					7
#define WGM00					6
#define COM0_B0					4
#define WGM01					3
#define CS0_B0					0


#define TCNT0					(*(volatile uint8 *)0x52)

#define OCR0					(*(volatile uint8 *)0x5C)

#define TIMSK					(*(volatile uint8 *)0x59)
#define TOIE0					0
#define OCIE0					1

#define TIFR					(*(volatile uint8 *)0x58)
#define TOV0					0
#define OCF0					1


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

#define TIMER0_INTERRUPT_ON			1
#define TIMER0_INTERRUPT_OFF		0

#define TIMER0_RES					256

#endif /* INCLUDE_MCAL_TIMER0_TIMER0_PRIVATE_H_ */
