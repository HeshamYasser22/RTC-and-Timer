/*
 * TIMER0_Interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_

void MTIMER0_voidInit (void);
void MTIMER0_voidStartTimer (uint8 A_uint8PreScaler);
void MTIMER0_voidStopTimer (void);
void MTIMER0_voidEnableOVFInterrupt (void);
void MTIMER0_voidDisableOVFInterrupt (void);
void MTIMER0_voidEnableCompareMatchInterrupt (void);
void MTIMER0_voidDisableCompareMatchInterrupt (void);
void MTIMER0_voidSetOVRCallBack (PtrToFunc_void A_OVFCallBack);
void MTIMER0_voidSetCompareMatchCallBack (PtrToFunc_void A_CompareMatchCallBack);
void MTIMER0_voidSetPreLoadValue (uint8 A_uint8Preload);
void MTIMER0_voidSetOCRValue (uint8 A_uint8OCR0);
uint8 MTIMER0_uint8ReadTCNTValue (void);
void MTIMER0_voidDelayinms (uint32 A_uint32Delay);

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

#endif /* INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
