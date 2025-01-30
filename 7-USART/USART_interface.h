/****************************************************/
/****************************************************/
/*****************  USART MCAH **********************/
/****************   A_NABIL    **********************/
/*************   USART_INTERFACE_H_  ****************/
/****************************************************/


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);

u8 USART_voidSendCharSynch(u8 Copy_u8Data);

u8 USART_voidReceiveCharSynch(u8 * UDR_Value);

u8 USART_u8SendCharAsynch(u8  Copy_u8Data,void(*Copy_pvNotificationFUNC)(void));

void USART_u8SendStringSynch(char* USART_pcSendString);

u8 USART_u8SendStringAsynch(char* USART_pcSendString,void(*Copy_pvNotificationFUNC)(void));//generate interrupt when buffer is empty

u8 USART_u8ReceiveCharAsynch(u8  *Copy_u8Data,void(*Copy_pvNotificationFUNC)(void));

void USART_u8ReceiveBufferSynch(u8* Buffer_Container,u8 Buffer_Size);

u8 USART_u8ReceiveBufferAsynch(u8* Buffer_Container,u8 Buffer_Size,void(*Copy_pvNotificationFUNC)(void));


#endif
