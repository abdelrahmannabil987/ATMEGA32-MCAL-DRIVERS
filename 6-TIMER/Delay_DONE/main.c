#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
void LED(void);
void main(void)
{
	PORT_voidInit();
	TIMER0_Delay_ms(1000,&LED,Periodic_delay);
	GIE_voidEnable();
	while(1)
	{}
}



void LED(void)
{
	static u8 state=DIO_u8PIN_HIGH;
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,state);
	if(state==DIO_u8PIN_LOW)
	{
		state=DIO_u8PIN_HIGH;
	}
	else if(state==DIO_u8PIN_HIGH)
	{
		state=DIO_u8PIN_LOW;
	}

}

