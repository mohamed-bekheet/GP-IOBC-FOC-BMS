/**************************************************************************************************************/
/* Author  : Mohamed Sedeek                                                                                   */
/* Date    : 5 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/

#ifndef _AFIO_INTERFACE_H
#define _AFIO_INTERFACE_H

typedef enum {
	EXTI_PORTA=0,
	EXTI_PORTB,
	EXTI_PORTC,
}interrupt_port_t;

sint8 AFIO_EXTI_selectPort(uint8 copyPin, uint8 copyPort);

#endif
