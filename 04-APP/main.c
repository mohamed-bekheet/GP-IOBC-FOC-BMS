/*
 * main.c
 *
 *  Created on: Nov 4, 2022
 *      Author: El-Rehab
 */

#include "../02-MCAL/01-RCC/RCC_interface.h"
#include "../02-MCAL/02-GPIO/GPIO_interface.h"
rcc_cfg_t rcc_portA_clk =
{
	.bus_id=RCC_APB2,
	.peripheral_id=RCC_IOPA_CLK_ENABLE,
	.error=0
};

gpio_pin_t pin =
{
	.pin=PIN8,
	.dir=GPIO_OUTPUT_PUSH_PULL,
	.port=GPIO_PORTA,
	.error=0
};

int main()
{
	RCC_InitClock();
	RCC_EnablePeriphClock(&rcc_portA_clk);
	GPIO_PinInit(&pin);
	while(1)
	{
		GPIO_PinToggle(&pin);
	}
	return 0;
}
