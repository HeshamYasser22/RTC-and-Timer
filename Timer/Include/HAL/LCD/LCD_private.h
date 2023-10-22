/*
 * LCD_private.h
 *
 *  Created on: Aug 6, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_HAL_LCD_LCD_PRIVATE_H_
#define INCLUDE_HAL_LCD_LCD_PRIVATE_H_
#define FOUR_BIT		0
#define EIGHT_BIT		1
#define ON				1
#define OFF				0
#define TWOLINES		1
#define ONELINE			0
#define FIVEBYTEN		1
#define FIVEBYSEVEN		0
#define CLEAR_DISPLAY	1

typedef struct {
	uint8 LCD_auint8Pins[8];
	uint8 LCD_uint8RS;
	uint8 LCD_uint8RW;
	uint8 LCD_uint8EN;
	uint8 LCD_uint8Mode;
	uint8 LCD_uint8LinesNumber 	: 1;
	uint8 LCD_uint8BlinkMode	: 1;
	uint8 LCD_uint8CursorMode	: 1;
	uint8 LCD_uint8IncrementMode: 1;
	uint8 LCD_uint8ShiftMode	: 1;
	uint8 LCD_uint8FontSize		: 1;

}tstrLCDConfig;
#endif /* INCLUDE_HAL_LCD_LCD_PRIVATE_H_ */
