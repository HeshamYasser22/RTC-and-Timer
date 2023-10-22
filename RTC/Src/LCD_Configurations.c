/*
 * LCD_Configurations.c
 *
 *  Created on: Aug 6, 2023
 *      Author: Hesham Yasser
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/LCD/LCD_private.h"
#include "../Include/HAL/LCD/LCD_Configurations.h"

tstrLCDConfig LCD_Configurations[LCD_NUMBER] = {{LCD1_PINS , PINB4 , PINB5 , PINB6 , FOUR_BIT , TWOLINES , ON , ON , ON ,OFF , FIVEBYTEN} };


