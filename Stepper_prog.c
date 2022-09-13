 /******************************************************************************
 *
 * Module: Stepper
 *
 * File Name: Stepper_Prog.c
 *
 * Description: C file for Stepper Motor.
 *
 * Author: Nabil Gamal
 ******************************************************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "Stepper_Init.h"
#include "Stepper_Cfg.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "UART_int.h"

uint16 y1;
uint16 y2;
char Data_in;

void Stepper_vidClockWise ()
{
	uint16 x;
    y1 = 0;
    y2 = 0;

	DIO_vid_SetPinValue(Stepper_DirectionPin, DIO_uint8_HIGH);	/* Set the direction Pin to the right */

	for (x = 0; x < Step_Per_Revolution_Nema; x++)
	{

		DIO_vid_SetPinValue(Stepper_StepPin, DIO_uint8_HIGH);	/* Actuator rolls forward */
		_delay_us (2000);
		DIO_vid_SetPinValue(Stepper_StepPin, DIO_uint8_LOW);	/* Actuator OFF */
		_delay_us (2000);


		y1 = x;
	}



}

void Stepper_vidCounterClockWise ()

{

	uint16 x;
    y2 = 0;
	y1 = 0;

		DIO_vid_SetPinValue(Stepper_DirectionPin, DIO_uint8_LOW);	/* Set the direction Pin to the left */

		for (x = 0; x < Step_Per_Revolution_Nema; x++)
		{

			DIO_vid_SetPinValue(Stepper_StepPin, DIO_uint8_HIGH);	/* Actuator rolls backward */
			_delay_us (2000);
			DIO_vid_SetPinValue(Stepper_StepPin, DIO_uint8_LOW);	/* Actuator OFF */
			_delay_us (2000);


			y2 = x;
		}

}

void Stepper_vidReturnLeft ()
{
	for (y1; y1 > 0; y1--)
	{
		DIO_vid_SetPinValue(Stepper_DirectionPin, DIO_uint8_LOW);	/* Set the direction Pin to the left */

		DIO_vid_SetPinValue(Stepper_StepPin, DIO_uint8_HIGH);	/* Actuator rolls backward */
		_delay_us (2000);
		DIO_vid_SetPinValue(Stepper_StepPin, DIO_uint8_LOW);	/* Actuator OFF */
		_delay_us (2000);
	}

}

void Stepper_vidReturnRight ()
{
	DIO_vid_SetPinValue(Stepper_DirectionPin, DIO_uint8_HIGH);	/* Set the direction Pin to the right */

	for (y2; y2 > 0; y2--)
	{
		DIO_vid_SetPinValue(Stepper_StepPin, DIO_uint8_HIGH);	/* Actuator rolls forward */
		_delay_us (2000);
		DIO_vid_SetPinValue(Stepper_StepPin, DIO_uint8_LOW);	/* Actuator OFF */
		_delay_us (2000);
	}

}

void Stepper_vidOFF ()
{
	DIO_vid_SetPinValue(Stepper_StepPin, DIO_uint8_LOW);	/* Actuator OFF */
}

void StepperSmall_vidClockWise ()
{
	uint16 x;

		DIO_vid_SetPinValue(StepperSmall_DirectionPin, DIO_uint8_HIGH);		/* Set the direction Pin to the left */

		for (x = 0; x < Step_Per_Revolution; x++)
		{
			DIO_vid_SetPinValue(StepperSmall_StepPin, DIO_uint8_HIGH);		/* Actuator rolls backward */
			_delay_us (2000);
			DIO_vid_SetPinValue(StepperSmall_StepPin, DIO_uint8_LOW);		/* Actuator OFF */
			_delay_us (2000);
		}

}

void StepperSmall_vidCounterClockWise ()

{

	uint16 x;

		DIO_vid_SetPinValue(StepperSmall_DirectionPin, DIO_uint8_LOW);		/* Set the direction Pin to the left */

		for (x = 0; x < Step_Per_Revolution; x++)
		{
			DIO_vid_SetPinValue(StepperSmall_StepPin, DIO_uint8_HIGH);		/* Actuator rolls backward */
			_delay_us (2000);
			DIO_vid_SetPinValue(StepperSmall_StepPin, DIO_uint8_LOW);		/* Actuator OFF */
			_delay_us (2000);
		}


}

void StepperSmall_vidOFF ()
{
	DIO_vid_SetPinValue(StepperSmall_StepPin, DIO_uint8_LOW);		/* Actuator OFF */
}
