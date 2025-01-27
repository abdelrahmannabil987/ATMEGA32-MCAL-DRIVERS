#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "CLCD_interface.h"

void ICU_software(void);

static u16 period_Ticks=0;
static u16 ON_Ticks=0;


void main(void)
{
	PORT_voidInit();
	EXTI_u8Int0SetCallBack(&ICU_software);
	EXTI_voidInt0INIT();

	TIMER1_voidInit();

	CLCD_voidInit_BitMode();
	TIMER0_voidInit();
	Duty_CycleFastPWM_SOT_COC(25);
	PreScalar();
	GIE_voidEnable();
/*
	CLCD_voidGoToXY(0,0);
	CLCD_voidsendstring("iam iam");*/
	while(1)
	{
		//Wait until period ticks and on ticks are measured
		while((period_Ticks == 0 )&&( ON_Ticks == 0 ));

		CLCD_voidGoToXY(0,0);
		CLCD_voidsendstring("Period_Ticks=");
		CLCD_voidwriteNumber(period_Ticks);
		CLCD_voidGoToXY(1,0);
		CLCD_voidsendstring("ON_Ticks=");
		CLCD_voidwriteNumber(ON_Ticks);

		while(1);
	}
}



void ICU_software(void)
{
	static u8 Local_u8Counter=0;

	Local_u8Counter++;
	if (Local_u8Counter==1)//first rising edge
	{
		TIMER1_voidSetTimerValue(0);
	}
	else if (Local_u8Counter==2)//second rising edge
	{
		period_Ticks=Timer1_u16ReadTimerValue();
		/*Change trigger for falling edge*/
		EXTI_u8Int0SerSenseControl(FALLING_EDGE);
	}
	else if(Local_u8Counter==3)
	{
		ON_Ticks=Timer1_u16ReadTimerValue();		/*Timer reading now is period ticks+on ticks*/
		ON_Ticks-=period_Ticks;

		/*Disable INT0 Interrupt*/
		EXTI_u8DisableInterrupt(INT0);
	}
}






