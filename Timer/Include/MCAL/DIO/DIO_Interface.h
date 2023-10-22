/*
 * DIO_Interface.h
 *
 *  Created on: Aug 2, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

typedef enum {
	OK,
	NOK,
	OUTRANGE
}tenumErrorStatus;

/*Pin Numbers:-
	* PINA0 ... PINA7
	* PINB0 ... PINB7
	* PINC0 ... PINC7
	* PIND0 ... PIND7
*/

/*Pin Values :-
 	* PIN_HIGH
 	* PIN_LOW
 */

/*Pin Directions
 	* OUTPUT_PIN
 	* INPUT_PIN
 */

/*PullUp States
 	* PULLUP_ENABLE
 	* PULLUP_DISABLE
 */

/*Ports
 	* PORTA
 	* PORTB
 	* PORTC
 	* PORTD
 */

void MDIO_voidInit(void);
tenumErrorStatus MDIO_enuSetPinValue (uint8 uint8PinNumCpy , uint8 uint8PinValCpy);
tenumErrorStatus MDIO_enuReadPinValue (uint8 uint8PinNumCpy , uint8* puint8PinValReturn);
tenumErrorStatus MDIO_enuSetGroupValue (uint8* puint8Group , uint8* puint8Values , uint8 uint8PinsNumCpy);
tenumErrorStatus MDIO_enuPullUpState (uint8 uint8PinNumCpy , uint8 uint8PullUpStateCpy);
tenumErrorStatus MDIO_enuSetPortValue (uint8 uint8PortCpy , uint8 uint8DataCpy);

//PORTA
#define PINA0		0
#define PINA1		1
#define PINA2		2
#define PINA3		3
#define PINA4		4
#define PINA5		5
#define PINA6		6
#define PINA7		7
//PORTB
#define PINB0		8
#define PINB1		9
#define PINB2		10
#define PINB3		11
#define PINB4		12
#define PINB5		13
#define PINB6		14
#define PINB7		15
//PORTC
#define PINC0		16
#define PINC1		17
#define PINC2		18
#define PINC3		19
#define PINC4		20
#define PINC5		21
#define PINC6		22
#define PINC7		23
//PORTD
#define PIND0		24
#define PIND1		25
#define PIND2		26
#define PIND3		27
#define PIND4		28
#define PIND5		29
#define PIND6		30
#define PIND7		31

//PORTS
#define PORTA		0
#define PORTB		1
#define PORTC		2
#define PORTD		3

//Pin Values
#define PIN_HIGH	1
#define PIN_LOW		0

//Pin Directions
#define OUTPUT_PIN	1
#define INPUT_PIN	0

//PullUp State
#define PULLUP_ENABLE	1
#define PULLUP_DISABLE	0


#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
