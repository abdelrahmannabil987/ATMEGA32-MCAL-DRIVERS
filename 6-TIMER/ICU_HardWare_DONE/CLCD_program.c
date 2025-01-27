/************************************************/
/************************************************/
/*****************   A.NABIL   ******************/
/*****************   HAL       ******************/
/*****************   CLCD      ******************/
/************************************************/
/************************************************/


#include "STD_TYPES.h"
#include "util/delay.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"


void CLCD_voidSendCommand(u8 Copy_u8Command)
{
#if MODE==EIGHT_BIT
	/*set RS pin to low ----> Command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	/*set R/W pin to low TO write (instruction write operaion (write instruction code in IR)*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	/*set Command for data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	/*set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
#elif MODE==FOUR_BIT
	/*set RS pin to low ----> Command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	/*set R/W pin to low TO write (instruction write operaion (write instruction code in IR)*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	/*SEND MSB OF COMMAND*/
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin4,(Copy_u8Command&0b00010000)>>4);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin5,(Copy_u8Command&0b00100000)>>5);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin6,(Copy_u8Command&0b01000000)>>6);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin7,(Copy_u8Command&0b10000000)>>7);

	/*set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);


	/*SEND LSB OF COMMAND*/

	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin4,(Copy_u8Command&0b00000001));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin5,(Copy_u8Command&0b00000010)>>1);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin6,(Copy_u8Command&0b00000100)>>2);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin7,(Copy_u8Command&0b00001000)>>3);

	/*set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
#endif
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
#if MODE==EIGHT_BIT
	/*set RS pin to high ----> data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	/*set RW pin to low to write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	/*set command for data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	/*set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

#elif MODE==FOUR_BIT
	/*set RS pin to high ----> data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	/*set R/W pin to low TO write (instruction write operaion (write instruction code in IR)*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	/*SEND MSB OF COMMAND*/
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin4,(Copy_u8Data&0b00010000)>>4);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin5,(Copy_u8Data&0b00100000)>>5);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin6,(Copy_u8Data&0b01000000)>>6);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin7,(Copy_u8Data&0b10000000)>>7);

	/*set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);


	/*SEND LSB OF COMMAND*/

	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin4,(Copy_u8Data&0b00000001));
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin5,(Copy_u8Data&0b00000010)>>1);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin6,(Copy_u8Data&0b00000100)>>2);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin7,(Copy_u8Data&0b00001000)>>3);

	/*set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

#endif
}


void CLCD_voidsendstring(const char * copy_pcstring)//ascii so char
{
	u8 i=0 ;

	/*set command for data pins*/
	while(copy_pcstring[i] !='\0')
	{
		if (i==16)  //to move to the second row
		{
			CLCD_voidGoToXY(1,0);
		}
		CLCD_voidSendData(copy_pcstring[i]);
		i++;
	}
}
void CLCD_voidInit_BitMode(void)
{
	_delay_ms(40);
#if MODE == EIGHT_BIT

	/*Function set command : 2 lines , 5*8 font size*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control : display enable , disable cursor , no blink cursor*/
#if Cursor == Cursor_ON

	CLCD_voidSendCommand(0b00001111);

#elif Cursor == Cursor_OFF
	CLCD_voidSendCommand(0b00001100);

#endif
	/*Clear display*/
	CLCD_voidSendCommand(1);
#endif

#if MODE == FOUR_BIT
	/*Function set command : 2 lines , 5*8 font size*/
	CLCD_voidSendCommand(0b00100010);
	//CLCD_voidSendCommand(0b10000000);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin4,0);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin5,0);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin6,0);
	DIO_u8SetPinValue(CLCD_DATA_PORT,CLCD_DataPin7,1);

	//set enable pulse
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_us(40);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	/*Display on off control : display enable , disable cursor , no blink cursor*/
#if Cursor == Cursor_ON
	CLCD_voidSendCommand(0b00001111);

#elif Cursor == Cursor_OFF

	CLCD_voidSendCommand(0b00001100);

#endif
	/*Clear display*/
	CLCD_voidSendCommand(1);

#endif
}


void CLCD_voidGoToXY(u8 Copy_u8Xpos, u8 Copy_u8Ypos)
{
	u8 Local_u8adress;
	if(Copy_u8Xpos==0)
	{
		/*location for first line*/
		Local_u8adress=Copy_u8Ypos;
	}
	else if (Copy_u8Xpos==1)
	{
		/*location for second line*/
		Local_u8adress=Copy_u8Ypos+0x40;
	}
	CLCD_voidSendCommand(Local_u8adress+128);//to make the 8 bit = 1 in DDRAM Address Command data sheet page 16
}

void CLCD_voidWriteSpecialCharacter(u8 * copy_pu8pattern,u8 copy_u8patternNumber,u8 copy_u8XPos,u8 copy_u8YPos)
{

	/*calculate CGRAM address whose each block is 8 bytes*/
	u8 Local_u8CGRAMaddress , Local_u8Iterator;
	Local_u8CGRAMaddress=copy_u8patternNumber*8;
	/*send CGRAM address command to LCD,with setting set 6 , clearing bit 7 */
	CLCD_voidSendCommand(Local_u8CGRAMaddress+64);

	/*write the pattern into CGRAM*/
	for (Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{

		CLCD_voidSendData(copy_pu8pattern[Local_u8Iterator]);
	}

	/*go back to the DDRAM to display the pattern*/
	CLCD_voidGoToXY(copy_u8XPos,copy_u8YPos);

	/*display  the pattern written in the CGRAM */
	CLCD_voidSendData(copy_u8patternNumber/*value from 0 to 7 will make DDRAM understand that she must get a value from CGRAM*/);
}


void CLCD_voidwriteNumber(u32 copy_u32Number)
{
	u8 arr[8],i,Local_u8Iterator;

	i=7;
	for (Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		if (copy_u32Number<10)
		{
			arr[i]=copy_u32Number;
			break;
		}
		arr[i]=copy_u32Number%10;
		copy_u32Number/=10;
		if (copy_u32Number<10)
		{
			i--;
			arr[i]=copy_u32Number;
			break;
		}
		i--;
	}
	for (Local_u8Iterator=i;Local_u8Iterator<8;Local_u8Iterator++)
	{

		switch (arr[Local_u8Iterator])
		{
		case 0 : CLCD_voidSendData('0');break;
		case 1 : CLCD_voidSendData('1');break;
		case 2 : CLCD_voidSendData('2');break;
		case 3 : CLCD_voidSendData('3');break;
		case 4 : CLCD_voidSendData('4');break;
		case 5 : CLCD_voidSendData('5');break;
		case 6 : CLCD_voidSendData('6');break;
		case 7 : CLCD_voidSendData('7');break;
		case 8 : CLCD_voidSendData('8');break;
		case 9 : CLCD_voidSendData('9');break;
		}
	}


}



void CLCD_voidSaveSpecialCharacterToCGRAM(u8 * copy_pu8pattern,u8 copy_u8patternNumber)
{

	/*calculate CGRAM address whose each block is 8 bytes*/
	u8 Local_u8CGRAMaddress , Local_u8Iterator;
	Local_u8CGRAMaddress=copy_u8patternNumber*8;
	/*send CGRAM address command to LCD,with setting set 6 , clearing bit 7 */
	CLCD_voidSendCommand(Local_u8CGRAMaddress+64);

	/*write the pattern into CGRAM*/
	for (Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{

		CLCD_voidSendData(copy_pu8pattern[Local_u8Iterator]);
	}
}


