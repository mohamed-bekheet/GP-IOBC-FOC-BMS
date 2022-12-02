/**************************************************************************************************************/
/* Author  : Mohamed Sedeek                                                                                   */
/* Date    : 2 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/

void interruptEnable(interrupt_t* interrupt) {
	if (interrupt->number <= 31) {
		NVIC_ISER0 = 1<< interrupt->number;
	}
	else if (interrupt->number <=59) {
		NVIC_ISER1 = 1<< (interrupt->number-32);
	}
	else {
		interrupt->error=1;
	}
}

void interruptDisable(interrupt_t* interrupt) {
	if (interrupt->number <= 31) {
		NVIC_ICER0 = 1<< interrupt->number;
	}
	else if (interrupt->number <=59) {
		NVIC_ICER1 = 1<< (interrupt->number-32);
	}
	else {
		interrupt->error=1;
	}
}

void interruptSetPending(interrupt_t* interrupt) {
	if (interrupt->number <= 31) {
		NVIC_ISPP0 = 1<< interrupt->number;
	}
	else if (interrupt->number <=59) {
		NVIC_ISPP1 = 1<< (interrupt->number-32);
	}
	else {
		interrupt->error=1;
	}
}

void interruptClearPending(interrupt_t* interrupt) {
	if (interrupt->number <= 31) {
		NVIC_ICPP0 = 1<< interrupt->number;
	}
	else if (interrupt->number <=59) {
		NVIC_ICPP1 = 1<< (interrupt->number-32);
	}
	else {
		interrupt->error=1;
	}
}

void interruptIsActive(interrupt_t* interrupt) {
	if (interrupt->number <= 31) {
		interrupt->active = GET_BIT(NVIC_IABR0,interrupt->number);
	}
	else if (interrupt->number <=59) {
		interrupt->active = GET_BIT(NVIC_IABR1,interrupt->number-32);
	}
	else {
		interrupt->error=1;
	}
}