/***************************************************************/
/* Author:Khaled Essam                                         */
/* Date : 04/11/2022                                           */
/* Version : V01                                               */
/***************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*Register Definition*/
#define RCC_CR         *((volatile uint32*)(0x40021000))
#define RCC_CFGR       *((volatile uint32*)(0x40021004))
#define RCC_CIR        *((volatile uint32*)(0x40021008))
#define RCC_APB2RSTR   *((volatile uint32*)(0x4002100C))
#define RCC_APB1RSTR   *((volatile uint32*)(0x40021010))
#define RCC_AHBENR     *((volatile uint32*)(0x40021014))
#define RCC_APB2ENR    *((volatile uint32*)(0x40021018))
#define RCC_APB1ENR    *((volatile uint32*)(0x4002101C))
#define RCC_BDCR       *((volatile uint32*)(0x40021020))
#define RCC_CSR        *((volatile uint32*)(0x40021024))

/*Clock Source Types*/
#define RCC_HSE_CRYSTAL 0
#define RCC_HSE_RC      1
#define RCC_HSI         2
#define RCC_PLL         3

/*PLL configuration*/
#define RCC_HSE_DIV_2 0
#define RCC_HSE       1
#define RCC_HSI_DIV_2 2 

typedef enum
{
    RCC_PLL_MUL_2,
    RCC_PLL_MUL_3,
    RCC_PLL_MUL_4,
    RCC_PLL_MUL_5,
    RCC_PLL_MUL_6,
    RCC_PLL_MUL_7,
    RCC_PLL_MUL_8,
    RCC_PLL_MUL_9,
    RCC_PLL_MUL_10,
    RCC_PLL_MUL_11,
    RCC_PLL_MUL_12,
    RCC_PLL_MUL_13,
    RCC_PLL_MUL_14,
    RCC_PLL_MUL_15,
    RCC_PLL_MUL_16,
}rcc_mul_t;
#endif
