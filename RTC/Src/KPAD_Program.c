/*
 * KPAD_Program.c
 *
 *  Created on: Aug 8, 2023
 *      Author: Hesham Yasser
 */
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/KPAD/KPAD_Interface.h"
#include "../Include/HAL/KPAD/KPAD_private.h"
#include "../Include/HAL/KPAD/KPAD_Configurations.h"
uint8 global_KPADCol[KPAD_COL_NUM] = KPAD_COLS_PINS;
uint8 global_KPADRow[KPAD_ROW_NUM] = KPAD_ROWS_PINS;
uint8 global_KPADKeys [KPAD_COL_NUM][KPAD_COL_NUM] = KPAD_KEYS;

void HKPAD_voidInit(void)
{
	uint8 local_uint8Iterator = 0;
	for (local_uint8Iterator = 0 ; local_uint8Iterator < KPAD_ROW_NUM ; local_uint8Iterator++)
	{
		MDIO_enuSetPinValue(global_KPADRow[local_uint8Iterator] , PIN_HIGH);
	}
	for (local_uint8Iterator = 0 ; local_uint8Iterator < KPAD_COL_NUM ; local_uint8Iterator++)
	{
		MDIO_enuPullUpState(global_KPADCol[local_uint8Iterator] , PULLUP_ENABLE);
	}
}
uint8 KPAD_uint8GetPressedKey(void)
{
	uint8 local_uint8RowIterator = 0;
	uint8 local_uint8ColIterator = 0;
	uint8 local_uint8ColValue = 0;
	uint8 local_uint8ReturnVal = KPAD_NOTPRESSED;
	for (local_uint8RowIterator = 0 ; local_uint8RowIterator < KPAD_ROW_NUM ; local_uint8RowIterator++)
	{
		MDIO_enuSetPinValue(global_KPADRow[local_uint8RowIterator] , PIN_LOW);
		for (local_uint8ColIterator = 0 ; local_uint8ColIterator < KPAD_COL_NUM ; local_uint8ColIterator++)
		{
			MDIO_enuReadPinValue(global_KPADCol[local_uint8ColIterator] , &local_uint8ColValue);
			if (local_uint8ColValue == 0)
			{
				while (local_uint8ColValue == 0)
				{
					MDIO_enuReadPinValue(global_KPADCol[local_uint8ColIterator] , &local_uint8ColValue);
				}
				local_uint8ReturnVal = global_KPADKeys[local_uint8RowIterator][local_uint8ColIterator];
				break;
			}
		}
		MDIO_enuSetPinValue(global_KPADRow[local_uint8RowIterator] , PIN_HIGH);
		if (local_uint8ReturnVal != KPAD_NOTPRESSED)
		{
			break;
		}
	}
	return local_uint8ReturnVal;
}
