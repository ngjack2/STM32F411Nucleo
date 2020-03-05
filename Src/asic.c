/*
 * asic.c
 *
 *  Created on: Feb 28, 2020
 *      Author: yaphan.ng
 */

#include "asic.h"

//
// for TIMx
//
#define TIM2_BASE_ADDR 0x40000000UL

volatile tTIMx* sTIM2  = (volatile tTIMx*)(TIM2_BASE_ADDR);
volatile tTIMx* sTIM3  = (volatile tTIMx*)(TIM2_BASE_ADDR + 0x400UL);
volatile tTIMx* sTIM4  = (volatile tTIMx*)(TIM2_BASE_ADDR + 0x800UL);
volatile tTIMx* sTIM5  = (volatile tTIMx*)(TIM2_BASE_ADDR + 0xC00UL);

//
// for GPIOx
//
#define GPIO_BASE_ADDR 0x40020000UL

volatile tGPIO* sGPIOA = (volatile tGPIO*)(GPIO_BASE_ADDR);
volatile tGPIO* sGPIOB = (volatile tGPIO*)(GPIO_BASE_ADDR + 0x400);

//
// for RCC
//
#define RCC_BASE_ADDR 0x40023800UL

volatile tRCC*  sRCC   = (volatile tRCC*) RCC_BASE_ADDR;


