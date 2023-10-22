/*
 * BIT_MATH.h
 *
 *  Created on: Aug 2, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_LIB_BIT_MATH_H_
#define INCLUDE_LIB_BIT_MATH_H_

#define SET_BIT(Reg , Bit)		(Reg |=  (1<<Bit))
#define CLR_BIT(Reg , Bit)		(Reg &= ~(1<<Bit))
#define TGL_BIT(Reg , Bit)		(Reg ^=  (1<<Bit))
#define GET_BIT(Reg , Bit)		((Reg >> Bit) & 1)
#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0)  Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif /* INCLUDE_LIB_BIT_MATH_H_ */
