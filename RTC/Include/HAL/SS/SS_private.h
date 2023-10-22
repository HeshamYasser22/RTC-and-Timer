/*
 * SS_private.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_HAL_SS_SS_PRIVATE_H_
#define INCLUDE_HAL_SS_SS_PRIVATE_H_

#define PINS_NUMBER			7

typedef struct {
	uint8 SS_Pins[PINS_NUMBER];
	uint8 SS_CommonMode;
	uint8 SS_CommonPin;
}SS_Config;


#define SS_COMMON_ANODE				1
#define SS_COMMON_CATHODE			0

#define SS_NUMBERS_ARRAY			{0x3F , 0x06 , 0x5B , 0x4F , 0x66 , 0x6D , 0x7D , 0x07 , 0x7F , 0x6F};


#endif /* INCLUDE_HAL_SS_SS_PRIVATE_H_ */
