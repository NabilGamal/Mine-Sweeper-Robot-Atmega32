#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "MOTOR_int.h"
#include "util/delay.h"
#include "UART_int.h"
#include "Stepper_Init.h"
#include "ADC_int.h"
#include "EXTI_int.h"
#include "int.h"
//#define SREG    (*((volatile uint8 *)0x5F ) )

void main ()
{
	DIO_vid_Init();
	char Data_in;
	//uint8 flag;
	uint8 flag_right = 0;
	uint8 flag_left = 0;
	uint8 flag_start = 0;
	UART_voidInit();
	uint8  MyPointer ;
	uint16 Analog ;
	ADC_voidInit();
	Timer0_vid_Init();
//	EXTI_voidInit();
//	SET_BIT(SREG , 7);
//	EXTI_voidEnable();
//	DIO_vid_SetPinValue(DIO_uint8_PIN_26 , DIO_uint8_HIGH);

	while (1)
	{
		 ADC_uint8GetConversionValue(0 , &MyPointer);

		 Analog = (uint16) (   (uint32)(  (uint32)MyPointer * (uint32)5000) / (uint16)256 );

		 Data_in = UART_uint8ReceiveByte();						/* receive data from Bluetooth device*/

		// if (Analog == 0)
		 //{

				if(Data_in =='1')
				{
					MOTOR_Right_Clock_wise ();					/* Robot starts moving in forward direction */
					MOTOR_Left_Clock_wise ();

					USART_SendString("Robot Forward\n");		/* send status of Motor i.e. Motor Forward */

				}
				else if(Data_in =='2')
				{
					MOTOR_Right_AntiClock_wise ();				/* Robot starts moving in Backward direction */
					MOTOR_Left_AntiClock_wise();

					USART_SendString("Robot Backward\n"); 		/* send status of Motor i.e. Motor Backward */
				}

				else if(Data_in =='3')
				{
					 MOTOR_Right_OFF ();						/* Robot OFF */
					 MOTOR_Left_OFF();
					USART_SendString("Robot OFF\n"); 			/* send status of Motor i.e. Motor OFF */
				}

				else if(Data_in =='4')
					{
					MOTOR_Right_Clock_wise ();					/* Robot starts moving in forward direction */
					MOTOR_Left_OFF();
					USART_SendString("Robot Left\n"); 			/* send status of Motor i.e. Motor OFF */
					}

				else if(Data_in =='5')
					{
					MOTOR_Right_OFF ();
					MOTOR_Left_Clock_wise ();
						USART_SendString("Robot Right\n"); 			/* send status of Motor i.e. Motor OFF */
					}


				else if(Data_in == '7')
				{
					flag_left = 1;
					USART_SendString("Scanning Left"); 					/* Send status of The Large Actuator (X-Axis) */
					Stepper_vidClockWise(); 					/* The Actuator LEFT */
					 _delay_ms (2000);
					Stepper_vidOFF(); 								/* Scan OFF */

				/*	 if (Data_in =='0')
								 	{
						 EXTI_voidSetCallBack(Stop);
								 	}*/

				}

				else if(Data_in == '8')
					{

					USART_SendString("Returning to the start"); 					/* Send status of The Large Actuator (X-Axis) */

					if (flag_left == 1)
					{
						Stepper_vidCounterClockWise(); 						/* The Actuator goes to right direction */
						 _delay_ms (2000);
						Stepper_vidOFF(); 								/* Scan OFF */
						flag_left = 0;
					}

					else if (flag_right == 1)
					{
						Stepper_vidClockWise(); 						/* The Actuator goes to LEFT direction */
						 _delay_ms (2000);
						Stepper_vidOFF(); 								/* Scan OFF */
						flag_right = 0;
										}
					/*	 if (Data_in =='0')
					 	{
						 EXTI_voidSetCallBack(Stop);
					 	}*/

					}

				else if(Data_in == '9')
				{
				flag_right = 1;
				USART_SendString("Scanning Right"); 					/* Send status of The Large Actuator (X-Axis) */
				Stepper_vidCounterClockWise();  						/* The Actuator goes to right direction */
				Stepper_vidOFF(); 								/* Scan OFF */

				/*	 if (Data_in =='0')
				 	{
					 EXTI_voidSetCallBack(Stop);
				 	}*/

				}

				else if(Data_in == 'U')
				{
					USART_SendString("Actuator Moving Up"); 		/* Send status of The Small Actuator (Z-Axis) */
					StepperSmall_vidClockWise();					/* The Actuator Moves UP */
					StepperSmall_vidOFF(); 								/* OFF */
				}

				else if(Data_in == 'D')
				{
					USART_SendString("Actuator Moving Down"); 		/* Send status of The Small Actuator (Z-Axis) */
					StepperSmall_vidCounterClockWise (); 						/* The Actuator Moves Down */
					StepperSmall_vidOFF(); 								/* OFF */
				}

				else if (Data_in =='0')
				{

					Pump_Start();
					_delay_ms (3000);
					Pump_Off();
					_delay_ms (3000);

					if (flag_left == 1)
						{
							Stepper_vidCounterClockWise(); 						/* The Actuator goes to right direction */
							_delay_ms (2000);
							Stepper_vidOFF(); 								/* Scan OFF */
							flag_left = 0;
						}

					else if (flag_right == 1)
						{
						Stepper_vidClockWise(); 						/* The Actuator goes to right direction */
							 _delay_ms (2000);
							Stepper_vidOFF(); 								/* Scan OFF */
							flag_right = 0;
					}


				else
					USART_SendString("Select proper option\n");	/* send message for selecting proper option */

				}

				else if (Data_in == 'H')
					{
						Timer0_Uint8Set_Ocr_Value(255); // For Fast and Phase
						USART_SendString("Moving With High Speed");
					}

				else if (Data_in == 'M')
					{
						Timer0_Uint8Set_Ocr_Value(230); // For Fast and Phase
						USART_SendString("Moving With Medium Speed");
					}

				else if (Data_in == 'L')
					{
						Timer0_Uint8Set_Ocr_Value(220); // For Fast and Phase
						USART_SendString("Moving With Low Speed");
					}
	}
}


		 //}

//		 else if (Analog > 1000)
//		 {
//				Stepper_vidClockWise(); 						/* The Actuator goes to right direction */
//
//			 MOTOR_Right_OFF ();						/* Robot OFF */
//			 MOTOR_Left_OFF();
//
//			 Stepper_vidOFF(); 							/* Scan OFF */
//
//			 if (Data_in =='9')
//			 	{
//				 	Stepper_vidReturnLeft();
//				 	Stepper_vidReturnRight();
//			 		MOTOR_Right_AntiClock_wise ();				/* Robot starts moving in Backward direction */
//			 		MOTOR_Left_AntiClock_wise();
//
//			 		USART_SendString("Robot Backward\n"); 		/* send status of Motor i.e. Motor Backward */
//			 	}
//
//
//			 if (Data_in =='0')
//			 	{
//				 Stepper_vidOFF();
//			 	}
//
//		 }









