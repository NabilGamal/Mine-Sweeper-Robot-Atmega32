/*
 * Author : Nabil Gamal
 * Date : 11/9/2020
 * Description : Generic Timer Driver
 *
 */

#ifndef PRIV_H_
#define PRIV_H_

#define TIMER_0_NORMAL_MODE    	1

#define TIMER_0_CTC_MODE       	2

#define TIMER_0_PWM_MODE       	3

#define TIMER_0_FAST_PWM_MODE  	4

#define TIMER_0_Phase_PWM_MODE  5

#define TIMER_1_FAST_PWM_MODE_ICR1 14


#define PRESCALAR_8            8
#define PRESCALAR_64           64
#define PRESCALAR_256          256
#define PRESCALAR_1024         1024


#define TIMER_0_INT_NORMAL_OVERFLOW    0
#define TIMER_0_INT_CTC_OVERFLOW       1

#define Fast_PWM_Inverted				1
#define Fast_PWM_Non_Inverted			2

#define Phase_PWM_Inverted				1
#define Phase_PWM_Non_Inverted			2



//Timer0 Registers
#define SREG   (*((volatile uint8 *)(0x5F)))
#define TCCR0  (*((volatile uint8 *)(0x53)))
#define TCNT0  (*((volatile uint8 *)(0x52)))
#define OCR0   (*((volatile uint8 *)(0x5C)))
#define TIMSK  (*((volatile uint8 *)(0x59)))
#define TIFR   (*((volatile uint8 *)(0x58)))

//Timer1 Registers
#define TCCR1A (*((volatile uint8 *)(0x4F)))
#define TCCR1B (*((volatile uint8 *)(0x4E)))
#define TCNT1H (*((volatile uint8 *)(0x4D)))
#define TCNT1L (*((volatile uint8 *)(0x4C)))
#define TCNT1  (*((volatile uint16 *)(0x5C)))
#define OCR1AH (*((volatile uint8 *)(0x5B)))
#define OCR1AL (*((volatile uint8 *)(0x5A)))
#define OCR1A  (*((volatile uint16 *)(0x5A)))


#define OCR1BH (*((volatile uint8 *)(0x49)))
#define OCR1BL (*((volatile uint8 *)(0x48)))
#define OCR1B  (*((volatile uint16 *)(0x48)))


#define ICR1H  (*((volatile uint8 *)(0x47)))
#define ICR1L  (*((volatile uint8 *)(0x46)))
#define ICR1    (*((volatile uint16 *)(0x46)))


#endif
