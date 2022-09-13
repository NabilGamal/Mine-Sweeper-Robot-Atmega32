 /******************************************************************************
 *
 * Module: Stepper
 *
 * File Name: Stepper_Init.h
 *
 * Description: Header file for Stepper Motor.
 *
 * Author: Nabil Gamal
 ******************************************************************************/

#ifndef STEPPER_INIT_H_
#define STEPPER_INIT_H_


void Stepper_vidClockWise (void);

void Stepper_vidCounterClockWise (void);

void Stepper_vidReturnLeft (void);

void Stepper_vidReturnRight(void);

void Stepper_vidOFF (void);

void StepperSmall_vidOFF (void);

void StepperSmall_vidCounterClockWise (void);

void StepperSmall_vidClockWise (void);

#endif
