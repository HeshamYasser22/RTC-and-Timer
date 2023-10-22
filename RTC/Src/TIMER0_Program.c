/*
 * TIMER0_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Hesham Yasser
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_private.h"
#include "../Include/MCAL/TIMER0/TIMER0_Configurations.h"


PtrToFunc_void TIMER0_OVRCallBack ;
PtrToFunc_void TIMER0_CompareMatchCallBack ;


void MTIMER0_voidInit (void)
{
#if TIMER0_MODE == NORMAL_MODE
	CLR_BIT(TCCR0 , WGM00);
	CLR_BIT(TCCR0 , WGM01);
#elif TIMER0_MODE == PHASE_CORRECT_PWM_MODE
	SET_BIT(TCCR0 , WGM00);
	CLR_BIT(TCCR0 , WGM01);
#elif TIMER0_MODE == CTC_MODE
	CLR_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);
#elif TIMER0_MODE == FAST_PWM_MODE
	SET_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);
#else
	#error WRONG_TIMER0_MODE
#endif
	TCCR0 &= ~(TWO_BIT_MASK << COM0_B0);
	TCCR0 |= (TIMER0_OC0_MODE << COM0_B0);
#if TIMER0_OVERFLOW_INTERRUPT_STATE == TIMER0_INTERRUPT_ON
	SET_BIT(TIMSK , TOIE0);
#else
	CLR_BIT(TIMSK , TOIE0);
#endif
#if TIMER0_COMPARE_MATCH_INTERRUPT_STATE == TIMER0_INTERRUPT_ON
	SET_BIT(TIMSK , OCIE0);
#else
	CLR_BIT(TIMSK , OCIE0);
#endif
	MTIMER0_voidStartTimer (TIMER0_CLK);

}
void MTIMER0_voidStartTimer (uint8 A_uint8PreScaler)
{
	if (A_uint8PreScaler < 8)
	{
		TCCR0 &= ~(THREE_BIT_MASK << CS0_B0);
		TCCR0 |= (A_uint8PreScaler << CS0_B0);
	}
}
void MTIMER0_voidStopTimer (void)
{
	TCCR0 &= ~(THREE_BIT_MASK << CS0_B0);
}
void MTIMER0_voidEnableOVFInterrupt (void)
{
	SET_BIT(TIMSK , TOIE0);

}
void MTIMER0_voidDisableOVFInterrupt (void)
{
	CLR_BIT(TIMSK , TOIE0);
}
void MTIMER0_voidEnableCompareMatchInterrupt (void)
{
	SET_BIT(TIMSK , OCIE0);
}
void MTIMER0_voidDisableCompareMatchInterrupt (void)
{
	CLR_BIT(TIMSK , OCIE0);
}
void MTIMER0_voidSetOVRCallBack (PtrToFunc_void A_OVFCallBack)
{
	TIMER0_OVRCallBack = A_OVFCallBack;
}
void MTIMER0_voidSetCompareMatchCallBack (PtrToFunc_void A_CompareMatchCallBack)
{
	TIMER0_CompareMatchCallBack = A_CompareMatchCallBack;
}
void MTIMER0_voidSetPreLoadValue (uint8 A_uint8Preload)
{
	TCNT0 = A_uint8Preload;
}
void MTIMER0_voidSetOCRValue (uint8 A_uint8OCR0)
{
	OCR0 = A_uint8OCR0;
}

uint8 MTIMER0_uint8ReadTCNTValue (void)
{
	return TCNT0;
}

void MTIMER0_voidDelayinms (uint32 A_uint32Delay)
{
	uint16 local_uint16PreScaler = 8;
	float32 local_float32TimerFrequency = ((F_CPU/1000)/local_uint16PreScaler)/TIMER0_RES;
	float32 local_float32TickTime = 1/local_float32TimerFrequency;
	uint32 local_uint32NeededTicks = A_uint32Delay / local_float32TickTime;
	if (local_uint32NeededTicks % TIMER0_RES != 0)
	{
		MTIMER0_voidSetPreLoadValue((TIMER0_RES-(local_uint32NeededTicks % TIMER0_RES)));
		local_uint32NeededTicks++;
	}
	MTIMER0_voidStartTimer(TIMER0_CLK);
	while (local_uint32NeededTicks != 0)
	{
		while (GET_BIT(TIFR , TOV0) == 0);
		SET_BIT(TIFR , TOV0);
		local_uint32NeededTicks--;
	}
	MTIMER0_voidStopTimer();
}


void __vector_11 (void) __attribute__ ((signal));
void __vector_11 (void)
{
	if (TIMER0_OVRCallBack != NULL)
	{
		TIMER0_OVRCallBack();
	}
}

void __vector_10 (void) __attribute__ ((signal));
void __vector_10 (void)
{
	if (TIMER0_CompareMatchCallBack != NULL)
	{
		TIMER0_CompareMatchCallBack();
	}
}
