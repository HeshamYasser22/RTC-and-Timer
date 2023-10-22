/*
 * SS_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Hesham Yasser
 */


#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/SS/SS_Interface.h"
#include "../Include/HAL/SS/SS_private.h"
#include "../Include/HAL/SS/SS_Configurations.h"


extern SS_Config SS_Configurations [SS_NUMBER];

static uint8 global_uint8SSArray [] = SS_NUMBERS_ARRAY;

void HSS_voidEnableSS (uint8 A_uint8Index)
{
	if (A_uint8Index < SS_NUMBER)
	{
		if (SS_Configurations[A_uint8Index].SS_CommonMode == SS_COMMON_ANODE)
		{
			MDIO_enuSetPinValue(SS_Configurations[A_uint8Index].SS_CommonPin , PIN_HIGH);
		}
		else
		{
			MDIO_enuSetPinValue(SS_Configurations[A_uint8Index].SS_CommonPin , PIN_LOW);
		}
	}
}

void HSS_voidDisableSS (uint8 A_uint8Index)
{
	if (A_uint8Index < SS_NUMBER)
	{
		if (SS_Configurations[A_uint8Index].SS_CommonMode == SS_COMMON_ANODE)
		{
			MDIO_enuSetPinValue(SS_Configurations[A_uint8Index].SS_CommonPin , PIN_LOW);
		}
		else
		{
			MDIO_enuSetPinValue(SS_Configurations[A_uint8Index].SS_CommonPin , PIN_HIGH);
		}
	}
}

void HSS_voidSendNumber (uint8 A_uint8Index , uint8 A_uint8Number)
{
	uint8 local_uint8Iterator = 0;
	if (A_uint8Index < SS_NUMBER && A_uint8Number < 10)
	{
		if (SS_Configurations[A_uint8Index].SS_CommonMode == SS_COMMON_ANODE)
		{
			for (local_uint8Iterator = 0 ; local_uint8Iterator < PINS_NUMBER ; local_uint8Iterator++)
			{
				MDIO_enuSetPinValue(SS_Configurations[A_uint8Index].SS_Pins[local_uint8Iterator] , ((~GET_BIT(global_uint8SSArray[A_uint8Number] , local_uint8Iterator))&1));
			}
		}
		else
		{
			for (local_uint8Iterator = 0 ; local_uint8Iterator < PINS_NUMBER ; local_uint8Iterator++)
			{
				MDIO_enuSetPinValue(SS_Configurations[A_uint8Index].SS_Pins[local_uint8Iterator] , (GET_BIT(global_uint8SSArray[A_uint8Number] , local_uint8Iterator)));
			}
		}
	}
}
