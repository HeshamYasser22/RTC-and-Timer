/*
 * TIMER2_Program.c
 *
 *  Created on: Aug 18, 2023
 *      Author: Hesham Yasser
 */


#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/MCAL/TIMER2/TIMER2_Interface.h"
#include "../Include/MCAL/TIMER2/TIMER2_private.h"
#include "../Include/MCAL/TIMER2/TIMER2_Configurations.h"


PtrToFunc_void TIMER2_OVRCallBack ;
PtrToFunc_void TIMER2_CompareMatchCallBack ;


void MTIMER2_voidInit (void)
{
#if TIMER2_MODE == NORMAL_MODE
	CLR_BIT(TCCR2 , WGM20);
	CLR_BIT(TCCR2 , WGM21);
#elif TIMER2_MODE == PHASE_CORRECT_PWM_MODE
	SET_BIT(TCCR2 , WGM20);
	CLR_BIT(TCCR2 , WGM21);
#elif TIMER2_MODE == CTC_MODE
	CLR_BIT(TCCR2 , WGM20);
	SET_BIT(TCCR2 , WGM21);
#elif TIMER2_MODE == FAST_PWM_MODE
	SET_BIT(TCCR2 , WGM20);
	SET_BIT(TCCR2 , WGM21);
#else
	#error WRONG_TIMER2_MODE
#endif
#if TIMER2_CLK_MODE == TIMER2_ASYNC
	SET_BIT (ASSR , AS2);
#else
	CLR_BIT (ASSR , AS2);
#endif
#if TIMER2_OVERFLOW_INTERRUPT_STATE == TIMER2_INTERRUPT_ON
	SET_BIT(TIMSK , TOIE2);
#else
	CLR_BIT(TIMSK , TOIE2);
#endif
#if TIMER2_COMPARE_MATCH_INTERRUPT_STATE == TIMER2_INTERRUPT_ON
	SET_BIT(TIMSK , OCIE2);
#else
	CLR_BIT(TIMSK , OCIE2);
#endif
	TCCR2 &= ~(TWO_BIT_MASK << COM2_B0);
	TCCR2 |= (TIMER2_OC2_MODE << COM2_B0);
	MTIMER2_voidStartTimer (TIMER2_CLK);


}
void MTIMER2_voidStartTimer (uint8 A_uint8PreScaler)
{
	if (A_uint8PreScaler < 8)
	{
		TCCR2 &= ~(THREE_BIT_MASK << CS2_B0);
		TCCR2 |= (A_uint8PreScaler << CS2_B0);
	}
}
void MTIMER2_voidStopTimer (void)
{
	TCCR2 &= ~(THREE_BIT_MASK << CS2_B0);
}
void MTIMER2_voidEnableOVFInterrupt (void)
{
	SET_BIT(TIMSK , TOIE2);

}
void MTIMER2_voidDisableOVFInterrupt (void)
{
	CLR_BIT(TIMSK , TOIE2);
}
void MTIMER2_voidEnableCompareMatchInterrupt (void)
{
	SET_BIT(TIMSK , OCIE2);
}
void MTIMER2_voidDisableCompareMatchInterrupt (void)
{
	CLR_BIT(TIMSK , OCIE2);
}
void MTIMER2_voidSetOVFCallBack (PtrToFunc_void A_OVFCallBack)
{
	TIMER2_OVRCallBack = A_OVFCallBack;
}
void MTIMER2_voidSetCompareMatchCallBack (PtrToFunc_void A_CompareMatchCallBack)
{
	TIMER2_CompareMatchCallBack = A_CompareMatchCallBack;
}
void MTIMER2_voidSetPreLoadValue (uint8 A_uint8Preload)
{
#if TIMER2_CLK_MODE == TIMER2_ASYNC
	while (GET_BIT(ASSR , TCN2UB) == 1);
#endif
	TCNT2 = A_uint8Preload;
}
void MTIMER2_voidSetOCRValue (uint8 A_uint8OCR2)
{
#if TIMER2_CLK_MODE == TIMER2_ASYNC
	while (GET_BIT(ASSR , OCR2UB) == 1);
#endif
	OCR2 = A_uint8OCR2;
}

uint8 MTIMER2_uint8ReadTCNTValue (void)
{
	return TCNT2;
}



void __vector_5 (void) __attribute__ ((signal));
void __vector_5 (void)
{
	if (TIMER2_OVRCallBack != NULL)
	{
		TIMER2_OVRCallBack();
	}
}

void __vector_4 (void) __attribute__ ((signal));
void __vector_4 (void)
{
	if (TIMER2_CompareMatchCallBack != NULL)
	{
		TIMER2_CompareMatchCallBack();
	}
}
