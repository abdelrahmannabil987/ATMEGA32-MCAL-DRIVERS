/************************************************/
/************************************************/
/*****************   A.NABIL   ******************/
/*****************   HAL       ******************/
/*****************   CLCD      ******************/
/************************************************/
/************************************************/




#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_ 


#define CLCD_DATA_PORT  DIO_u8PORTA /*Choose Data Port*/
#define CLCD_CTRL_PORT  DIO_u8PORTB /*Choose Ctrl Port (RS-RW-E)*/

#define CLCD_RS_PIN    DIO_u8PIN0
#define CLCD_RW_PIN    DIO_u8PIN1
#define CLCD_E_PIN     DIO_u8PIN2

//#define Array_Size 1  //number of digits in number in write number function

#define CLCD_DataPin4 DIO_u8PIN4
#define CLCD_DataPin5 DIO_u8PIN5
#define CLCD_DataPin6 DIO_u8PIN6
#define CLCD_DataPin7 DIO_u8PIN7


/* Choose Mode FOUR_MODE OR EIGHT_BIT */

#define MODE  FOUR_BIT


/* Choose
 * Cursor_ON for cursor and blink
 * OR
 * Cursor_OFF for no cursor nor blink
 **/

#define Cursor Cursor_OFF

#endif
