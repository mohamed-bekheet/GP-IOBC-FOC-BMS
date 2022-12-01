/***************************************************************/
/* Author:Khaled Essam & Mohamed Sedeek                        */
/* Date : 05/11/2022                                           */
/* Version : V02                                               */
/***************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/************************includes*****************************/
#include "../../01-LIB/STD_TYPES.h"
#include "GPIO_config.h"
/**************************macros******************************/
#define GPIO_INPUT_FLOAT          0x4
#define GPIO_INPUT_PULL_UP_DOWN   0x8
#define GPIO_INPUT_ANALOG 		  0x0
#define GPIO_OUTPUT_OPEN_DRAIN    0x5
#define GPIO_OUTPUT_PUSH_PULL     0x1
#define GPIO_AF_PUSH_PULL         0x9
#define GPIO_AF_OPEN_DRAIN        0xD

#define GPIO_ALL_PINS_INPUT_FLOAT          0x44444444
#define GPIO_ALL_PINS_INPUT_PULL_UP_DOWN   0x88888888
#define GPIO_ALL_PINS_INPUT_ANALOG 		   0x00000000
#define GPIO_ALL_PINS_OUTPUT_OPEN_DRAIN    0x55555555
#define GPIO_ALL_PINS_OUTPUT_PUSH_PULL     0x11111111
#define GPIO_ALL_PINS_AF_PUSH_PULL         0x99999999
#define GPIO_ALL_PINS_AF_OPEN_DRAIN        0xDDDDDDDD

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

#define HIGH 1
#define LOW  0

#define ALL_PINS_HIGH 0xFFFF
#define ALL_PINS_LOW  0x0000

/************************data types***************************/
typedef struct
{
    uint8 pin  :4;
    uint8 port :2;
    uint8 dir  :4;
    uint8 error:1;
    uint8 read :1;  /*read bit in case of input cfg */
	uint8 write:1;
    uint8 reserved:3;
}gpio_pin_t;

typedef struct
{
    uint8 port :2;
    uint8 dir  :4;
    uint16 read :16;
	uint16 write :16;
    uint8 error:1;
    uint8 reserved:1;
}gpio_port_t;

typedef enum
{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15,
}pin_t;

/**************************APIs*****************************/
void GPIO_PinInit  (gpio_pin_t* pin);
void GPIO_PinRead  (gpio_pin_t* pin);
void GPIO_PinWrite (gpio_pin_t* pin);
void GPIO_PinToggle(gpio_pin_t* pin);

void GPIO_PortInit  (gpio_port_t* port);
void GPIO_PortRead  (gpio_port_t* port);
void GPIO_PortWrite (gpio_port_t* port);
void GPIO_PortToggle(gpio_port_t* port);
#endif
