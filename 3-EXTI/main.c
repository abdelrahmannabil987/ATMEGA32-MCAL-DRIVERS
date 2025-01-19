#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "util/delay.h"

void INT1_ISR(void);

void main(void)
{
	PORT_voidInit();

	EXTI_u8Int1SerSenseControl(FALLING_EDGE);
	EXTI_u8IntEnable(INT1_PIE);
	GIE_voidEnable();
	EXTI_u8Int1SetCallBack(INT1_ISR);
	while(1)
	{}
}

void INT1_ISR(void)
{
	while(1)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		_delay_ms(300);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		_delay_ms(300);
	}
}
