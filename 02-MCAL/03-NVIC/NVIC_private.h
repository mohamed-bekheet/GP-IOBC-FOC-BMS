/**************************************************************************************************************/
/* Author  : Mohamed Sedeek                                                                                   */
/* Date    : 2 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/

#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H

#define NVIC_ISER0       *((volatile uint32*) 0xE000E100)
#define NVIC_ISER1       *((volatile uint32*) 0xE000E104)

#define NVIC_ICER0       *((volatile uint32*) 0xE000E180)
#define NVIC_ICER1       *((volatile uint32*) 0xE000E184)

#define NVIC_ISPR0       *((volatile uint32*) 0xE000E200)
#define NVIC_ISPR1       *((volatile uint32*) 0xE000E204)

#define NVIC_ICPR0       *((volatile uint32*) 0xE000E280)
#define NVIC_ICPR1       *((volatile uint32*) 0xE000E284)

#define NVIC_IABR0       *((volatile uint32*) 0xE000E300)
#define NVIC_IABR0       *((volatile uint32*) 0xE000E304)

#endif