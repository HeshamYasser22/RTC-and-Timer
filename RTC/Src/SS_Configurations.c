/*
 * SS_Configurations.c
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


SS_Config SS_Configurations [SS_NUMBER]  =
		{
				{
						{
							PIND0 , PIND1 , PIND2 , PIND3 , PIND4 , PIND5 , PIND6
						}
						,
						SS_COMMON_CATHODE
						,
						PINC0
				}
				,
				{
						{
							PIND0 , PIND1 , PIND2 , PIND3 , PIND4 , PIND5 , PIND6
						}
						,
						SS_COMMON_CATHODE
						,
						PINC1
				}
				,
				{
						{
							PIND0 , PIND1 , PIND2 , PIND3 , PIND4 , PIND5 , PIND6
						}
						,
						SS_COMMON_CATHODE
						,
						PINC2
				}
				,
				{
						{
							PIND0 , PIND1 , PIND2 , PIND3 , PIND4 , PIND5 , PIND6
						}
						,
						SS_COMMON_CATHODE
						,
						PINC3
				}
				,
				{
						{
							PIND0 , PIND1 , PIND2 , PIND3 , PIND4 , PIND5 , PIND6
						}
						,
						SS_COMMON_CATHODE
						,
						PINC4
				}
				,
				{
						{
							PIND0 , PIND1 , PIND2 , PIND3 , PIND4 , PIND5 , PIND6
						}
						,
						SS_COMMON_CATHODE
						,
						PINC5
				}
		};
