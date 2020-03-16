/*
 * hal_timer.c
 *
 *  Created on: 4 Mar 2020
 *      Author: yaphan.ng
 */
#include "systemTypes.h"
#include "asic.h"
#include "hal_timer.h"


/**
 * Initialize all the necessary timer
 *
 */
__externC void hal_timer_init(void)
{
	hal_timer2_init();
}

/**
 * Create a general counter with 1 tick is 1us
 *
 */
__externC void hal_timer2_init(void)
{
	// Enable timer 2
	sRCC->RCC_APB1ENR.bits.TIM2EN = 1;

	// Load 0 into auto reload register
	sTIM2->TIMx_ARR.all32 = 0;

	//
	sTIM2->TIMx_CNT.all32 = 0;

	// divide 50 for current clk speed
	sTIM2->TIMx_PSC.all32 = 0;

	// Timer counter enable
	sTIM2->TIMx_CR1.bits.CEN = 1;

}

/**
 * Get free running timer2 counter value
 *
 */
__externC UINT32 hal_get_timer2_counter(void)
{

	UINT32 value = sTIM2->TIMx_CNT.all32;

	return (value);
}

/**
 * Function that delay 1 us
 *
 */
__externC UINT32 hal_delay_us(UINT32 value)
{
	UINT32 startTime = hal_get_timer2_counter();

	return ((startTime - hal_get_timer2_counter()) <= value);
}

