/*****************************************/
/*****************************************/
/***************  MHAL LAYER  ************/
/***************  A.NABIL    *************/
/***************  ADC_PROGRAM_C_  ********/
/*****************************************/
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"

static u16 * ADC_pu16Reading=NULL;
static void (*ADC_pvCallBackNotificationFUNC)(void) = NULL;


static u8 *ADC_pu8Chain_ChannelArr=NULL;      //Global Variables to carry Chain Array
static u8 ADC_pu8Chain_Size;                  //Global Variable to Carry number of Channels
static u16*ADC_pu16Chain_ResultArray=NULL;    //Global variable to carry Chain Read
static u8 ADC_u8ChainConversionIndex=0;       //Global Variable to carry the Current Conversion Index

static u8 ADC_u8ISRsource;

u8 ADC_u8Busy_State=IDLE;

void ADC_voidInit(void)
{
	/*AVCC as Reference voltage*/
#if AREF_VOLTAGE==AVCC

	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif AREF_VOLTAGE==External

	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif AREF_VOLTAGE==Internal

	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);

#endif

#if Data_Result==Left_Adj
	/*Activate Left Adjust Register*/
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif Data_Result==Right_Adj
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#endif
	/*Set Prescalar*/ //BIT MASKING
	ADCSRA &= PreScalar_Masking;
	ADCSRA |= Prescalar_Factor;

	/*Enable Peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	/*if Auto Trigger*/
#if (AUTO_Trigger==enabled) && (ADC_Trigger==Free_Running)
	/*Clear the MUX Bits in ADMUX REG*/
	ADMUX &= InputChannel_Masking;

	/*SET the required channel into the MUX Bits*/
	ADMUX |= Input_Channel;//BIT MASKING

	CLR_BIT(SFIOR,SFIOR_ADTS0);
	CLR_BIT(SFIOR,SFIOR_ADTS1);
	CLR_BIT(SFIOR,SFIOR_ADTS2);


	SET_BIT(ADCSRA,ADCSRA_ADIE);   //Interrupt enable
	SET_BIT(ADCSRA,ADCSRA_ADATE);  //Auto trigger enable
	SET_BIT(ADCSRA,ADCSRA_ADSC);   //Start Conversion For the First Time Only
#endif

}


u16 ADC_u16StartConversionSynch(u8 Copy_u8Channel , u16* Copy_Ptru16Reading)
{
	u8 ReadingContainer = BITS_READ;
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=OK;
	if (ADC_u8Busy_State==IDLE)
	{
		/*ADC is now BUSY*/
		ADC_u8Busy_State=BUSY;
		/*Clear the MUX Bits in ADMUX REG*/
		ADMUX &= InputChannel_Masking;

		/*SET the required channel into the MUX Bits*/
		ADMUX |= Copy_u8Channel;//BIT MASKING
#if AUTO_Trigger == disabled //POLLING
		/*Start Conversion*/ //single conversion
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*Polling (busy waiting) until the conversion complete flag is set OR Counter reaching TimeOUT Value*/
		while(((GET_BIT(ADCSRA,ADCSRA_ADIF))==0) && (Local_u32Counter!= ADC_u32TimeOUT) )
		{
			Local_u32Counter++;
		}

		if (Local_u32Counter==ADC_u32TimeOUT)
		{
			//loop is broken because the time out is reached
			Local_u8ErrorState=NOK;
		}
		else
		{
			//Loop is broken because flag is raised
			/*Clear the conversion complete flag*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);

			if(ReadingContainer == 1) //_8_BITS
			{
				/*Return the reading*/
				*Copy_Ptru16Reading =  ADCH;
			}
			else if(ReadingContainer == 2)//_10_BITS
			{
				*Copy_Ptru16Reading = ADC_DATA;
			}
			/*ADC is finished , return it to IDLE*/
			ADC_u8Busy_State=IDLE;
		}


#endif
	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}

	return Local_u8ErrorState;

}




