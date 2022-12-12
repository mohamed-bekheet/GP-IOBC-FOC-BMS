/**************************************************************************************************************/
/* Author  : Khaled Essam                                                                                   */
/* Date    : 11 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/

#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_

/************************includes*****************************/
#include "../../01-LIB/STD_TYPES.h"
#include "TIM1_config.h"
/**************************macros******************************/
#define TIM1_UPCOUNT   0b0
#define TIM1_DOWNCOUNT 0b1

#define TIM1_EDGE_ALIGNED_MODE      0b00
#define TIM1_CENTER_ALIGNED_MODE_1  0b01
#define TIM1_CENTER_ALIGNED_MODE_2  0b10
#define TIM1_CENTER_ALIGNED_MODE_3  0b11

#define TIM1_UEI_ENABLE  1
#define TIM1_UEI_DISABLE 0




typedef struct
{
	uint8 DIR : 1;
	uint8 UDIS :1;
	uint8 center_aligned_mode:2;
	uint16 preload_value;
	uint16 prescaler;
	uint8 error :1;
}tim1_timer_cfg_t;

void TIM1_Init(tim1_timer_cfg_t*);




#endif /* TIM1_INTERFACE_H_ */
