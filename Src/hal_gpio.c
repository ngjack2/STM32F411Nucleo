/*
 * hal_gpio.c
 *
 *  Created on: 2 Mar 2020
 *      Author: yaphan.ng
 */
#include "systemTypes.h"
#include "asic.h"

/**
 * Initialize the portA pin 5 as output
 *
 */
void hal_gpioA_init(void)
{
	// Enable GPIO A
	sRCC->RCC_AHB1ENR.bits.GPIOAEN = 1;

	// Change the mode of GPIOA
	sGPIOA->GPIOx_MODER.bits.MODER5 = 0x01;

	// Change the output type to push-pull state GPIOA
	sGPIOA->GPIOx_OTYPER.bits.OT15 = 0;

	// Change the output speed to low
	sGPIOA->GPIOx_OSPEEDR.bits.OSPEEDR5 = 0x01;

	// Change the GPIOA-5 to pull-up
	sGPIOA->GPIOx_PUPDR.bits.PUPDR5 = 0x01;
}

/**
 * Toggle GPIO Port A pin 5
 *
 */
void hal_gpioA_pin5_toggle(void)
{
	sGPIOA->GPIOx_ODR.bits.ODR5 ^= 1;
}
