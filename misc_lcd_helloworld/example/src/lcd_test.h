/*
 * lcd_test.h
 *
 *  Created on: 1 de set de 2016
 *      Author: luisfg30
 */

#ifndef SRC_LCD_TEST_H_
#define SRC_LCD_TEST_H_

#include "board.h"
#include "lcd_st7565s.h"
#include "lpc_rom8x8.h"


/**
 * @Brief show a message for each situation
 * @param a- action code
 *	0 -User already registered
 *	1 -Insufficient balance
 *	2 -OK, enough balance
 *	3 -User check out ok
 *	4 -User check out with negative balance
 */
void action(int a);

#endif /* SRC_LCD_TEST_H_ */
