/*
 * STD_TYPES.h
 *
 *  Created on: Aug 2, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_LIB_STD_TYPES_H_
#define INCLUDE_LIB_STD_TYPES_H_

typedef unsigned char 		uint8;
typedef char 				sint8;
typedef unsigned long int 	uint32;
typedef long int 			sint32;
typedef unsigned short int 	uint16;
typedef short int 			sint16;
typedef float 				float32;
typedef long double 		float64;

typedef void (* PtrToFunc_void) (void);
#define NULL				(void * )0

#endif /* INCLUDE_LIB_STD_TYPES_H_ */
