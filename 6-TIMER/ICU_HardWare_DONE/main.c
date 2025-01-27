#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include "CLCD_interface.h"

void ICU_HardWare(void);



static u16 period_Ticks=0;
static u16 ON_Ticks=0;


void main(void)
{
	PORT_voidInit();
	ICU_voidInit();
	ICU_u8SetCallBack(&ICU_HardWare);

	TIMER1_voidInit();

	CLCD_voidInit_BitMode();
	TIMER0_voidInit();
	Duty_CycleFastPWM_SOT_COC(25);
	PreScalar();
	GIE_voidEnable();


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

void ICU_HardWare(void)
{

	static u16 Reading1,Reading2,Reading3;
	static u8 Local_u8Counter=0;
	Local_u8Counter++;
	if(Local_u8Counter==1)
	{
		Reading1=ICU_u16ReadInputCaptureREG();
	}
	else if(Local_u8Counter==2)
	{
		Reading2=ICU_u16ReadInputCaptureREG();
		period_Ticks=Reading2-Reading1;
		ICU_voidSetTriggerEdge(ICU_FallingEdge);
	}
	else if(Local_u8Counter==3)
	{
		Reading3=ICU_u16ReadInputCaptureREG();
		ON_Ticks=Reading3-Reading2;
		ICU_voidDisableInterrupt();
	}
}





