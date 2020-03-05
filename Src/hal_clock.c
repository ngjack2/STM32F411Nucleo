/*
 * hal_clock.c
 *
 *  Created on: 3 Mar 2020
 *      Author: yaphan.ng
 */
#include "systemTypes.h"
#include "asic.h"
#include "hal_clock.h"

//
// Setup PLL to 100MHz
//
struct sPllParam sPll100MHzParam =
{
	0,   // source for PLL
	200, // N scale
	16,  // M scale
	2,   // P scale
};

/**
 * Initialize the M4 to clock 100MHz
 *
 */
void hal_clock_init(void)
{
	// Select HSI as PLL and PLLI2S as clock input
	sRCC->RCC_PLLCFGR.bits.PLLSRC = sPll100MHzParam.PLLSRC;

	// N-scale multiplication
	sRCC->RCC_PLLCFGR.bits.PLLN   = sPll100MHzParam.PLLN;

	// PLL clock input scale for HSI
	sRCC->RCC_PLLCFGR.bits.PLLM   = sPll100MHzParam.PLLM;

	// M-scale division of main PLL
	sRCC->RCC_PLLCFGR.bits.PLLP   = sPll100MHzParam.PLLP;

	// Turn on the PLL
	sRCC->RCC_CR.bits.PLLON = 1;

	// Wait for PLL to be lock
	while(!sRCC->RCC_CR.bits.PLLRDY);

	// Switch to PLL clock source
	sRCC->RCC_CFGR.bits.SW0 = 0;
	sRCC->RCC_CFGR.bits.SW1 = 1;

	// Set prescale for APB1 clock divide by 2
	sRCC->RCC_CFGR.bits.PPRE1 = 0x4;

	// Set prescale for APB2 clock divide by 1
	sRCC->RCC_CFGR.bits.PPRE2 = 0;

	// Set prescale for AHB clock divide by 1
	sRCC->RCC_CFGR.bits.HPRE = 0;

}

