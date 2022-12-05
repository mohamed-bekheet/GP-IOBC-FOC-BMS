/**************************************************************************************************************/
/* Author  : Mohamed Sedeek                                                                                   */
/* Date    : 2 Dec 2022                                                                                       */
/* Version : 02                                                                                               */
/**************************************************************************************************************/
#include <STD_TYPES.h>
#include <BIT_MATH.h>
#include <NVIC_interface.h>
#include <NVIC_private.h>
#include <NVIC_config.h>

void interruptEnable(interrupt_t* interrupt) {
	if (interrupt && interrupt->number <= 31) {
		NVIC_ISER0 = 1<< interrupt->number;
	}
	else if (interrupt && interrupt->number <=59) {
		NVIC_ISER1 = 1<< (interrupt->number-32);
	}
	else {
		interrupt->error=1;
	}
}

void interruptDisable(interrupt_t* interrupt) {
	if (interrupt && interrupt->number <= 31) {
		NVIC_ICER0 = 1<< interrupt->number;
	}
	else if (interrupt && interrupt->number <=59) {
		NVIC_ICER1 = 1<< (interrupt->number-32);
	}
	else {
		interrupt->error=1;
	}
}

void interruptSetPending(interrupt_t* interrupt) {
	if (interrupt && interrupt->number <= 31) {
		NVIC_ISPP0 = 1<< interrupt->number;
	}
	else if (interrupt && interrupt->number <=59) {
		NVIC_ISPP1 = 1<< (interrupt->number-32);
	}
	else {
		interrupt->error=1;
	}
}

void interruptClearPending(interrupt_t* interrupt) {
	if (interrupt && interrupt->number <= 31) {
		NVIC_ICPP0 = 1<< interrupt->number;
	}
	else if (interrupt && interrupt->number <=59) {
		NVIC_ICPP1 = 1<< (interrupt->number-32);
	}
	else {
		interrupt->error=1;
	}
}

void interruptIsActive(interrupt_t* interrupt) {
	if (interrupt && interrupt->number <= 31) {
		interrupt->active = GET_BIT(NVIC_IABR0,interrupt->number);
	}
	else if (interrupt && interrupt->number <=59) {
		interrupt->active = GET_BIT(NVIC_IABR1,interrupt->number-32);
	}
	else {
		interrupt->error=1;
	}
}

void initInterruptPriority(void){
	SCB_AIRCR= INTERRUPT_PRIORITY_GROUP;
}

void setInterruptPriority(interrupt_t* interrupt){
	if (interrupt && interrupt->number >=0) {
		u8 localPriority = (interrupt->subPriority | interrupt->groupPriority<<(INTERRUPT_PRIORITY_GROUP-PRIORITY_GROUP1)/256)<<4;
		*(NVIC_IPR + interrupt->number)= localPriority;
	}	
}

void setSoftwareInterrupt(interrupt_t* interrupt){
	NVIC_STIR = interrupt->number;
}