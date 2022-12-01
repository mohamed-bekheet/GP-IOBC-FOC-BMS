/***************************************************************/
/* Author:Khaled Essam                                         */
/* Date : 04/11/2022                                           */
/* Version : V01                                               */
/***************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/************************includes*****************************/
#include "../../01-LIB/STD_TYPES.h"
#include "RCC_config.h"
/**************************macros******************************/
#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2

#define RCC_TIM1_CLK_ENABLE   11
#define RCC_TIM2_CLK_ENABLE   0
#define RCC_TIM3_CLK_ENABLE   1
#define RCC_TIM4_CLK_ENABLE   2
#define RCC_TIM5_CLK_ENABLE   3
#define RCC_TIM6_CLK_ENABLE   4
#define RCC_TIM7_CLK_ENABLE   5
#define RCC_TIM8_CLK_ENABLE   13
#define RCC_TIM9_CLK_ENABLE   19
#define RCC_TIM10_CLK_ENABLE  20
#define RCC_TIM11_CLK_ENABLE  21
#define RCC_TIM12_CLK_ENABLE  6
#define RCC_TIM13_CLK_ENABLE  7
#define RCC_TIM14_CLK_ENABLE  8
#define RCC_ADC1_CLK_ENABLE   9
#define RCC_ADC2_CLK_ENABLE   10
#define RCC_ADC3_CLK_ENABLE   11
#define RCC_USART1_CLK_ENABLE 14
#define RCC_USART2_CLK_ENABLE 17
#define RCC_USART3_CLK_ENABLE 18
#define RCC_USART4_CLK_ENABLE 19
#define RCC_USART5_CLK_ENABLE 20
#define RCC_SPI1_CLK_ENABLE   12
#define RCC_SPI2_CLK_ENABLE   14
#define RCC_SPI3_CLK_ENABLE   15
#define RCC_I2C1_CLK_ENABLE   21
#define RCC_I2C2_CLK_ENABLE   22
#define RCC_IOPA_CLK_ENABLE   2
#define RCC_IOPB_CLK_ENABLE   3
#define RCC_IOPC_CLK_ENABLE   4
#define RCC_IOPD_CLK_ENABLE   5
#define RCC_IOPE_CLK_ENABLE   6
#define RCC_IOPF_CLK_ENABLE   7
#define RCC_IOPG_CLK_ENABLE   8





/************************data types***************************/
typedef struct 
{
    uint8 bus_id        : 2;
    uint8 peripheral_id : 5;
    uint8 error         : 1;
}rcc_cfg_t; 

/**************************APIs*****************************/
void RCC_InitClock();
void RCC_EnablePeriphClock (rcc_cfg_t* rcc);
void RCC_DisablePeriphClock(rcc_cfg_t* rcc);


#endif
