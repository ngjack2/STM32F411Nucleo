/*
 * hal_gpio.h
 *
 *  Created on: 2 Mar 2020
 *      Author: yaphan.ng
 */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

extern void hal_gpio_init(void);
extern void hal_gpioA_init(void);
extern void hal_gpioC_init(void);
extern void hal_gpioA_pin5_toggle(void);
extern void hal_gpioA_pin13_toggle(void);

extern UINT32 hal_get_gpioC_pin13(void);

#endif /* HAL_GPIO_H_ */
