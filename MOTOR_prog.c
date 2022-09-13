/*
 * Author : Nabil Gamal
 * Date : 11/9/2020
 * Description : DC Motor Driver
 *
 */

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "MOTOR_int.h"
#include "MOTOR_config.h"
#include "MOTOR_priv.h"


void MOTOR_Right_Clock_wise (void)
{

	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_1 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_0 , DIO_uint8_LOW);

}


void MOTOR_Right_AntiClock_wise (void)
{

	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_1 , DIO_uint8_LOW);
	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_0 , DIO_uint8_HIGH);


}

void MOTOR_Right_OFF (void)
{


	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_1 , DIO_uint8_LOW);
	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_0 , DIO_uint8_LOW);


}

void MOTOR_Right2_Clock_wise (void)
{

	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_1 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_0 , DIO_uint8_LOW);

}


void MOTOR_Right2_AntiClock_wise (void)
{

	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_1 , DIO_uint8_LOW);
	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_0 , DIO_uint8_HIGH);


}

void MOTOR_Right2_OFF (void)
{


	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_1 , DIO_uint8_LOW);
	DIO_vid_SetPinValue (MOTOR_Right_unit8_Pin_0 , DIO_uint8_LOW);


}

void MOTOR_Left_Clock_wise (void)
{

	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_1, DIO_uint8_HIGH);
	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_0, DIO_uint8_LOW);

}


void MOTOR_Left_AntiClock_wise (void)
{

	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_1 , DIO_uint8_LOW);
	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_0 , DIO_uint8_HIGH);


}

void MOTOR_Left_OFF (void)
{


	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_1 , DIO_uint8_LOW);
	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_0 , DIO_uint8_LOW);


}
void MOTOR_Left2_Clock_wise (void)
{

	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_1, DIO_uint8_HIGH);
	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_0, DIO_uint8_LOW);

}


void MOTOR_Left2_AntiClock_wise (void)
{

	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_1 , DIO_uint8_LOW);
	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_0 , DIO_uint8_HIGH);


}

void MOTOR_Left2_OFF (void)
{


	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_1 , DIO_uint8_LOW);
	DIO_vid_SetPinValue (MOTOR_Left_unit8_Pin_0 , DIO_uint8_LOW);


}

void Pump_Start (void)
{
	DIO_vid_SetPinValue (Pump_Pin_1 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue (Pump_Pin_2 , DIO_uint8_LOW);
}

void Pump_Off (void)
{
	DIO_vid_SetPinValue (Pump_Pin_1 , DIO_uint8_LOW);
	DIO_vid_SetPinValue (Pump_Pin_2 , DIO_uint8_LOW);
}
