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
#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/KPAD/KPAD_Interface.h"

uint8 Program_uint8Pressed (void);
void Program_voidSendTwoDigits (uint32 A_uint32Number);
void Program_voidSendTime (uint32 A_uint32Seconds , uint32 A_uint32Minutes , uint32 A_uint32Hours);
void Program_voidStartTime (uint32 A_uint32Seconds , uint32 A_uint32Minutes , uint32 A_uint32Hours);

void main (void)
{
	MDIO_voidInit();
	HLCD_voidInit();
	HKPAD_voidInit();
	uint8 local_uint8Pressed = KPAD_NOTPRESSED;
	uint8 local_uint8Seconds = 0;
	uint8 local_uint8Minutes = 0;
	uint8 local_uint8Hours = 0;
	uint8 local_uint8Index = 0;
	while (1)
	{
		Program_voidSendTime(local_uint8Seconds , local_uint8Minutes , local_uint8Hours);

		HLCD_voidGoTo(0,0,local_uint8Index);
		local_uint8Pressed = Program_uint8Pressed();
		switch (local_uint8Pressed)
		{
		case 'U':
			switch (local_uint8Index)
			{
			case 0:
				local_uint8Hours += 10;
				break;
			case 1:
				local_uint8Hours += 1;
				break;
			case 3:
				local_uint8Minutes = (local_uint8Minutes+10)%60;
				break;
			case 4:
				local_uint8Minutes += (local_uint8Minutes+1)%60;
				break;
			case 6:
				local_uint8Seconds = (local_uint8Seconds+10)%60;
				break;
			case 7:
				local_uint8Seconds = (local_uint8Seconds+1)%60;
				break;
			}
			break;
		case 'D':
			switch (local_uint8Index)
			{
			case 0:
				local_uint8Hours = ((local_uint8Hours-10))&0x3f;
				break;
			case 1:
				local_uint8Hours = ((local_uint8Hours-1))&0x3f;
				break;
			case 3:
				local_uint8Minutes = (((local_uint8Minutes-10)&0x3f)%60);
				break;
			case 4:
				local_uint8Minutes = (((local_uint8Minutes-1)&0x3f)%60);
				break;
			case 6:
				local_uint8Seconds = (((local_uint8Seconds-10)&0x3f)%60);
				break;
			case 7:
				local_uint8Seconds = (((local_uint8Seconds-1)&0x3f)%60);
				break;
			}
			break;
		case 'R':
			local_uint8Index = (local_uint8Index+1)%8;
			break;
		case 'L':
			local_uint8Index = ((local_uint8Index-1)%8)&(0b111);
			break;
		case 'S':
			Program_voidStartTime(local_uint8Seconds , local_uint8Minutes , local_uint8Hours);
			local_uint8Seconds = 0;
			local_uint8Minutes = 0;
			local_uint8Hours = 0;
			break;
		}
	}
}

void Program_voidSendTwoDigits (uint32 A_uint32Number)
{
	if (A_uint32Number < 10)
	{
		HLCD_voidSendOneNumber(0,0);
		HLCD_voidSendOneNumber(0,A_uint32Number);
	}
	else
	{
		HLCD_voidSendNumbers(0,A_uint32Number);
	}
}

uint8 Program_uint8Pressed (void)
{
	uint8 local_uint8Key = KPAD_uint8GetPressedKey();
	while (local_uint8Key == KPAD_NOTPRESSED)
	{
		local_uint8Key = KPAD_uint8GetPressedKey();
	}
	return local_uint8Key;
}

void Program_voidSendTime (uint32 A_uint32Seconds , uint32 A_uint32Minutes , uint32 A_uint32Hours)
{
	//HLCD_voidSendCommand(0,1);
	HLCD_voidGoTo(0,0,0);
	Program_voidSendTwoDigits(A_uint32Hours);
	HLCD_voidSendData(0,':');
	Program_voidSendTwoDigits(A_uint32Minutes);
	HLCD_voidSendData(0,':');
	Program_voidSendTwoDigits(A_uint32Seconds);
}

void Program_voidStartTime (uint32 A_uint32Seconds , uint32 A_uint32Minutes , uint32 A_uint32Hours)
{
	while (A_uint32Hours != 0 || A_uint32Minutes != 0 || A_uint32Seconds != 0)
	{
		while (A_uint32Minutes != 0 || A_uint32Seconds != 0)
		{
			while (A_uint32Seconds != 0)
			{
				A_uint32Seconds--;
				_delay_ms (1000);
				Program_voidSendTime(A_uint32Seconds , A_uint32Minutes , A_uint32Hours);
			}
			if(A_uint32Minutes != 0)
			{
				A_uint32Seconds = 59;
				A_uint32Minutes--;
			}
		}
		if (A_uint32Hours != 0)
		{
			A_uint32Seconds = 59;
			A_uint32Minutes = 59;
			A_uint32Hours --;
		}

	}
	HLCD_voidGoTo(0,1,0);
	HLCD_voidSendString(0,"Its The Time");
	while (Program_uint8Pressed() == KPAD_NOTPRESSED);
	HLCD_voidSendCommand(0,1);
}
