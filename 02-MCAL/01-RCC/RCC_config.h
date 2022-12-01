/***************************************************************/
/* Author:Khaled Essam                                         */
/* Date : 04/11/2022                                           */
/* Version : V01                                               */
/***************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H
#include "RCC_private.h"

/*
 RCC_HSE_CRYSTAL 
 RCC_HSE_RC      
 RCC_HSI         
 RCC_PLL         
*/
#define RCC_CLOCK_TYPE RCC_HSI



/*Config onlyif you select RCC_PLL*/
#if RCC_CLOCK_TYPE==RCC_PLL
/*
 RCC_HSE_DIV_2 
 RCC_HSE       
 RCC_HSI_DIV_2 
*/
#define PLL_CONFIG RCC_HSE_DIV_2



/*
 RCC_PLL_MUL_x  //where x (2--->16)
*/
#define RCC_PLL_MUL RCC_PLL_MUL_2



#endif


#endif
