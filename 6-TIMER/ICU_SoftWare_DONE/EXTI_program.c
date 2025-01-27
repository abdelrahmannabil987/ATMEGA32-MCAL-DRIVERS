/*****************************************/
/*****************************************/
/***************  MHAL LAYER  *************/
/***************  A.NABIL    *************/
/***************  EXTI_PROGRAM **********/
/*****************************************/
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "DIO_interface.h"

/*Global Pointer To Function to hold INT0 ISR address*/
void (*EXTI_pvINT0FUNC)(void)=NULL;

/*Global Pointer To Function to hold INT1 ISR address*/
void (*EXTI_pvINT1FUNC)(void)=NULL;

/*Global Pointer To Function to hold INT2 ISR address*/
void (*EXTI_pvINT2FUNC)(void)=NULL;



/*******************************************************************************/
/*******************************************************************************/
/********************    PREBUILD CONFIGURATION   ******************************/
/************************                      *********************************/
/*********************************    ******************************************/
/*******************************************************************************/

void EXTI_voidInt0INIT(void)
{
	/*Peripheral interrupt control(SIE) for INT0*/
#if INT0_Sense==FALLING_EDGE

	/*Set sense control for INT0 to falling edge*/

	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);


#elif INT0_Sense==ON_CHANGE

	/*Set sense control for INT0 to be on change*/
	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_Sense==LOW_LEVEL

	/*Set sense control for INT0 to low level*/
	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_Sense==RISING_EDGE

	/*Set sense control for INT0 to rising edge*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#else
#error "Wrong INT0 Sense Configuration Option"
#endif
	/* Check PIE Initial State*/
#if INT0_INITIAL_STATE==Enable
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE==Disnable
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE Configuration Option"
#endif
}


void EXTI_voidInt1INIT(void)
{
	/*Peripheral interrupt control(SIE) for INT1*/
#if INT1_Sense==FALLING_EDGE

	/*Set sense control for INT1 to falling edge*/

	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);


#elif INT1_Sense==ON_CHANGE

	/*Set sense control for INT1 to be on change*/
	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_Sense==LOW_LEVEL

	/*Set sense control for INT1 to low level*/
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_Sense==RISING_EDGE

	/*Set sense control for INT1 to rising edge*/
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);
#else
#error "Wrong INT1 Sense Configuration Option"
#endif


	/* Check PIE Initial State*/
#if INT1_INITIAL_STATE==Enable
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE==Disnable
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong INT1_INITIAL_STATE Configuration Option"
#endif
}




void EXTI_voidInt2INIT(void)
{
	/*Peripheral interrupt control(SIE) for INT2*/
#if INT2_Sense==FALLING_EDGE

	/*Set sense control for INT2 to falling edge*/
	CLR_BIT(MCUCSR,MCUCSR_INT2);

#elif INT2_Sense==RISING_EDGE

	/*Set sense control for INT2 to rising edge*/
	SET_BIT(MCUCSR,MCUCSR_INT2);

#else
#error "Wrong INT2 Sense Configuration Option"
#endif


	/* Check PIE Initial State*/
#if INT2_INITIAL_STATE==Enable
	SET_BIT(GICR,GICR_INT2);
#elif INT2_INITIAL_STATE==Disable
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong INT2_INITIAL_STATE Configuration Option"
#endif
}