u16 ADC_u16StartConversionAsynch(u8 Copy_u8Channel , u16* Copy_Ptru16Reading,void(*Copy_pvNotificationFUNC)(void))
{
	u8 Local_u8ErrorState;

	if(ADC_u8Busy_State==IDLE)
	{
		if((Copy_Ptru16Reading == NULL) ||( Copy_pvNotificationFUNC == NULL))
		{
			Local_u8ErrorState= NULL_POINTER;
		}
		else
		{
			/*Make ADC Busy in order not to work until be idle*/
			ADC_u8Busy_State=BUSY;

			/*Make ISR source Single Channel Asynchronous*/
			ADC_u8ISRsource=SingleChannelAsynch;

			/*Initialize the reading variable globally*/
			ADC_pu16Reading = Copy_Ptru16Reading;
			/*Initialize the call back notification function globally*/
			ADC_pvCallBackNotificationFUNC=Copy_pvNotificationFUNC;
			/*Clear the MUX Bits in ADMUX REG*/
			ADMUX &= InputChannel_Masking;

			/*SET the required channel into the MUX Bits*/
			ADMUX |= Copy_u8Channel;//BIT MASKING

			/*Start Conversion*/ //single conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);


			/*ADC Interrupt Enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}
	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

s32 Mapping(s32 Input_MIN,s32 Input_MAX,s32 Output_MIN,s32 Output_MAX,s32 Input_Value)//A function of a straight line
{
	return (((Output_MAX-Output_MIN)*(Input_Value-Input_MIN))/(Input_MAX-Input_MIN))+(Output_MIN);
}



u8 ADC_u8StartChainAsynchronous(Chain_t *Copy_Chain)
{
	u8 Local_u8ErrorState=OK;
	/*Check NULL pointer*/
	if(Copy_Chain==NULL)
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	else
	{
		if (ADC_u8Busy_State==IDLE)
		{
			/*Make ADC BUSY*/
			ADC_u8Busy_State=BUSY;

			/*Make ISR source Chain Asynchronous*/
			ADC_u8ISRsource=ChainAsynch;

			/*Initialize Chain Channel Array*/
			ADC_pu8Chain_ChannelArr=Copy_Chain->Channel;

			/*Initialize Result Array*/
			ADC_pu16Chain_ResultArray=Copy_Chain->Result;

			/*Initialize Chain Size*/
			ADC_pu8Chain_Size=Copy_Chain->Chain_Size;

			/*Initialize Notification Function*/
			ADC_pvCallBackNotificationFUNC=Copy_Chain->Notification_FUNC;

			/*Initialize Current Conversion Index*/
			ADC_u8ChainConversionIndex=0;

			/*Set the Required Channel (first channel)*/
			ADMUX &= 0b11100000;
			ADMUX |= ADC_pu8Chain_ChannelArr[ADC_u8ChainConversionIndex]; // first channel index=0
			/*Start Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*Enable Conversion Complete Interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			Local_u8ErrorState=BUSY_FUNC;
		}

	}

	return Local_u8ErrorState;
}

void __vector_16 (void)   __attribute__((signal));
void __vector_16 (void)
{
	u8 ReadingContainer=BITS_READ;

	if(ADC_u8ISRsource==SingleChannelAsynch)
	{
		/*Read ADC Result*/
		if(ReadingContainer == 1) //_8_BITS
		{
			/*Return the reading*/
			*ADC_pu16Reading =  ADCH;
		}
		else if(ReadingContainer == 2)//_10_BITS
		{
			*ADC_pu16Reading = ADC_DATA;
		}

		/*Make ADC_State be IDLE because it finished*/
		ADC_u8Busy_State=IDLE;

		/*Invoke the call back notification function*/
		ADC_pvCallBackNotificationFUNC();

		/*Disable ADC conversion complete interrupt*/
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else if(ADC_u8ISRsource==ChainAsynch)/*ISR source is Chain*/
	{
		/*Read the current conversion*/
		if(ReadingContainer == 1) //_8_BITS
		{
			/*Return the reading*/
			ADC_pu16Chain_ResultArray[ADC_u8ChainConversionIndex] =  ADCH;
		}
		else if(ReadingContainer == 2)//_10_BITS
		{
			ADC_pu16Chain_ResultArray[ADC_u8ChainConversionIndex] = ADC_DATA;
		}

		/*Increment chain index*/
		ADC_u8ChainConversionIndex++;

		/*Check chain is finished or not*/
		if (ADC_u8ChainConversionIndex==ADC_pu8Chain_Size)
		{
			/*chain is finished*/
			/*Make ADC IDLE*/
			ADC_u8Busy_State=IDLE;

			/*Invoke the call back notification function*/
			ADC_pvCallBackNotificationFUNC();

			/*Disable ADC conversion complete interrupt*/
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			/*chain is not finished*/
			/*Set the new required channel*/
			ADMUX &= 0b11100000;
			ADMUX |= ADC_pu8Chain_ChannelArr[ADC_u8ChainConversionIndex];

			/*Start new Conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
	}
}













