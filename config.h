/*
 * Author : Nabil Gamal
 * Date : 11/9/2020
 * Description : Generic Timer Driver
 *
 */

#ifndef CONFIG_H_
#define CONFIG_H_


#define TIMER_MODE             TIMER_0_Phase_PWM_MODE
#define TIMER1_MODE            TIMER_1_FAST_PWM_MODE_ICR1

#define TIMER_PRESCALAR        PRESCALAR_8
#define TIMER_1_PRESCALER      PRESCALER_8

#define Fast_PWM_MODE		   Fast_PWM_Inverted
#define Phase_PWM_MODE		   Phase_PWM_Inverted

#define Normal_uint16Counter_Value        2000
#define CTC_uint16Counter_Value           2000

#define TIMER_ISR_NUMBERS              5

#endif
