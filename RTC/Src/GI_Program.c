/*
 * GI_Program.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Hesham Yasser
 */


#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/MCAL/GI/GI_Interface.h"
#include "../Include/MCAL/GI/GI_private.h"
#include "../Include/MCAL/GI/GI_Configurations.h"

void MGI_voidGIEnable (void)
{
	SET_BIT(SREG , I_PIN);
}
void MGI_voidGIDisable (void)
{
	CLR_BIT(SREG , I_PIN);
}
