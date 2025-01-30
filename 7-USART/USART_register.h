/****************************************************/
/****************************************************/
/*****************  USART MCAH **********************/
/****************   A_NABIL    **********************/
/*************   USART_REGISTER_H_  *****************/
/****************************************************/

#ifndef USART_REGISTER_H_ 
#define USART_REGISTER_H_






#define UCSRA    *((u8* volatile)0x2B) //Control and Status Register A

#define UCSRA_RXC      7
#define UCSRA_TXC      6
#define UCSRA_UDRE     5
#define UCSRA_FE       4
#define UCSRA_DOR      3
#define UCSRA_PE       2
#define UCSRA_U2X      1
#define UCSRA_MPCM     0



#define UCSRB    *((u8* volatile)0x2A) //Control and Status Register B

#define UCSRB_RXCIE   7
#define UCSRB_TXCIE   6
#define UCSRB_UDRIE   5
#define UCSRB_RXEN    4
#define UCSRB_TXEN    3
#define UCSRB_UCSZ2   2
#define UCSRB_RXB8    1
#define UCSRB_TXB8    0




#define UBRRH    *((u8* volatile)0x40)//Baud Rate Register
#define UBRRH_URSEL   7
#define UCSRC    *((u8* volatile)0x40)//Control and Status Register C

#define UCSRC_UCPOL   0
#define UCSRC_UCSZ0   1
#define UCSRC_UCSZ1   2
#define UCSRC_USBS    3
#define UCSRC_UPM0    4
#define UCSRC_UPM1    5
#define UCSRC_UMSEL   6
#define UCSRC_URSEL   7


#define UDR      *((u8* volatile)0x2C)

#define UBRRL    *((u8* volatile)0x29)


#endif
