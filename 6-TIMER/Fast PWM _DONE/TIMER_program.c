/**************************************************************/
/**************************************************************/
/********************* AUTHOR: A.NABIL ************************/
/********************* LAYER : MCAL    ************************/
/********************* SWC : TIMER_H_  ********************/
/**************************************************************/
/**************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "DIO_interface.h"


static void(*TIMER0_pvCallBackFUNC_OF)(void)=NULL;//Timer/Counter0 Overflow
static void(*TIMER0_pvCallBackFUNC_CompareMatch)(void)=NULL;//Timer/Counter0 CompareMatch
static void(*ExcuteFnAfterDelay)(void)=NULL;
static u32 Delay_ms;
static u8 Checkperiodicity;

static void(*ICU_pvCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{
#if Operation_Mode == Normal_Mode
	/*choose Normal mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);//Normal mode
	CLR_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TIMSK,TIMSK_TOIE0);//overflow interrupt enable
#elif Operation_Mode == CTC
	/*choose CTC mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);//CTC mode
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TIMSK,TIMSK_OCIE0);//compare match interrupt enable
#elif Operation_Mode == Fast_PWM
	/*choose Fast PWM mode */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	// no interrupt in PWM
#if Fast_PWM_MODE == SOT_COC
	/*Set on top  clear  on compare*/
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif Fast_PWM_MODE == COT_SOC
	/*Clear on top Match set on compare*/
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#endif
#elif Operation_Mode == Phase_Correct_PWM
	/*choose Phase_Correct_PWM mode */
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	// no interrupt in phase correct

#endif

}

void TIMER0_voidSetPreLoadValue(u8 Copy_u8Preload)
{
	TCNT0=Copy_u8Preload;
}


void TIMER0_voidSetCompareMatchValue(u8 Copy_u8Value)
{
	OCR0=Copy_u8Value;
}



void PreScalar(void)
{
	/*Choose thePreScalar*/
	TCCR0&=0b11111000;
	TCCR0|=PreScalar_Value;
}


u8 TIMER0_u8SetCallBack_CTC(void(*Copy_pvCallBackFUNC)(void))//Timer/Counter0 CompareMatch
{

	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvCallBackFUNC!=NULL)
	{
		TIMER0_pvCallBackFUNC_CompareMatch=Copy_pvCallBackFUNC;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}

u8 TIMER0_u8SetCallBack_OF(void(*Copy_pvCallBackFUNC)(void))//Timer/Counter0 Overflow
{

	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvCallBackFUNC!=NULL)
	{
		TIMER0_pvCallBackFUNC_OF=Copy_pvCallBackFUNC;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}

u8 TIMER0_Delay_ms(u32 Copy_u16Delay_ms,void(*fnafterdelay)(void),u8 periodicity)
{

	u8 Local_u8ErrorStatus=OK;
	if(fnafterdelay!=NULL)
	{

		CLR_BIT(TCCR0,TCCR0_WGM00);//CTC mode
		SET_BIT(TCCR0,TCCR0_WGM01);
		SET_BIT(TIMSK,TIMSK_OCIE0);//compare match interrupt enable
		OCR0=250;
		TCCR0&=0b11111000;
		TCCR0|=2;
		ExcuteFnAfterDelay=fnafterdelay;
		Delay_ms=Copy_u16Delay_ms*4;
		Checkperiodicity=periodicity;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}


/*
void TIMER1_voidInit(void)
{
	//Setting Fast FWM non inverting mode
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	//setting waveform for Fast FWM
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	//Setting the preScalar
	TCCR1B&=0b11111000;
	TCCR1B|=2;
}
 */
void TIMER1_voidInit(void)
{
	//Setting the preScalar to be 8
	TCCR1B&=0b11111000;
	TCCR1B|=2;
}
void TIMER1_voidSetTimerValue(u16 Copy_u16value)
{
	TCNT1=Copy_u16value;
}

u16 Timer1_u16ReadTimerValue(void)
{
	return TCNT1;
}

void Timer1_voidSetICR_TopValue(u16 Copy_u16TOP)
{
	ICR1=Copy_u16TOP;
}
void Timer1_voidSetChannelA_Compare_Match(u16 Copy_u16Compare_Match)
{
	OCR1A=Copy_u16Compare_Match;
}

/*ICU By HardWare Functions*/
void ICU_voidInit(void)
{

	/*Set Trigger Force to RisingEdge Initially*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);

	/*Enable Input Capture Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}



u8 ICU_voidSetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_u8Edge==ICU_RisingEdge)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(Copy_u8Edge==ICU_FallingEdge)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else
	{
		Local_u8ErrorStatus=NOK;
	}
	return Local_u8ErrorStatus;
}



void ICU_voidEnableInterrupt(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}




u16 ICU_u16ReadInputCaptureREG(void)
{
	return ICR1;
}



void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}



u8 ICU_u8SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if (Copy_pvCallBackFunc != NULL)
	{
		ICU_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}




void __vector_10 (void) __attribute__((signal));//Timer/Counter0 CompareMatch
void __vector_10 (void)
{

	if (TIMER0_pvCallBackFUNC_CompareMatch!=NULL)
	{
		TIMER0_pvCallBackFUNC_CompareMatch();
	}
	//DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);

	if (ExcuteFnAfterDelay!=NULL)
	{static u16 Counter=0;
	Counter++;
	if(Counter==Delay_ms)
	{
		ExcuteFnAfterDelay();
		Counter=0;
		if (Checkperiodicity==Non_Periodic_delay)
		{
			CLR_BIT(TIMSK,TIMSK_OCIE0);//compare match interrupt disable
		}

	}
	}

	else
	{
		//DoNothing
	}
}



void __vector_11(void) __attribute__((signal));//Timer/Counter0 Overflow
void __vector_11(void)
{

	if (TIMER0_pvCallBackFUNC_OF!=NULL)
	{
		TIMER0_pvCallBackFUNC_OF();
	}
}




/*ICU ISR*/
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if (ICU_pvCallBackFunc!=NULL)
	{
		ICU_pvCallBackFunc();
	}

	else
	{
		/*Do nothing*/
	}

}
