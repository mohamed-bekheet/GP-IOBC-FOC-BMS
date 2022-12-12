/**************************************************************************************************************/
/* Author  : Mohamed Sedeek                                                                                   */
/* Date    : 2 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/

#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H

typedef struct {
	uint8 number :6;
	uint8 groupPriority :4 ;
	uint8 subPriority :4;
	uint8 active :1;
	uint8 error  :1;
}interrupt_t;

typedef enum {
	WWDG=0,
	PVD,
	TAMPER,
	RTC,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Channel1,
	DMA1_Channel2,
	DMA1_Channel3,
	DMA1_Channel4,
	DMA1_Channel5,
	DMA1_Channel6,
	DMA1_Channel7,
	ADC1_2,
	USB_HP_CAN_TX,
	USB_LP_CAN_RX0,
	CAN_RX1,
	CAN_SCE,
	EXTI9_5,
	TIM1_BRK,
	TIM1_UP,
	TIM1_TRG_COM,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	USART3,
	EXTI15_10,
	RTCAlarm,
	USBWakeup,
	TIM8_BRK,
	TIM8_UP,
	TIM8_TRG_COM,
	TIM8_CC,
	ADC3,
	FSMC,
	SDIO,
	TIM5,
	SPI3,
	UART4,
	UART5,
	TIM6,
	TIM7,
	DMA2_Channel1,
	DMA2_Channel2,
	DMA2_Channel3,
	DMA2_Channel4_5
}interrupt_number_t;

#define PRIORITY_GROUP1 0x0FA050300
#define PRIORITY_GROUP2 0x0FA050400
#define PRIORITY_GROUP3 0x0FA050500
#define PRIORITY_GROUP4 0x0FA050600
#define PRIORITY_GROUP5 0x0FA050700

void interruptEnable(interrupt_t* interrupt);
void interruptDisable(interrupt_t* interrupt);

void interruptSetPending(interrupt_t* interrupt);
void interruptClearPending(interrupt_t* interrupt);

void interruptIsActive(interrupt_t* interrupt);

void initInterruptPriority(void);
void setInterruptPriority(interrupt_t* interrupt);

void setSoftwareInterrupt(interrupt_t* interrupt);

#endif
