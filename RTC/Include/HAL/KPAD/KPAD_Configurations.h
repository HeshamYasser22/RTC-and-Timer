/*
 * KPAD_Configurations.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Hesham Yasser
 */

#ifndef INCLUDE_HAL_KPAD_KPAD_CONFIGURATIONS_H_
#define INCLUDE_HAL_KPAD_KPAD_CONFIGURATIONS_H_

#define KPAD_KEYS		{{'7' , '8' , '9' , '/'},\
						 {'4' , '5' , '6' , '*'},\
						 {'1' , '2' , '3' , '-'},\
						 {'C' , '0' , '.' , '+'},\
						}
#define KPAD_COL_NUM		4
#define KPAD_ROW_NUM		4

#define KPAD_COLS_PINS			{PINA0 , PINA1 , PINA2 , PINA3}				//	Configure As Input
#define KPAD_ROWS_PINS			{PINA4 , PINA5 , PINA6 , PINA7}				//	Configure As Output


#endif /* INCLUDE_HAL_KPAD_KPAD_CONFIGURATIONS_H_ */
