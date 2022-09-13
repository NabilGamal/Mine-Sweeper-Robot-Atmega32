/******************************************************************************
 *
 * Module: EXTI
 *
 * File Name: EXTI_prog.c
 *
 * Description: C file for EXTI in AVR ATmega 32..
 *
 * Author: Nabil Gamal
 ******************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_int.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"


 /* Pointer to function */
void (* EXTI_CallBack) (void) ;


void __vector_1(void) __attribute__((signal , used));
void __vector_1(void)
{
	EXTI_CallBack() ;
	
}

void EXTI_voidInit(void)
{
		/*Set Mode*/
		#if(EXTI_uint8_MODE == EXTI_uint8_LOW_LEVEL)
			CLEAR_BIT(MCUCR , ISC0);
			CLEAR_BIT(MCUCR , ISC1);
		#elif(EXTI_uint8_MODE == EXTI_uint8_IOC)	
			SET_BIT(MCUCR , ISC0);
			CLEAR_BIT(MCUCR , ISC1);
		#elif(EXTI_uint8_MODE == EXTI_uint8_FALLING_EDGE)
			CLEAR_BIT(MCUCR , ISC0);
			SET_BIT(MCUCR , ISC1);
		#else
			SET_BIT(MCUCR , ISC0);
			SET_BIT(MCUCR , ISC1);
		#endif
		
		/*Disable interrupt*/
		CLEAR_BIT(GICR , EXTI_INT0);
		/*Clear Flag*/
		SET_BIT(GIFR , EXTI_INT0);

}

void EXTI_voidSetCallBack(void (*Copy_ptr) (void))
{
	EXTI_CallBack = Copy_ptr ;
}

void EXTI_voidEnable(void)
{
	SET_BIT(GICR , EXTI_INT0);
}

void EXTI_voidDisable(void)
{
	CLEAR_BIT(GICR , EXTI_INT0);
}

