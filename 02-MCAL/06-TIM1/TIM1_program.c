/**************************************************************************************************************/
/* Author  : Khaled Essam                                                                                   */
/* Date    : 11 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/


#ifndef TIM1_PROGRAM_H_
#define TIM1_PROGRAM_H_

/*Includes*/
#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"
#include "TIM1_interface.h"
#include "TIM1_private.h"
#include "TIM1_config.h"

void TIM1_Init(tim1_timer_cfg_t* TIM1)
{
	if (TIM1)
	{
		/*config the direction */
		switch(TIM1->DIR)
		{
			case TIM1_UPCOUNT  :CLR_BIT(TIM1_CR1,4);break;
			case TIM1_DOWNCOUNT:SET_BIT(TIM1_CR1,4);break;
		}
		/*choose the operation mode neglect dir if TIM1_CENTER_ALIGNED_MODE_X is chosen*/
		switch(TIM1->center_aligned_mode)
		{
			case TIM1_EDGE_ALIGNED_MODE  :  CLR_BIT(TIM1_CR1,5);CLR_BIT(TIM1_CR1,6);break;
			case TIM1_CENTER_ALIGNED_MODE_1:SET_BIT(TIM1_CR1,5);CLR_BIT(TIM1_CR1,6);break;
			case TIM1_CENTER_ALIGNED_MODE_2:CLR_BIT(TIM1_CR1,5);SET_BIT(TIM1_CR1,6);break;
			case TIM1_CENTER_ALIGNED_MODE_3:SET_BIT(TIM1_CR1,5);SET_BIT(TIM1_CR1,6);break;
			default : TIM1->error=1;
		}
		/*update enable interrupt */
		switch(TIM1->UDIS)
		{
			case TIM1_UEI_ENABLE  : CLR_BIT(TIM1_CR1,1);break;
			case TIM1_UEI_DISABLE : SET_BIT(TIM1_CR1,1);break;
		}
		/*loading preload value*/
		TIM1_ARR=TIM1->preload_value;
		/*choose prescaler*/
		TIM1_PSC=TIM1->prescaler;
		/*enable timer*/
		SET_BIT(TIM1_CR1,4);
	}
	else
	{
		TIM1->error=1;
	}
}


#endif /* TIM1_PROGRAM_H_ */
