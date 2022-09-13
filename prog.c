/*
 * Author : Nabil Gamal
 * Date : 11/9/2020
 * Description : Generic Timer Driver
 *
 */

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "int.h"
#include "config.h"
#include "priv.h"

void (*CallBackPointer[TIMER_ISR_NUMBERS]) (void);


void TIMER_voidSetCallBack( void (*Copy_Ptr) (void), uint8 TIMER_INDEX )
{
	CallBackPointer [TIMER_INDEX] = Copy_Ptr ;
}
//NORMAL Mode
void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	static uint16 counter = 0;
	counter++;
	if (counter == Normal_uint16Counter_Value)
	{

		CallBackPointer[TIMER_0_INT_NORMAL_OVERFLOW]();
		counter = 0;
		TCNT0 = 0;

	}
}

//CTC
void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{
	static uint16 counter = 0;
	counter++;
	if (counter == CTC_uint16Counter_Value)
	{
		CallBackPointer[TIMER_0_INT_CTC_OVERFLOW]();
		counter = 0;
		TCNT0 = 0;

	}



}

void Timer0_Uint8Set_Ocr_Value (uint8 OCR0_Value)
{
	OCR0 = OCR0_Value;
}



void Timer0_vid_Init (void)
{

#if (TIMER_MODE == TIMER_0_NORMAL_MODE)
	CLEAR_BIT (TCCR0, 6);
	CLEAR_BIT (TCCR0, 3);
	SET_BIT   (TIMSK, 0);

	//Enable Global interrupt
	SET_BIT   (SREG, 7);

	//Put TCNT0 in Function
	TCNT0 = 0;


#elif (TIMER_MODE == TIMER_0_CTC_MODE)
	SET_BIT   (TCCR0, 3);
	CLEAR_BIT (TCCR0, 6);
	SET_BIT   (TIMSK, 1);

	//Enable Global interrupt
	SET_BIT (SREG, 7);
	TCNT0 = 0;

	//Put the OCR0 in Function
	//OCR0 = 100;

#elif (TIMER_MODE == TIMER_0_FAST_PWM_MODE)
		SET_BIT   (TCCR0, 3);
		SET_BIT (TCCR0, 6);

		//SET_BIT (TCCR0, 5);
		//CLEAR_BIT (TCCR0, 4);
		switch (Fast_PWM_MODE)
			{
				//Clear OC0 PIN ON COMPARE MATCH
				case 1:
					SET_BIT (TCCR0, 5);
					CLEAR_BIT (TCCR0, 4);
					break;

				//Set OC0 PIN ON COMPARE MATCH
				case 2:
					SET_BIT (TCCR0, 4);
					CLEAR_BIT (TCCR0, 5);
					break;
			}

#elif (TIMER_MODE == TIMER_0_Phase_PWM_MODE)
		CLEAR_BIT   (TCCR0, 3);
		SET_BIT (TCCR0, 6);

		//SET_BIT (TCCR0, 5);
		//CLEAR_BIT (TCCR0, 4);
		switch (Phase_PWM_MODE)
			{
				//Clear OC0 PIN ON COMPARE MATCH
				case 1:
					SET_BIT (TCCR0, 5);
					CLEAR_BIT (TCCR0, 4);
					break;

				//Set OC0 PIN ON COMPARE MATCH
				case 2:
					SET_BIT (TCCR0, 4);
					CLEAR_BIT (TCCR0, 5);
					break;
			}

#endif


#if (TIMER_PRESCALAR == PRESCALAR_8)
	CLEAR_BIT   (TCCR0, 2);
	SET_BIT     (TCCR0, 1);
	CLEAR_BIT   (TCCR0, 0);

#endif




}



void Timer1_vid_Init (void)
{

#if (TIMER1_MODE == TIMER_1_FAST_PWM_MODE_ICR1)
	//CHANNEL A

	SET_BIT(OCR1A, 7);
	CLEAR_BIT(OCR1A, 6);

	SET_BIT(TCCR1A, 1);
	CLEAR_BIT(TCCR1A, 0);

	SET_BIT(TCCR1B, 4);
	SET_BIT(TCCR1B, 3);

#endif
}
