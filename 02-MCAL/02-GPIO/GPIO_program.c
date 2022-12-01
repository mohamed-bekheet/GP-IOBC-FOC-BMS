/***************************************************************/
/* Author:Khaled Essam & Mohamed Sedeek                        */
/* Date : 05/11/2022                                           */
/* Version : V02                                               */
/***************************************************************/

/*Includes*/
#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_PinInit  (gpio_pin_t* pin)
{
    if(pin && (pin->pin <= PIN15) && (pin->port <= GPIO_PORTC))
    {
        switch (pin->port)
        {
            case GPIO_PORTA: 
				if (pin->pin <= PIN7)
				{
					GPIOA_CRL &= ~(0xF << pin->pin*4 );  //make 4 bits zero
					GPIOA_CRL |= pin->dir << pin->pin*4;
				}
				else if(pin->pin <= PIN15)
				{
					GPIOA_CRH &= ~(0xF << (pin->pin-8)*4 );  //make 4 bits zero
					GPIOA_CRH |= pin->dir << (pin->pin-8)*4;
				}
            break;
            case GPIO_PORTB: 
				if (pin->pin <= PIN7)
				{
					GPIOB_CRL &= ~(0xF << pin->pin*4 );  //make 4 bits zero
					GPIOB_CRL |= pin->dir << pin->pin*4;
				}
				else if(pin->pin <= PIN15)
				{
					GPIOB_CRH &= ~(0xF << (pin->pin-8)*4 );  //make 4 bits zero
					GPIOB_CRH |= pin->dir << (pin->pin-8)*4;
				}
            
            break;
            case GPIO_PORTC: 
				if (pin->pin <= PIN7)
				{
					GPIOC_CRL &= ~(0xF << pin->pin*4 );  //make 4 bits zero
					GPIOC_CRL |= pin->dir << pin->pin*4;
				}
				else if(pin->pin <= PIN15)
				{
					GPIOC_CRH &= ~(0xF << (pin->pin-8)*4 );  //make 4 bits zero
					GPIOC_CRH |= pin->dir << (pin->pin-8)*4;
				}
			break;
			default: pin->error = 1;	
        }
    }
    else
    {
        /*return error*/
        pin->error=1;
    }
}

void GPIO_PinRead  (gpio_pin_t* pin)
{
    if(pin && (pin->pin <= PIN15) && (pin->port <= GPIO_PORTC))
    {
    	switch (pin->port)
    	{
    	case GPIO_PORTA : pin->read = (GPIOA_IDR >> pin->pin)&1 ; break;
    	case GPIO_PORTB : pin->read = (GPIOB_IDR >> pin->pin)&1 ; break;
    	case GPIO_PORTC : pin->read = (GPIOC_IDR >> pin->pin)&1 ; break;
    	default : pin->error = 1; 	    /* return error */
    	}
    }
    else
    {
        /*return error*/
        pin->error=1;
    }
}

void GPIO_PinWrite (gpio_pin_t* pin)
{
    if(pin && (pin->pin <= PIN15) && (pin->port <= GPIO_PORTC))
    {
		if(pin->write == HIGH) {
			switch (pin->port)
			{
				case GPIO_PORTA : GPIOA_BSRR = (1<<pin->pin); break;
				case GPIO_PORTB : GPIOB_BSRR = (1<<pin->pin); break;
				case GPIO_PORTC : GPIOC_BSRR = (1<<pin->pin); break;
				default : pin->error = 1; 	    /* return error */ 
			}
		}
		else if (pin->write == LOW) {
			switch (pin->port)
			{
				case GPIO_PORTA : GPIOA_BRR = (1<<pin->pin); break;
				case GPIO_PORTB : GPIOB_BRR = (1<<pin->pin); break;
				case GPIO_PORTC : GPIOC_BRR = (1<<pin->pin); break;
				default : pin->error = 1; 	    /* return error */ 
			}
		}
    }
    else
    {
        /*return error*/
        pin->error=1;
    }
}

void GPIO_PinToggle(gpio_pin_t* pin)
{
    if(pin && (pin->pin <= PIN15) && (pin->port <= GPIO_PORTC))
    {
    	switch (pin->port)
    	{
    	case GPIO_PORTA : GPIOA_ODR ^= (1<<pin->pin); break;
    	case GPIO_PORTB : GPIOB_ODR ^= (1<<pin->pin); break;
    	case GPIO_PORTC : GPIOC_ODR ^= (1<<pin->pin); break;
    	}
    }
    else
    {
        /*return error*/
        pin->error=1;
    }
}

void GPIO_PortInit  (gpio_port_t* port)
{
    if(port && (port->port <= GPIO_PORTC))
    {
        switch (port->port)
        {
            case GPIO_PORTA:
				GPIOA_CRL = port->dir;
				GPIOA_CRH = port->dir;
				break;

            case GPIO_PORTB:
				GPIOB_CRL = port->dir;
				GPIOB_CRH = port->dir;
				break;

            case GPIO_PORTC:
				GPIOC_CRL = port->dir;
				GPIOC_CRH = port->dir;
				break;
        }
    }
    else
    {
        /*return error*/
        port->error=1;
    }
}

void GPIO_PortRead  (gpio_port_t* port)
{
    if(port && (port->port <= GPIO_PORTC))
    {
		switch(port->port) {
			case GPIO_PORTA :
				port->read = GPIOA_IDR;
				break;
			case GPIO_PORTB :
				port->read = GPIOB_IDR;
				break;
			case GPIO_PORTC :
				port->read = GPIOC_IDR;
				break;	
		}
    }
    else
    {
        /*return error*/
        port->error=1;
    }
}

void GPIO_PortWrite (gpio_port_t* port)
{
    if(port && (port->port <= GPIO_PORTC))
    {
		switch(port->port) {
			case GPIO_PORTA : 
				GPIOA_ODR = port->write;
				break;
			case GPIO_PORTB : 
				GPIOB_ODR = port->write;
				break;
			case GPIO_PORTC : 
				GPIOC_ODR = port->write;
				break;		
		}

    }
    else
    {
        /*return error*/
        port->error=1;
    }
}

void GPIO_PortToggle(gpio_port_t* port)
{
    if(port && (port->port <= GPIO_PORTC))
    {
		switch(port->port) {
			case GPIO_PORTA:
				GPIOA_ODR ^= 0xFFFF;
				break;
			case GPIO_PORTB:
				GPIOB_ODR ^= 0xFFFF;
				break;
			case GPIO_PORTC:
				GPIOC_ODR ^= 0xFFFF;
				break;		
		}

    }
    else
    {
        /*return error*/
        port->error=1;
    }
}
