/*
 * KPAD_Configurations.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_HAL_KPAD_KPAD_CONFIGURATIONS_H_
#define INCLUDE_HAL_KPAD_KPAD_CONFIGURATIONS_H_

#define KPAD_KEYS		{{'7' , 'U' , '9' , '/'},\
						 {'L' , 'S' , 'R' , '*'},\
						 {'1' , 'D' , '3' , '-'},\
						 {'C' , '0' , '.' , '+'},\
						}
#define KPAD_COL_NUM		4
#define KPAD_ROW_NUM		4

#define KPAD_COLS_PINS			{PIND3 , PIND2 , PIND1 , PIND0}				//	Configure As Input
#define KPAD_ROWS_PINS			{PIND4 , PIND5 , PIND6 , PIND7}				//	Configure As Output


#endif /* INCLUDE_HAL_KPAD_KPAD_CONFIGURATIONS_H_ */
