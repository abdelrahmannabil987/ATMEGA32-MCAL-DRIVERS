/****************************************************/
/****************************************************/
/*****************  USART MCAH **********************/
/****************   A_NABIL    **********************/
/*************   USART_CONFIG_H_  ******************/
/****************************************************/


#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/*Character Size is the size of tx/rx data (Useful Data)
 * options :
 * 1-five_bits
 * 2-six_bits
 * 3-seven_bits
 * 4-eight_bits
 * 5-nine_bits
 * */
#define Character_Size eight_bits

/*Baud rate = bit rate
 * options:
 * 1-_9600_Baud_Rate*/
#define Baud_Rate   _9600_Baud_Rate


/*Stop_Bits
 * options :
 * 1-one_bit_stop
 * 2-two_bit_stop
 * */

#define Stop_Bits one_bit_stop

/*Parity_Mode
 * options:
 * 1-Disabled
 * 2-Even_Parity
 * 3-Odd_Parity
 * */
#define Parity_Mode Disabled


/*Communication_Mode
 * options:
 * 1-Asynchronous_Operation
 * 2-Synchronous_Operation
 * */
#define Communication_Mode  Asynchronous_Operation
/*
 * assign baud rate to UBRR
 * options :
 * 1-ASYNCH_NORMAL_MODE
 * 2-ASYNCH_DOUBLE_SPEED
 * 3-SYNCH_MODE
 *
 * */
#define SPEED_MODE ASYNCH_NORMAL_MODE

#define USART_TIME_OUT 50000

#define SYS_FREQ 8000000
#define BAUD_RATE  9600

#endif
