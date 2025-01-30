/****************************************************/
/****************************************************/
/*****************  USART MCAH **********************/
/****************   A_NABIL    **********************/
/*************   USART_PRIVATE_H_  ******************/
/****************************************************/


#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define five_bits   1
#define six_bits    2
#define seven_bits  3
#define eight_bits  4
#define nine_bits   5


#define _9600_Baud_Rate 51

#define one_bit_stop   1
#define two_bit_stop   2

#define Disabled      1
#define Even_Parity   2
#define Odd_Parity    3

#define Asynchronous_Operation  1
#define Synchronous_Operation   2

#define Empty_forSendChar          1
#define Empty_forSendCharInString  2
#define Received_Char_Complete     3
#define Received_CharInBuffer_Complete     4

#define IDLE       1
#define BUSY       2

#define ASYNCH_NORMAL_MODE    1
#define ASYNCH_DOUBLE_SPEED   2
#define SYNCH_MODE            3


#endif
