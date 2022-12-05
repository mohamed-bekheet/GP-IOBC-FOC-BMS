/**************************************************************************************************************/
/* Author  : Mohamed Sedeek                                                                                   */
/* Date    : 5 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/

#ifndef _EXTI_INTERFACE_H
#define _EXTI_INTERFACE_H

typedef enum {
	EXTI_PIN0=0,
	EXTI_PIN1,
	EXTI_PIN2,
	EXTI_PIN3,
	EXTI_PIN4,
	EXTI_PIN5,
	EXTI_PIN6,
	EXTI_PIN7,
	EXTI_PIN8,
	EXTI_PIN9,
	EXTI_PIN10,
	EXTI_PIN11,
	EXTI_PIN12,
	EXTI_PIN13,
	EXTI_PIN4,
	EXTI_PIN15,
}interrupt_pin_t

typedef enum {
	RISING=0,
	FALLING,
	CHANGE,
}trigger_t

typedef struct {
	u8 pin      :4;
	u8 trigger  :2;
	u8 error    :1;
	u8 reserved :1;
}exti_t

void EXTI_enable(exti_t* exti);
void EXTI_disable(exti_t* exti);
void EXTI_generateSoftwareInterrupt(exti_t* exti);

#endif