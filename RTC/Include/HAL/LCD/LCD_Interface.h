/*
 * LCD_Interface.h
 *
 *  Created on: Aug 6, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_

void HLCD_voidInit (void);
void HLCD_voidSendData (uint8 A_uint8LCDIndex ,uint8 A_uint8Data);
void HLCD_voidSendCommand (uint8 A_uint8LCDIndex , uint8 A_uint8Command);
void HLCD_voidGoTo (uint8 A_uint8LCDIndex , uint8 A_uint8Row , uint8 A_uint8Col);
void HLCD_voidSendString (uint8 A_uint8LCDIndex , uint8* A_puint8Str);
void HLCD_voidSendOneNumber (uint8 A_uint8LCDIndex , uint8 A_uint8Number);
void HLCD_voidSendNumbers (uint8 A_uint8LCDIndex , sint32 A_sint32Number);
void LCD_voidClearDisplay(uint8 A_uint8LCDIndex);
void LCD_voidDisplayHex(uint8 A_uint8LCDIndex);
#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
