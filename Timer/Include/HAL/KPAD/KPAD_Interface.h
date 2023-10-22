/*
 * KPAD_Interface.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_HAL_KPAD_KPAD_INTERFACE_H_
#define INCLUDE_HAL_KPAD_KPAD_INTERFACE_H_

void HKPAD_voidInit(void);
uint8 KPAD_uint8GetPressedKey(void);

#define KPAD_NOTPRESSED		0xff

#endif /* INCLUDE_HAL_KPAD_KPAD_INTERFACE_H_ */
