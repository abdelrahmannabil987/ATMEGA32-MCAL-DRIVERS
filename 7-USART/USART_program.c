#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"


u8 USART_STATE=IDLE;
static u8  USART_pu8Data;
static void (*USART_pvCallBackNotificationFUNC)(void) = NULL;
static char* USART_pcSendStringGlobal;
static void (*USART_pvCallBackNotificationFUNCString)(void) = NULL;
static u8* Received_data=NULL;
static void (*USART_pvCallBackNotificationFUNCReceivedChar)(void) = NULL;
static void (*USART_pvCallBackNotificationFUNCReceivedBuffer)(void) = NULL;
static u8 Buffer_Size_Global;
static u8*Buffer_Container_Global=NULL;
static u8 Interrupt_u8SRC;


void USART_voidInit(void)
{
	u8 Local_u8UCSRC_Value=0;
	u32 Local_u32UBRR_VALUE;

#if Character_Size == five_bits //Data Size

	CLR_BIT(Local_u8UCSRC_Value,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRC_Value,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif Character_Size == six_bits //Data Size

	SET_BIT(Local_u8UCSRC_Value,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRC_Value,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif Character_Size == seven_bits //Data Size

	CLR_BIT(Local_u8UCSRC_Value,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC_Value,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif Character_Size == eight_bits //Data Size

	SET_BIT(Local_u8UCSRC_Value,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC_Value,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif Character_Size == nine_bits //Data Size

	SET_BIT(Local_u8UCSRC_Value,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC_Value,UCSRC_UCSZ1);
	SET_BIT(UCSRB,UCSRB_UCSZ2);
#endif

	/*Stop Bits*/
#if Stop_Bits == one_bit_stop
	CLR_BIT(UCSRC,UCSRC_USBS);
#elif Stop_Bits == two_bit_stop
	SET_BIT(UCSRC,UCSRC_USBS);
#endif

#if Parity_Mode == Disabled
	CLR_BIT(UCSRC,UCSRC_UPM0);
	CLR_BIT(UCSRC,UCSRC_UPM1);

#elif Parity_Mode == Even_Parity
	CLR_BIT(UCSRC,UCSRC_UPM0);
	SET_BIT(UCSRC,UCSRC_UPM1);

#elif Parity_Mode == Odd_Parity
	SET_BIT(UCSRC,UCSRC_UPM0);
	SET_BIT(UCSRC,UCSRC_UPM1);

#endif
	u32 BAUD_RATY=BAUD_RATE;
#if SPEED_MODE==ASYNCH_NORMAL_MODE
	CLR_BIT(UCSRA,UCSRA_U2X);
	/*SET UBRR Value from the Equation in DATA SHEET*/
	Local_u32UBRR_VALUE=(u32)(SYS_FREQ/(u32)(16*BAUD_RATY))-1;
	UBRRL=(u8)Local_u32UBRR_VALUE;
	UBRRH=Local_u32UBRR_VALUE>>8;

#elif SPEED_MODE==ASYNCH_DOUBLE_SPEED
	SET_BIT(UCSRA,UCSRA_U2X);
	/*SET UBRR Value from the Equation in DATA SHEET*/
	Local_u32UBRR_VALUE=(u32)(SYS_FREQ/(u32)(8*BAUD_RATY))-1;
	UBRRL=(u8)Local_u32UBRR_VALUE;
	UBRRH=Local_u32UBRR_VALUE>>8;
#elif SPEED_MODE==SYNCH_MODE
	/*SET UBRR Value from the Equation in DATA SHEET*/
	Local_u32UBRR_VALUE=(u32)(SYS_FREQ/(u32)(2*BAUD_RATY))-1;
	UBRRL=(u8)Local_u32UBRR_VALUE;
	UBRRH=Local_u32UBRR_VALUE>>8;
#endif
#if Communication_Mode == Asynchronous_Operation
	CLR_BIT(UCSRC,UCSRC_UMSEL);
#elif Communication_Mode == Synchronous_Operation
	SET_BIT(UCSRC,UCSRC_UMSEL);
#endif

	SET_BIT(Local_u8UCSRC_Value,UCSRC_URSEL);//To accsess UCSRC not UBRRH
	UCSRC=Local_u8UCSRC_Value;

	//UBRRL=Baud_Rate;   //Baud Rate 9600 bps

	/*TX Enabling CCT*/
	SET_BIT(UCSRB,UCSRB_TXEN);

	/*RX Enabling CCT*/
	SET_BIT(UCSRB,UCSRB_RXEN);

}



u8 USART_voidSendCharSynch(u8 Copy_u8Data)
{
	u8 Local_u8ErrorState=OK;
	u32 Local_u32Counter=0;
	while((GET_BIT(UCSRA,UCSRA_UDRE)==0)&&(Local_u32Counter!=USART_TIME_OUT));//wait until transmit buffer is empty//data reg empty
	{
		Local_u32Counter++;
	}
	if(Local_u32Counter==USART_TIME_OUT)
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		UDR=Copy_u8Data;
	}
	return Local_u8ErrorState;
}

u8 USART_u8SendCharAsynch(u8 Copy_u8Data,void(*Copy_pvNotificationFUNC)(void))
{
	u8 Local_u8ErrorState=OK;
	if(USART_STATE==IDLE)
	{

		USART_STATE=BUSY;
		if(Copy_pvNotificationFUNC==NULL)
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			USART_pvCallBackNotificationFUNC=Copy_pvNotificationFUNC;
			USART_pu8Data=Copy_u8Data;
			SET_BIT(UCSRB,UCSRB_UDRIE);//PIE of Data Register Empty
		}
		Interrupt_u8SRC=Empty_forSendChar;
	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;

	}

	return Local_u8ErrorState;
}
u8 USART_u8SendStringAsynch(char* USART_pcSendString,void(*Copy_pvNotificationFUNC)(void))
{
	u8 Local_u8ErrorState=OK;
	if (USART_STATE==IDLE)
	{
		USART_STATE=BUSY;
		if(Copy_pvNotificationFUNC==NULL)
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			USART_pvCallBackNotificationFUNCString=Copy_pvNotificationFUNC;
			USART_pcSendStringGlobal=USART_pcSendString;
			SET_BIT(UCSRB,UCSRB_UDRIE);//PIE of Data Register Empty
		}
		Interrupt_u8SRC=Empty_forSendCharInString;
	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

u8 USART_voidReceiveCharSynch(u8 * UDR_Value)
{
	u8 Local_u8ErrorState=OK;
	u32 Local_u32Counter=0;
	while((GET_BIT(UCSRA,UCSRA_RXC)==0)&&(Local_u32Counter!=USART_TIME_OUT))//Stay Here while Receive Buffer is completly received
	{
		Local_u32Counter++;
	}
	if(Local_u32Counter==USART_TIME_OUT)
	{
		Local_u8ErrorState=NOK;
	}
	else
	{
		*UDR_Value=UDR;
	}
	/*while(GET_BIT(UCSRA,UCSRA_RXC)==0);
	return UDR;*/
	return Local_u8ErrorState;
}

void USART_u8SendStringSynch(char* USART_pcSendString)
{
	u8 Local_u8Iterator=0;
	while(USART_pcSendString[Local_u8Iterator] != '\0')
	{
		USART_voidSendCharSynch(USART_pcSendString[Local_u8Iterator]);
		Local_u8Iterator++;
	}

}

u8 USART_u8ReceiveCharAsynch(u8  *Copy_u8Data,void(*Copy_pvNotificationFUNC)(void))
{
	u8 Local_u8ErrorState=OK;
	if(USART_STATE==IDLE)
	{

		USART_STATE=BUSY;
		if(Copy_pvNotificationFUNC==NULL)
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			USART_pvCallBackNotificationFUNCReceivedChar=Copy_pvNotificationFUNC;
			Received_data=Copy_u8Data;
			SET_BIT(UCSRB,UCSRB_RXCIE);
		}
		Interrupt_u8SRC=Received_Char_Complete;
	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

void USART_u8ReceiveBufferSynch(u8* Buffer_Container,u8 Buffer_Size)
{
	u8 Local_u8Iterator,Local_u8Data;
	for(Local_u8Iterator=0;Local_u8Iterator<Buffer_Size;Local_u8Iterator++)
	{
		Local_u8Data=Buffer_Container[Local_u8Iterator];
		USART_voidReceiveCharSynch(&Local_u8Data);
	}
}

u8 USART_u8ReceiveBufferAsynch(u8* Buffer_Container,u8 Buffer_Size,void(*Copy_pvNotificationFUNC)(void))
{
	u8 Local_u8ErrorState=OK;
	if(USART_STATE==IDLE)
	{

		USART_STATE=BUSY;
		if(Copy_pvNotificationFUNC==NULL)
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			USART_pvCallBackNotificationFUNCReceivedBuffer=Copy_pvNotificationFUNC;
			Buffer_Size_Global=Buffer_Size;
			Buffer_Container_Global=Buffer_Container;
			SET_BIT(UCSRB,UCSRB_RXCIE);
		}
		Interrupt_u8SRC=Received_CharInBuffer_Complete;
	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}


void __vector_13 (void)   __attribute__((signal)); //ISR of Received Complete
void __vector_13 (void)
{
	static u8 Local_u8Iterator=0;
	if (Interrupt_u8SRC==Received_Char_Complete)
	{
		if(USART_pvCallBackNotificationFUNCReceivedChar!=NULL)
		{
			USART_pvCallBackNotificationFUNCReceivedChar();
			*Received_data=UDR;
			CLR_BIT(UCSRB,UCSRB_RXCIE);
			USART_STATE=IDLE;
		}
		else
		{
			//DoNothing
		}
	}
	else if (Interrupt_u8SRC==Received_CharInBuffer_Complete)
	{
		if (USART_pvCallBackNotificationFUNCReceivedBuffer!=NULL)
		{
			Buffer_Container_Global[Local_u8Iterator]=UDR;
			USART_pvCallBackNotificationFUNCReceivedBuffer();
			Local_u8Iterator++;
			USART_STATE=IDLE;
			if(Local_u8Iterator==Buffer_Size_Global)
			{
				CLR_BIT(UCSRB,UCSRB_RXCIE);
				Local_u8Iterator=0;

			}
		}
		else
		{
			//Do nothing
		}
	}
}

void __vector_14 (void)   __attribute__((signal)); //ISR of Data Register Empty
void __vector_14 (void)
{
	static u8 Local_u8Iterator=0;
	if ((USART_pvCallBackNotificationFUNC!=NULL) || (USART_pvCallBackNotificationFUNCString!=NULL))
	{
		if(Interrupt_u8SRC==Empty_forSendChar)
		{
			USART_pvCallBackNotificationFUNC();
			UDR=USART_pu8Data;
			CLR_BIT(UCSRB,UCSRB_UDRIE);//PIE of Data Register Empty
			USART_STATE=IDLE;
		}
		else if (Interrupt_u8SRC==Empty_forSendCharInString)
		{
			if (USART_pcSendStringGlobal[Local_u8Iterator]!='\0')
			{
				USART_pvCallBackNotificationFUNCString();
				USART_voidSendCharSynch(USART_pcSendStringGlobal[Local_u8Iterator]);
				Local_u8Iterator++;
				USART_STATE=IDLE;
			}
			else
			{
				CLR_BIT(UCSRB,UCSRB_UDRIE);//PIE of Data Register Empty
				Local_u8Iterator=0;
			}
		}
	}
	else
	{
		//DoNothing
	}
}
