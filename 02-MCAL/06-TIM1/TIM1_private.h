/**************************************************************************************************************/
/* Author  : Khaled Essam                                                                                   */
/* Date    : 11 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/


#ifndef TIM1_PRIVATE_H_
#define TIM1_PRIVATE_H_

#define TIM1_CR1    *((volatile uint32*)(0x40012C00))
#define TIM1_CR2    *((volatile uint32*)(0x40012C04))
#define TIM1_SMCR   *((volatile uint32*)(0x40012C08))
#define TIM1_DIER   *((volatile uint32*)(0x40012C0C))
#define TIM1_SR     *((volatile uint32*)(0x40012C10))
#define TIM1_EGR    *((volatile uint32*)(0x40012C14))
#define TIM1_CCMR1  *((volatile uint32*)(0x40012C18))
#define TIM1_CCMR2  *((volatile uint32*)(0x40012C1C))
#define TIM1_CCER   *((volatile uint32*)(0x40012C20))
#define TIM1_CNT    *((volatile uint32*)(0x40012C24))
#define TIM1_PSC    *((volatile uint32*)(0x40012C28))
#define TIM1_ARR    *((volatile uint32*)(0x40012C2C))
#define TIM1_RCR    *((volatile uint32*)(0x40012C30))
#define TIM1_CCR1   *((volatile uint32*)(0x40012C34))
#define TIM1_CCR2   *((volatile uint32*)(0x40012C38))
#define TIM1_CCR3   *((volatile uint32*)(0x40012C3C))
#define TIM1_CCR4   *((volatile uint32*)(0x40012C40))
#define TIM1_BDTR   *((volatile uint32*)(0x40012C44))
#define TIM1_DCR    *((volatile uint32*)(0x40012C48))
#define TIM1_DMAR   *((volatile uint32*)(0x40012C4C))



#endif /* TIM1_PRIVATE_H_ */
