/************************************/
/************************************/
/********    MCAL Layer *************/
/********    MCAL Layer *************/
/********    SWC:PORT   *************/
/************************************/
/************************************/


#include "STD_TYPES.h"
#include "PORT_register.h"
#include "PORT_config.h"
#include "PORT_private.h"

void  PORT_voidInit(void)
{
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;
	
	PORTA=PORTA_InitialValue;
	PORTB=PORTB_InitialValue;
	PORTC=PORTC_InitialValue;
	PORTD=PORTD_InitialValue;
}
