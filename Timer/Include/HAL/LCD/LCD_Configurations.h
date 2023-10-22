/*
 * LCD_Configurations.h
 *
 *  Created on: Aug 6, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_HAL_LCD_LCD_CONFIGURATIONS_H_
#define INCLUDE_HAL_LCD_LCD_CONFIGURATIONS_H_

#define LCD_NUMBER		1
/*
#define LCD_DATA_PORT		PORTA
#define LCD_EN_PIN			PINB0
#define LCD_RW_PIN			PINB1
#define LCD_RS_PIN			PINB2

#define LCD_MODE			EIGHT_BIT

#define BLINK_MODE			ON
#define CURSOR_MODE			ON
#define INCREMENT_MODE		ON
#define SHIFT_MODE			OFF
#define LINESNUMBER			TWOLINES
#define FONTSIZE			FIVEBYTEN
*/
#define LCD1_PINS			{PINA0 , PINA1 , PINA2 , PINA3 , PINA4 , PINA5 , PINA6 , PINA7}
#define LCD2_PINS			{PINC0 , PINC1 , PINC2 , PINC3}
#endif /* INCLUDE_HAL_LCD_LCD_CONFIGURATIONS_H_ */
