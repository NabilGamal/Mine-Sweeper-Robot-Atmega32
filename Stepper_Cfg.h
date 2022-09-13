 /******************************************************************************
 *
 * Module: Stepper
 *
 * File Name: Stepper_Cfg.h
 *
 * Description: Header file for Stepper Motor that has its configuration.
 *
 * Author: Nabil Gamal
 ******************************************************************************/

#ifndef STEPPER_CFG_H_
#define STEPPER_CFG_H_

#define Stepper_DirectionPin	DIO_uint8_PIN_10
#define Stepper_StepPin			DIO_uint8_PIN_9

#define StepperSmall_DirectionPin	DIO_uint8_PIN_13
#define StepperSmall_StepPin		DIO_uint8_PIN_12

#define Step_Per_Revolution		190

#define Step_Per_Revolution_Nema		1200

#endif
