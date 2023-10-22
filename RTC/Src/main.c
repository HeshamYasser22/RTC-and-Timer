/*
 * main.c
 *
 *  Created on: Aug 2, 2023
 *      Author: Hesham Yasser
 */
#define F_CPU	8000000UL
#include <util/delay.h>
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/GI/GI_Interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_Interface.h"
#include "../Include/MCAL/TIMER2/TIMER2_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/KPAD/KPAD_Interface.h"
#include "../Include/HAL/SS/SS_Interface.h"


void Program_voidTimerOVF (void);
void Program_voidSSDisplayClock (void);
uint8 Program_KPADGetKey (void);
void Program_SetClock (void);
//void Program_voidSSSendTwoNumbers (uint8 A_uint8Number);



uint8 global_uint8Hour = 0;
uint8 global_uint8Minute = 0;
uint8 global_uint8Second = 0;
void main (void)
{
	MDIO_voidInit();
	HLCD_voidInit();
	HKPAD_voidInit();
	MGI_voidGIEnable();
	MTIMER0_voidInit();
	MTIMER0_voidStopTimer();
	MTIMER2_voidSetOVFCallBack(Program_voidTimerOVF);
	MTIMER2_voidInit();
	MTIMER2_voidDisableOVFInterrupt();
	MTIMER2_voidStopTimer();
	while (1)
	{
		Program_SetClock();
		MTIMER2_voidStartTimer(0b101);
		MTIMER2_voidEnableOVFInterrupt();
		while (1)
		{
			Program_voidSSDisplayClock();
		}
	}
}

void Program_voidTimerOVF (void)
{
	if (global_uint8Second < 60)
	{
		global_uint8Second++;
		if (global_uint8Second == 60)
		{
			global_uint8Second = 0;
			if (global_uint8Minute < 60)
			{
				global_uint8Minute++;
				if (global_uint8Minute == 60)
				{
					global_uint8Minute = 0;
					if (global_uint8Hour < 24)
					{
						global_uint8Hour++;
						if (global_uint8Hour == 24)
						{
							global_uint8Hour = 0;
						}
					}

				}

			}

		}

	}
	//Program_voidSSDisplayClock();
}
void Program_voidSSDisplayClock (void)
{
	HSS_voidSendNumber(0,(global_uint8Second%10));
	HSS_voidEnableSS(0);
	MTIMER0_voidDelayinms(4);
	HSS_voidDisableSS(0);
	HSS_voidSendNumber(1,(global_uint8Second/10));
	HSS_voidEnableSS(1);
	MTIMER0_voidDelayinms(4);
	HSS_voidDisableSS(1);
	HSS_voidSendNumber(2,(global_uint8Minute%10));
	HSS_voidEnableSS(2);
	MTIMER0_voidDelayinms(4);
	HSS_voidDisableSS(2);
	HSS_voidSendNumber(3,(global_uint8Minute/10));
	HSS_voidEnableSS(3);
	MTIMER0_voidDelayinms(4);
	HSS_voidDisableSS(3);
	HSS_voidSendNumber(4,(global_uint8Hour%10));
	HSS_voidEnableSS(4);
	MTIMER0_voidDelayinms(4);
	HSS_voidDisableSS(4);
	HSS_voidSendNumber(5,(global_uint8Hour/10));
	HSS_voidEnableSS(5);
	MTIMER0_voidDelayinms(4);
	HSS_voidDisableSS(5);
}
uint8 Program_KPADGetKey (void)
{
	uint8 local_uint8Return = KPAD_NOTPRESSED;
	while (local_uint8Return == KPAD_NOTPRESSED)
	{
		local_uint8Return = KPAD_uint8GetPressedKey();
	}
	return local_uint8Return;
}
void Program_SetClock (void)
{
	global_uint8Hour = 0;
	global_uint8Minute = 0;
	global_uint8Second = 0;
	uint8 local_uint8Iterator = 0;
	uint8 local_uint8Key = 0;
	do
	{
		global_uint8Hour = 0;
		HLCD_voidSendString(0,"Hour : ");
		for (local_uint8Iterator = 0 ; local_uint8Iterator < 2 ; local_uint8Iterator++)
		{
			local_uint8Key = Program_KPADGetKey();
			if ((local_uint8Key <= '9') && (local_uint8Key >= '0'))
			{
				global_uint8Hour = global_uint8Hour*10 + (local_uint8Key-'0');
				HLCD_voidSendData(0,local_uint8Key);
			}
			else
			{
				local_uint8Iterator--;
			}
		}
		if (global_uint8Hour > 24)
		{
			HLCD_voidSendCommand(0,1);
			HLCD_voidSendString(0,"Wrong Input !");
			MTIMER0_voidDelayinms(500);
			HLCD_voidSendCommand(0,1);
		}
	}
	while (global_uint8Hour > 24);


	MTIMER0_voidDelayinms(300);
	HLCD_voidSendCommand(0,1);
	do
	{
		global_uint8Minute = 0;
		HLCD_voidSendString(0,"Minutes : ");
		for (local_uint8Iterator = 0 ; local_uint8Iterator < 2 ; local_uint8Iterator++)
		{
			local_uint8Key = Program_KPADGetKey();
			if ((local_uint8Key <= '9') && (local_uint8Key >= '0'))
			{
				global_uint8Minute = global_uint8Minute*10 + (local_uint8Key-'0');
				HLCD_voidSendData(0,local_uint8Key);
			}
			else
			{
				local_uint8Iterator--;
			}
		}
		if (global_uint8Minute > 60)
		{
			HLCD_voidSendCommand(0,1);
			HLCD_voidSendString(0,"Wrong Input !");
			MTIMER0_voidDelayinms(500);
			HLCD_voidSendCommand(0,1);
		}
	}
	while (global_uint8Minute > 60);
	MTIMER0_voidDelayinms(300);
	HLCD_voidSendCommand(0,1);
	do
	{
		global_uint8Second = 0;
		HLCD_voidSendString(0,"Seconds : ");
		for (local_uint8Iterator = 0 ; local_uint8Iterator < 2 ; local_uint8Iterator++)
		{
			local_uint8Key = Program_KPADGetKey();
			if ((local_uint8Key <= '9') && (local_uint8Key >= '0'))
			{
				global_uint8Second = global_uint8Second*10 + (local_uint8Key-'0');
				HLCD_voidSendData(0,local_uint8Key);
			}
			else
			{
				local_uint8Iterator--;
			}
		}
		if (global_uint8Second > 60)
		{
			HLCD_voidSendCommand(0,1);
			HLCD_voidSendString(0,"Wrong Input !");
			MTIMER0_voidDelayinms(500);
			HLCD_voidSendCommand(0,1);
		}
	}
	while (global_uint8Second > 60);
	MTIMER0_voidDelayinms(300);
	HLCD_voidSendCommand(0,1);
	HLCD_voidSendString(0,"    Tic Tak");
}
