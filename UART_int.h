 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART_int.h
 *
 * Description: Header file for UART in AVR ATmega 32..
 *
 * Author: Nabil Gamal
 ******************************************************************************/

#ifndef UART_INT_H_
#define UART_INT_H_


void UART_voidInit(void);

void UART_voidSendByte(uint8 Byte);

uint8 UART_uint8ReceiveByte(void);

uint8 UART_uint8_ReturnUDRValue(void);

void UART_void_SetCBReceive( void (*ptr) (void) );
void USART_SendString(char *str);


#endif /* UART_INT_H_ */
