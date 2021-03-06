/*
* delay.c - Auxiliary library to use time delays 
* NOTE: Please also check the comments in delay.h - they provide useful hints
* and background information.
*/
#include "delay.h"

void SysTick_Init(void) {

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ);
}

void delay_ms(uint32_t delayTime) {
	sysTickCounter = delayTime;
	while (sysTickCounter > 0) {
		// kill clocks
	}
}

void SysTick_Handler(void) {
	if (sysTickCounter > 0) {
		sysTickCounter--;
	}
}
