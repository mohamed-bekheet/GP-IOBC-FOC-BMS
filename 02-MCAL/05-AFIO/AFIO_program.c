/**************************************************************************************************************/
/* Author  : Mohamed Sedeek                                                                                   */
/* Date    : 5 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/

#include <STD_TYPES.h>
#include <BIT_MATH.h>
#include <AFIO_interface.h>
#include <AFIO_private.h>
#include <AFIO_config.h>

sint8 AFIO_EXTI_selectPort(u8 copyPin, u8 copyPort){
	if (copyPin<=15 && copyPort<=2) {
		u8 localReg=0,localShift=0;
	
		localReg= copyPin/4;
		localShift= copyPin%4;
		
		*(AFIO_EXTICR1+localReg) &= ~(0xF<<localShift*4);
		*(AFIO_EXTICR1+localReg) |= (copyPort<<localShift*4);
		return 0; // No error
	}
	else {
		return -1; //Return error
	}
}