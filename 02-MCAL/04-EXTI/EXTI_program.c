/**************************************************************************************************************/
/* Author  : Mohamed Sedeek                                                                                   */
/* Date    : 5 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/

#include <STD_TYPES.h>
#include <BIT_MATH.h>
#include <EXTI_interface.h>
#include <EXTI_private.h>
#include <EXTI_config.h>

void EXTI_enable(exti_t* exti){
	if (exti && exti->pin<=INTERRUPT_PIN_15 && exti->trigger<=CHANGE) {
		SET_BIT(EXTI_IMR,exti->pin);
		switch(exti->trigger) {
			case RISING:
				SET_BIT(EXTI_RTSR,exti->pin);
				break;
			case FALLING:
				SET_BIT(EXTI_FTSR,exti->pin);
				break;
			case CHANGE:
				SET_BIT(EXTI_RTSR,exti->pin);
				SET_BIT(EXTI_FTSR,exti->pin);
				break;
			default:
				break;
		}
	}
	else {
		exti->error=1;
	}
}

void EXTI_disable(exti_t* exti){
	if (exti && exti->pin<=INTERRUPT_PIN_15 && exti->trigger<=CHANGE) {
		CLR_BIT(EXTI_IMR,exti->pin);
	}
	else {
		exti->error=1;
	}
}

void EXTI_generateSoftwareInterrupt(exti_t* exti){
	if (exti && exti->pin<=INTERRUPT_PIN_15 && exti->trigger<=CHANGE) {
		SET_BIT(EXTI_SWIER,exti->pin);
	}
	else {
		exti->error=1;
	}
	
}
