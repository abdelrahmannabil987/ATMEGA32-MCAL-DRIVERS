#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "TIMER_interface.h"
#include "util/delay.h"




void main(void)
{
	PORT_voidInit();
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
	/*watch dog sleep in 1 sec*/
	WDT_voidEnable();
	WDT_voidSleep(7);
	/*watch dog disable*/
	//WDT_voidDisable();
	while(1);
}





