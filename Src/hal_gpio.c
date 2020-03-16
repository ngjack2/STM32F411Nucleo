/*
 * hal_gpio.c
 *
 *  Created on: 2 Mar 2020
 *      Author: yaphan.ng
 */
#include "systemTypes.h"
#include "asic.h"
#include "hal_gpio.h"

/**
 * Initialize all ports
 *
 */
__externC void hal_gpio_init(void)
{
	// Initialize the port A
	hal_gpioA_init();

	// Initialize the port C
	hal_gpioC_init();

}

/**
 * Initialize the portA pin 5 as output
 *
 */
__externC void hal_gpioA_init(void)
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
 * Initialize the portC pin 5 as input
 *
 */
__externC void hal_gpioC_init(void)
{
	// Enable GPIO C
	sRCC->RCC_AHB1ENR.bits.GPIOCEN = 1;

	// Change the mode of GPIO C
	sGPIOC->GPIOx_MODER.bits.MODER13 = 0;
	sGPIOC->GPIOx_MODER.bits.MODER9  = 2;

	// Change the output type to push-pull state GPIO C
	sGPIOC->GPIOx_OTYPER.bits.OT13 = 0;
	sGPIOC->GPIOx_OTYPER.bits.OT9  = 0;

	// Change the output speed to low
	sGPIOC->GPIOx_OSPEEDR.bits.OSPEEDR13 = 0x01;
	sGPIOC->GPIOx_OSPEEDR.bits.OSPEEDR9  = 0x03;

	// Change the GPIOA-5 to pull-up
	sGPIOC->GPIOx_PUPDR.bits.PUPDR13 = 0x02;
	sGPIOC->GPIOx_PUPDR.bits.PUPDR9  = 0x01;
}

/**
 * Toggle GPIO Port A pin 5
 *
 */
__externC void hal_gpioA_pin5_toggle(void)
{
	sGPIOA->GPIOx_ODR.bits.ODR5 ^= 1;
}

/**
 * Get value from port C pin 13
 *
 */
__externC UINT32 hal_get_gpioC_pin13(void)
{
	return (sGPIOC->GPIOx_IDR.bits.IDR13);
}

