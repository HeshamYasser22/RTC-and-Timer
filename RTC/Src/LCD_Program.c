/*
 * LCD_Program.c
 *
 *  Created on: Aug 6, 2023
 *      Author: Hesham Yasser
 */
#define F_CPU		8000000UL
#include <util/delay.h>
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/LCD/LCD_private.h"
#include "../Include/HAL/LCD/LCD_Configurations.h"

extern tstrLCDConfig LCD_Configurations[LCD_NUMBER];
void HLCD_voidInit (void)
{
	uint8 local_uint8Counter = 0;
	uint8 local_uint8Command = 0;
	for (local_uint8Counter = 0 ; local_uint8Counter < LCD_NUMBER ; local_uint8Counter++)
	{
		_delay_ms(30);
		if (LCD_Configurations[local_uint8Counter].LCD_uint8Mode == EIGHT_BIT)
		{
			local_uint8Command = 0b00110000;
			local_uint8Command |= ((LCD_Configurations[local_uint8Counter].LCD_uint8LinesNumber<<3) | (LCD_Configurations[local_uint8Counter].LCD_uint8FontSize<<2));
			HLCD_voidSendCommand (local_uint8Counter , local_uint8Command);
			_delay_ms(1);
			local_uint8Command = 0b00001100;
			local_uint8Command |= ((LCD_Configurations[local_uint8Counter].LCD_uint8CursorMode<<1) | (LCD_Configurations[local_uint8Counter].LCD_uint8BlinkMode<<0));
			HLCD_voidSendCommand (local_uint8Counter , local_uint8Command);
			_delay_ms(1);
			HLCD_voidSendCommand (local_uint8Counter , CLEAR_DISPLAY);
			_delay_ms(2);
			local_uint8Command = 0b00000100;
			local_uint8Command |= ((LCD_Configurations[local_uint8Counter].LCD_uint8IncrementMode<<1) | (LCD_Configurations[local_uint8Counter].LCD_uint8ShiftMode<<0));
			HLCD_voidSendCommand (local_uint8Counter , local_uint8Command);
			_delay_ms(1);
		}
		else
		{
			local_uint8Command = 0b00000010;
			HLCD_voidSendCommand (local_uint8Counter , local_uint8Command);
			local_uint8Command = 0b00100000;
			local_uint8Command |= ((LCD_Configurations[local_uint8Counter].LCD_uint8LinesNumber<<3) | (LCD_Configurations[local_uint8Counter].LCD_uint8FontSize<<2));
			HLCD_voidSendCommand (local_uint8Counter , local_uint8Command);
			_delay_ms(1);
			local_uint8Command = 0b00001100;
			local_uint8Command |= ((LCD_Configurations[local_uint8Counter].LCD_uint8CursorMode<<1) | (LCD_Configurations[local_uint8Counter].LCD_uint8BlinkMode<<0));
			HLCD_voidSendCommand (local_uint8Counter , local_uint8Command);
			_delay_ms(1);
			HLCD_voidSendCommand (local_uint8Counter , CLEAR_DISPLAY);
			_delay_ms(2);
			local_uint8Command = 0b00000100;
			local_uint8Command |= ((LCD_Configurations[local_uint8Counter].LCD_uint8IncrementMode<<1) | (LCD_Configurations[local_uint8Counter].LCD_uint8ShiftMode<<0));
			HLCD_voidSendCommand (local_uint8Counter , local_uint8Command);
			_delay_ms(1);
		}
	}

}
void HLCD_voidSendData (uint8 A_uint8LCDIndex , uint8 A_uint8Data)
{
	uint8 local_uint8Counter = 0;
	MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8RS , PIN_HIGH);
	MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8RW , PIN_LOW);

	if (LCD_Configurations[A_uint8LCDIndex].LCD_uint8Mode == EIGHT_BIT)
	{
		for (local_uint8Counter = 0 ; local_uint8Counter < 8 ; local_uint8Counter ++)
		{
			MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_auint8Pins[local_uint8Counter] , GET_BIT(A_uint8Data , local_uint8Counter));
		}
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_HIGH);
		_delay_ms(2);
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_LOW);
	}
	else
	{
		for (local_uint8Counter = 0 ; local_uint8Counter < 4 ; local_uint8Counter ++)
		{
			MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_auint8Pins[local_uint8Counter] , GET_BIT((A_uint8Data>>4), local_uint8Counter));
		}
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_HIGH);
		_delay_ms(2);
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_LOW);
		for (local_uint8Counter = 0 ; local_uint8Counter < 4 ; local_uint8Counter ++)
		{
			MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_auint8Pins[local_uint8Counter] , GET_BIT((A_uint8Data), local_uint8Counter));
		}
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_HIGH);
		_delay_ms(2);
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_LOW);
	}

}
void HLCD_voidSendCommand (uint8 A_uint8LCDIndex , uint8 A_uint8Command)
{
	uint8 local_uint8Counter = 0;
	MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8RS , PIN_LOW);
	MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8RW , PIN_LOW);

	if (LCD_Configurations[A_uint8LCDIndex].LCD_uint8Mode == EIGHT_BIT)
	{
		for (local_uint8Counter = 0 ; local_uint8Counter < 8 ; local_uint8Counter ++)
		{
			MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_auint8Pins[local_uint8Counter] , GET_BIT(A_uint8Command , local_uint8Counter));
		}
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_HIGH);
		_delay_ms(2);
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_LOW);
	}
	else
	{
		for (local_uint8Counter = 0 ; local_uint8Counter < 4 ; local_uint8Counter ++)
		{
			MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_auint8Pins[local_uint8Counter] , GET_BIT((A_uint8Command>>4), local_uint8Counter));
		}
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_HIGH);
		_delay_ms(2);
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_LOW);
		for (local_uint8Counter = 0 ; local_uint8Counter < 4 ; local_uint8Counter ++)
		{
			MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_auint8Pins[local_uint8Counter] , GET_BIT((A_uint8Command), local_uint8Counter));
		}
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_HIGH);
		_delay_ms(2);
		MDIO_enuSetPinValue(LCD_Configurations[A_uint8LCDIndex].LCD_uint8EN , PIN_LOW);
	}
}
void HLCD_voidGoTo (uint8 A_uint8LCDIndex , uint8 A_uint8Row , uint8 A_uint8Col)
{
	uint8 local_uint8Address = (0x40*A_uint8Row) + A_uint8Col;
	local_uint8Address |= (1<<7);
	HLCD_voidSendCommand(A_uint8LCDIndex , local_uint8Address);

}
void HLCD_voidSendString (uint8 A_uint8LCDIndex , uint8* A_puint8Str)
{
	uint8 local_uint8Iterator = 0;
	for (local_uint8Iterator = 0 ; A_puint8Str[local_uint8Iterator] != '\0' ; local_uint8Iterator++)
	{
		HLCD_voidSendData(A_uint8LCDIndex , A_puint8Str[local_uint8Iterator]);
	}

}
void HLCD_voidSendOneNumber (uint8 A_uint8LCDIndex , uint8 A_uint8Number)
{
	HLCD_voidSendData(A_uint8LCDIndex , (A_uint8Number+'0'));

}
void HLCD_voidSendNumbers (uint8 A_uint8LCDIndex , sint32 A_sint32Number)
{
	uint32 local_uint32Temp = 1;
	if (A_sint32Number != 0)
	{
		if (A_sint32Number < 0)
		{
			HLCD_voidSendData(A_uint8LCDIndex , '-');
			A_sint32Number = -(A_sint32Number);
		}
		while (A_sint32Number != 0)
		{
			local_uint32Temp = (local_uint32Temp*10) + (A_sint32Number%10);
			A_sint32Number = A_sint32Number/10;
		}
		while (local_uint32Temp !=1)
		{
			HLCD_voidSendOneNumber(A_uint8LCDIndex , local_uint32Temp%10);
			local_uint32Temp = local_uint32Temp/10;
		}
	}
	else
	{
		HLCD_voidSendOneNumber(A_uint8LCDIndex , 0);
	}

}
