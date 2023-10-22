/*
 * DIO_Program.c
 *
 *  Created on: Aug 2, 2023
 *      Author: Hesham Yasser
 */


#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_private.h"
#include "../Include/MCAL/DIO/DIO_Configurations.h"

void MDIO_voidInit(void)
{
	PORTA_REG = CONC_BIT(PINA7_VAL,PINA6_VAL,PINA5_VAL,PINA4_VAL,PINA3_VAL,PINA2_VAL,PINA1_VAL,PINA0_VAL);
	PORTB_REG = CONC_BIT(PINB7_VAL,PINB6_VAL,PINB5_VAL,PINB4_VAL,PINB3_VAL,PINB2_VAL,PINB1_VAL,PINB0_VAL);
	PORTC_REG = CONC_BIT(PINC7_VAL,PINC6_VAL,PINC5_VAL,PINC4_VAL,PINC3_VAL,PINC2_VAL,PINC1_VAL,PINC0_VAL);
	PORTD_REG = CONC_BIT(PIND7_VAL,PIND6_VAL,PIND5_VAL,PIND4_VAL,PIND3_VAL,PIND2_VAL,PIND1_VAL,PIND0_VAL);
	DDRA_REG = CONC_BIT(PINA7_DIR,PINA6_DIR,PINA5_DIR,PINA4_DIR,PINA3_DIR,PINA2_DIR,PINA1_DIR,PINA0_DIR);
	DDRB_REG = CONC_BIT(PINB7_DIR,PINB6_DIR,PINB5_DIR,PINB4_DIR,PINB3_DIR,PINB2_DIR,PINB1_DIR,PINB0_DIR);
	DDRC_REG = CONC_BIT(PINC7_DIR,PINC6_DIR,PINC5_DIR,PINC4_DIR,PINC3_DIR,PINC2_DIR,PINC1_DIR,PINC0_DIR);
	DDRD_REG = CONC_BIT(PIND7_DIR,PIND6_DIR,PIND5_DIR,PIND4_DIR,PIND3_DIR,PIND2_DIR,PIND1_DIR,PIND0_DIR);
}
tenumErrorStatus MDIO_enuSetPinValue (uint8 uint8PinNumCpy , uint8 uint8PinValCpy)
{
	tenumErrorStatus local_enuFlag = OK;
	if (uint8PinNumCpy >= PINA0 && uint8PinNumCpy <= PIND7)
	{
		switch (uint8PinNumCpy)
		{
		case PINA0 ... PINA7 :
			if (uint8PinValCpy == PIN_HIGH)
			{
				SET_BIT(PORTA_REG , uint8PinNumCpy);
			}
			else if (uint8PinValCpy == PIN_LOW)
			{
				CLR_BIT(PORTA_REG , uint8PinNumCpy);
			}
			else
			{
				local_enuFlag = NOK;
			}
			break;
		case PINB0 ... PINB7 :
			if (uint8PinValCpy == PIN_HIGH)
			{
				SET_BIT(PORTB_REG , (uint8PinNumCpy&THREE_BIT_MASK));
			}
			else if (uint8PinValCpy == PIN_LOW)
			{
				CLR_BIT(PORTB_REG , (uint8PinNumCpy&THREE_BIT_MASK));
			}
			else
			{
				local_enuFlag = NOK;
			}
			break;
		case PINC0 ... PINC7 :
			if (uint8PinValCpy == PIN_HIGH)
			{
				SET_BIT(PORTC_REG , (uint8PinNumCpy&THREE_BIT_MASK));
			}
			else if (uint8PinValCpy == PIN_LOW)
			{
				CLR_BIT(PORTC_REG , (uint8PinNumCpy&THREE_BIT_MASK));
			}
			else
			{
				local_enuFlag = NOK;
			}
			break;
		case PIND0 ... PIND7 :
			if (uint8PinValCpy == PIN_HIGH)
			{
				SET_BIT(PORTD_REG , (uint8PinNumCpy&THREE_BIT_MASK));
			}
			else if (uint8PinValCpy == PIN_LOW)
			{
				CLR_BIT(PORTD_REG , (uint8PinNumCpy&THREE_BIT_MASK));
			}
			else
			{
				local_enuFlag = NOK;
			}
			break;
		}
	}
	else
	{
		local_enuFlag = OUTRANGE;
	}
	return local_enuFlag;
}
tenumErrorStatus MDIO_enuReadPinValue (uint8 uint8PinNumCpy , uint8* puint8PinValReturn)
{
	tenumErrorStatus local_enuFlag = OK;
	if (puint8PinValReturn != NULL)
	{
		switch (uint8PinNumCpy)
		{
		case PINA0 ... PINA7 :
			* puint8PinValReturn = GET_BIT(PINA_REG , uint8PinNumCpy);
			break;
		case PINB0 ... PINB7 :
			* puint8PinValReturn = GET_BIT(PINB_REG , (uint8PinNumCpy&THREE_BIT_MASK));
			break;
		case PINC0 ... PINC7 :
			* puint8PinValReturn = GET_BIT(PINC_REG , (uint8PinNumCpy&THREE_BIT_MASK));
			break;
		case PIND0 ... PIND7 :
			* puint8PinValReturn = GET_BIT(PIND_REG , (uint8PinNumCpy&THREE_BIT_MASK));
			break;
		default :
			local_enuFlag = OUTRANGE;
		}
	}
	else
	{
		local_enuFlag = NOK;
	}
	return local_enuFlag;
}
tenumErrorStatus MDIO_enuSetGroupValue (uint8* puint8Group , uint8* puint8Values , uint8 uint8PinsNumCpy)
{
	tenumErrorStatus local_enuFlag = OK;
	uint8 uint8Iterator_local	= 0;
	for (uint8Iterator_local = 0 ; uint8Iterator_local < uint8PinsNumCpy ; uint8Iterator_local ++)
	{
		local_enuFlag = MDIO_enuSetPinValue(puint8Group[uint8Iterator_local] , puint8Values[uint8Iterator_local]);
		if (local_enuFlag != OK)
		{
			break;
		}
	}
	return local_enuFlag;
}
tenumErrorStatus MDIO_enuPullUpState (uint8 uint8PinNumCpy , uint8 uint8PullUpStateCpy)
{
	tenumErrorStatus local_enuFlag = OK;
	local_enuFlag = MDIO_enuSetPinValue(uint8PinNumCpy , uint8PullUpStateCpy);
	return local_enuFlag;
}
tenumErrorStatus MDIO_enuSetPortValue (uint8 uint8PortCpy , uint8 uint8DataCpy)
{
	tenumErrorStatus local_enuFlag = OK;
	switch (uint8PortCpy)
	{
	case PORTA:
		PORTA_REG = uint8DataCpy;
		break;
	case PORTB:
		PORTB_REG = uint8DataCpy;
		break;
	case PORTC:
		PORTC_REG = uint8DataCpy;
		break;
	case PORTD:
		PORTD_REG = uint8DataCpy;
		break;
	default :
		local_enuFlag = OUTRANGE;
		break;
	}
	return local_enuFlag;
}
