/*
 * hal_timer.h
 *
 *  Created on: Mar 5, 2020
 *      Author: yaphan.ng
 */

#ifndef HAL_TIMER_H_
#define HAL_TIMER_H_


__externC void hal_timer_init(void);
__externC void hal_timer2_init(void);

__externC UINT32 hal_delay_us(UINT32 value);

#endif /* HAL_TIMER_H_ */
