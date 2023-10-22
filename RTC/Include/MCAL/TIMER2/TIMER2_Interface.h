/*
 * TIMER2_Interface.h
 *
 *  Created on: Aug 18, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_
#define INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_

void MTIMER2_voidInit (void);
void MTIMER2_voidStartTimer (uint8 A_uint8PreScaler);
void MTIMER2_voidStopTimer (void);
void MTIMER2_voidEnableOVFInterrupt (void);
void MTIMER2_voidDisableOVFInterrupt (void);
void MTIMER2_voidEnableCompareMatchInterrupt (void);
void MTIMER2_voidDisableCompareMatchInterrupt (void);
void MTIMER2_voidSetOVFCallBack (PtrToFunc_void A_OVFCallBack);
void MTIMER2_voidSetCompareMatchCallBack (PtrToFunc_void A_CompareMatchCallBack);
void MTIMER2_voidSetPreLoadValue (uint8 A_uint8Preload);
void MTIMER2_voidSetOCRValue (uint8 A_uint8OCR2);
uint8 MTIMER2_uint8ReadTCNTValue (void);


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

#endif /* INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_ */