u8 EXTI_u8EnableInterrupt(u8 Copy_u8IntNum)
{
	u8 Local_u8ErrorState=OK;
	if(Copy_u8IntNum>INT2 && Copy_u8IntNum<INT1)
	{/*Set the required bit*/
	SET_BIT(GICR,Copy_u8IntNum);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}


u8 EXTI_u8DisableInterrupt(u8 Copy_u8IntNum)
{
	u8 Local_u8ErrorState=OK;
	if((Copy_u8IntNum>INT2) && (Copy_u8IntNum<INT1))
	{/*Clear the required bit*/
	CLR_BIT(GICR,Copy_u8IntNum);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

/*******************************************************************************/
/*******************************************************************************/
/********************    POST BUILD CONFIGURATION   ******************************/
/************************                      *********************************/
/*********************************    ******************************************/
/*******************************************************************************/


u8 EXTI_u8Int0SerSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Sense)
	{
	case FALLING_EDGE:SET_BIT(MCUCR,MCUCR_ISC01);CLR_BIT(MCUCR,MCUCR_ISC00);break;
	case RISING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC01);SET_BIT(MCUCR,MCUCR_ISC00);break;
	case ON_CHANGE:CLR_BIT(MCUCR,MCUCR_ISC01);SET_BIT(MCUCR,MCUCR_ISC00);break;
	case LOW_LEVEL:CLR_BIT(MCUCR,MCUCR_ISC01);CLR_BIT(MCUCR,MCUCR_ISC00);break;
	default : Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}


u8 EXTI_u8Int1SerSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Sense)
	{
	case FALLING_EDGE:SET_BIT(MCUCR,MCUCR_ISC11);CLR_BIT(MCUCR,MCUCR_ISC10);break;
	case RISING_EDGE:CLR_BIT(MCUCR,MCUCR_ISC11);SET_BIT(MCUCR,MCUCR_ISC10);break;
	case ON_CHANGE:CLR_BIT(MCUCR,MCUCR_ISC11);SET_BIT(MCUCR,MCUCR_ISC10);break;
	case LOW_LEVEL:CLR_BIT(MCUCR,MCUCR_ISC11);CLR_BIT(MCUCR,MCUCR_ISC10);break;
	default : Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}


u8 EXTI_u8Int2SerSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Sense)
	{
	case FALLING_EDGE:CLR_BIT(MCUCSR,MCUCSR_INT2);break;
	case RISING_EDGE:SET_BIT(MCUCSR,MCUCSR_INT2);break;

	default : Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}



/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

u8 EXTI_u8IntEnable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState=OK;

	switch(Copy_u8Int)
	{
	case INT0_PIE:	SET_BIT(GICR,GICR_INT0);break;
	case INT1_PIE:	SET_BIT(GICR,GICR_INT1);break;
	case INT2_PIE:	SET_BIT(GICR,GICR_INT2);break;
	default:	 Local_u8ErrorState=NOK;
	}
	return 	Local_u8ErrorState;
}
u8 EXTI_u8IntDisnable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState=OK;

	switch(Copy_u8Int)
	{
	case INT0_PIE:	CLR_BIT(GICR,GICR_INT0);break;
	case INT1_PIE:	CLR_BIT(GICR,GICR_INT1);break;
	case INT2_PIE:	CLR_BIT(GICR,GICR_INT2);break;
	default:	Local_u8ErrorState=NOK;
	}
	return 	Local_u8ErrorState;
}



/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/


/*CALL BACK*/

u8 EXTI_u8Int0SetCallBack(void(*Copy_PVINT0FUNC)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_PVINT0FUNC != NULL)
	{
		EXTI_pvINT0FUNC=Copy_PVINT0FUNC;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}

	return Local_u8ErrorState;
}




u8 EXTI_u8Int1SetCallBack(void(*Copy_PVINT1FUNC)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_PVINT1FUNC != NULL)
	{
		EXTI_pvINT1FUNC=Copy_PVINT1FUNC;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}

	return Local_u8ErrorState;
}




u8 EXTI_u8Int2SetCallBack(void(*Copy_PVINT2FUNC)(void))
{
	u8 Local_u8ErrorState=OK;
	if(Copy_PVINT2FUNC != NULL)
	{
		EXTI_pvINT2FUNC=Copy_PVINT2FUNC;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}

	return Local_u8ErrorState;
}






//ISR of INT0

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_pvINT0FUNC != NULL)
	{

		EXTI_pvINT0FUNC();
	}
	else
	{
		//DO NOTHING
	}
}

//ISR of INT1


void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_pvINT1FUNC != NULL)
	{

		EXTI_pvINT1FUNC();
	}
	else
	{
		//DO NOTHING
	}
}

//ISR of INT2


void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_pvINT2FUNC != NULL)
	{

		EXTI_pvINT2FUNC();
	}
	else
	{
		//DO NOTHING
	}
}
