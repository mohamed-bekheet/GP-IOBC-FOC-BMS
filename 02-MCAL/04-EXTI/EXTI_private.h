/**************************************************************************************************************/
/* Author  : Mohamed Sedeek                                                                                   */
/* Date    : 5 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/

#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H

#define EXTI_IMR      *((volatile uint32*) 0x40010400)
#define EXTI_EMR      *((volatile uint32*) 0x40010404)
#define EXTI_RTSR     *((volatile uint32*) 0x40010408)
#define EXTI_FTSR     *((volatile uint32*) 0x4001040C)
#define EXTI_SWIER    *((volatile uint32*) 0x40010410)
#define EXTI_PR       *((volatile uint32*) 0x40010414)

#endif