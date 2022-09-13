/*
 * Author : Nabil Gamal
 * Date : 11/9/2020
 * Description : Generic Timer Driver
 *
 */

#ifndef INT_H_
#define INT_H_


void Timer0_vid_Init (void);
void TIMER_voidSetCallBack( void (*Copy_Ptr) (void), uint8 TIMER_INDEX );

void Timer0_Uint8Set_Ocr_Value (uint8 OCR_Value);

void Timer1_vid_Init (void);

#endif
