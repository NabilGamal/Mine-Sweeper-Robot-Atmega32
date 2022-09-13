 /******************************************************************************
 *
 * Module: EXTI
 *
 * File Name: EXTI_int.h
 *
 * Description: Header file for EXTI in AVR ATmega 32..
 *
 * Author: Nabil Gamal
 ******************************************************************************/

#ifndef _EXTI_INT_H_

#define _EXTI_INT_H_


void EXTI_voidInit(void);

void EXTI_voidSetCallBack(void (*Copy_ptr) (void));

void EXTI_voidEnable(void);

void EXTI_voidDisable(void);
void Stop (void);


#endif
