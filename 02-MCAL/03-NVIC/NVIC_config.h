/**************************************************************************************************************/
/* Author  : Mohamed Sedeek                                                                                   */
/* Date    : 2 Dec 2022                                                                                       */
/* Version : 01                                                                                               */
/**************************************************************************************************************/

#ifndef _NVIC_CONFIG_H
#define _NVIC_CONFIG_H

#define INTERRUPT_PRIORITY_GROUP PRIORITY_GROUP1 
/* Options are:
	PRIORITY_GROUP1 ->  4 bits group priority corresponding to 16 group priorities, 0 bits sub priority corresponding to 0 sub priorities
	PRIORITY_GROUP2 ->  3 bits group priority corresponding to 8 group priorities,  1 bits sub priority corresponding to 2 sub priorities
	PRIORITY_GROUP3 ->  2 bits group priority corresponding to 4 group priorities,  2 bits sub priority corresponding to 4 sub priorities
	PRIORITY_GROUP4 ->  1 bits group priority corresponding to 2 group priorities,  3 bits sub priority corresponding to 8 sub priorities
	PRIORITY_GROUP5 ->  0 bits group priority corresponding to 0 group priorities,  4 bits sub priority corresponding to 16 sub priorities
*/

#endif