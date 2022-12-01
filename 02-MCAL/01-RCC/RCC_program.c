/***************************************************************/
/* Author:Khaled Essam                                         */
/* Date : 04/11/2022                                           */
/* Version : V01                                               */
/***************************************************************/

/*Includes*/
#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_InitClock()
{
	RCC_CFGR=0x00000000; //no devision and hsi is system clock
	#if    RCC_CLOCK_TYPE==RCC_HSI
	/*enable HSI with and trim value is 16*/
	RCC_CR = 0x00000081; 
	//RCC_CFGR=0x00000000;
	#elif  RCC_CLOCK_TYPE==RCC_HSE_CRYSTAL
	/*enable HSE and HSE is not bypassed*/
	RCC_CR = 0x00010000;
	//RCC_CFGR=0x00000000;
	#elif  RCC_CLOCK_TYPE==RCC_HSE_RC
	/*enable HSE and HSE is bypassed*/
	RCC_CR = 0x00050000;
	//RCC_CFGR=0x00000000;
	#elif RCC_CLOCK_TYPE==RCC_PLL
	#if PLL_CONFIG==RCC_HSE_DIV_2
	SET_BIT(RCC_CFGR,16);
	SET_BIT(RCC_CFGR,17);
	#elif PLL_CONFIG==RCC_HSE
	SET_BIT(RCC_CFGR,16);
	CLR_BIT(RCC_CFGR,17);
	#elif PLL_CONFIG==RCC_HSI_DIV_2
	CLR_BIT(RCC_CFGR,16);
	#endif
	RCC_CFGR |= ((RCC_PLL_MUL&1)<<18);
	RCC_CFGR |= ((RCC_PLL_MUL&2)<<19);
	RCC_CFGR |= ((RCC_PLL_MUL&4)<<20);
	RCC_CFGR |= ((RCC_PLL_MUL&8)<<21);
	SET_BIT(RCC_CR,24);  //enable PLL
	#else  #error("Wrong Clock Type")
	#endif
}



void RCC_EnablePeriphClock(rcc_cfg_t* rcc)
{
	if(rcc)
	{
		if(rcc->peripheral_id >= 31)
		{
			switch(rcc->peripheral_id)
			{
				case RCC_AHB:  SET_BIT(RCC_AHBENR,rcc->peripheral_id) ; break;
				case RCC_APB1: SET_BIT(RCC_APB1ENR,rcc->peripheral_id); break;
				case RCC_APB2: SET_BIT(RCC_APB2ENR,rcc->peripheral_id); break;
				default: rcc -> error=1; break;
			}
		}
		else 
		{
			/* return error */
			rcc -> error=1;
		}
	}
	else
	{
		/* return error */
		rcc -> error=1;	
	}	
}

void RCC_DisablePeriphClock(rcc_cfg_t* rcc)
{
	if(rcc)
	{
		if(rcc->peripheral_id >= 31)
		{
			switch(rcc->peripheral_id)
			{
				case RCC_AHB:  CLR_BIT(RCC_AHBENR,rcc->peripheral_id);  break;
				case RCC_APB1: CLR_BIT(RCC_APB1ENR,rcc->peripheral_id); break;
				case RCC_APB2: CLR_BIT(RCC_APB2ENR,rcc->peripheral_id); break;
				default: rcc -> error=1; break;
			}
		}
		else 
		{
			/* return error */
			rcc -> error=1;
		}
	}
	else
	{
		/* return error */
		rcc -> error=1;	
	}	
}
