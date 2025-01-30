/************************************/
/************************************/
/********    MCAL Layer *************/
/********    MCAL Layer *************/
/********    SWC:PORT   *************/
/************************************/
/************************************/


#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_


/*choose 0 for input 
         1 for output*/

#define PORTA_PIN0_DIR      1
#define PORTA_PIN1_DIR      0
#define PORTA_PIN2_DIR      0
#define PORTA_PIN3_DIR      0
#define PORTA_PIN4_DIR      0
#define PORTA_PIN5_DIR      0
#define PORTA_PIN6_DIR      0
#define PORTA_PIN7_DIR      0
					       
					       
					       
#define PORTB_PIN0_DIR      0
#define PORTB_PIN1_DIR      0
#define PORTB_PIN2_DIR      0
#define PORTB_PIN3_DIR      0
#define PORTB_PIN4_DIR      0      /*SS PIN input floating at Slave*/
#define PORTB_PIN5_DIR      0      /*MOSI: Master o/p salve i/p*/
#define PORTB_PIN6_DIR      1      /*MISO: Master i/p slave o/p*/
#define PORTB_PIN7_DIR      0      /*SCK : i/p at Slave*/
					       
					       
#define PORTC_PIN0_DIR      0
#define PORTC_PIN1_DIR      0
#define PORTC_PIN2_DIR      0
#define PORTC_PIN3_DIR      0
#define PORTC_PIN4_DIR      0
#define PORTC_PIN5_DIR      0
#define PORTC_PIN6_DIR      0
#define PORTC_PIN7_DIR      0
					       
					       
					       
#define PORTD_PIN0_DIR      0 
#define PORTD_PIN1_DIR      0
#define PORTD_PIN2_DIR      0
#define PORTD_PIN3_DIR      0
#define PORTD_PIN4_DIR      0
#define PORTD_PIN5_DIR      0
#define PORTD_PIN6_DIR      0
#define PORTD_PIN7_DIR      0



/************************  INITIAL_VALUE  ********************/

/*if direction is input so 0 if floating 1 for pullup resistor
  if direction is output so 0 is low 1 is high*/

#define PORTA_PIN0_InitialValue      0
#define PORTA_PIN1_InitialValue      0
#define PORTA_PIN2_InitialValue      0
#define PORTA_PIN3_InitialValue      0
#define PORTA_PIN4_InitialValue      0
#define PORTA_PIN5_InitialValue      0
#define PORTA_PIN6_InitialValue      0
#define PORTA_PIN7_InitialValue      0
				    
#define PORTB_PIN0_InitialValue      0 
#define PORTB_PIN1_InitialValue      0
#define PORTB_PIN2_InitialValue      0
#define PORTB_PIN3_InitialValue      0
#define PORTB_PIN4_InitialValue      0
#define PORTB_PIN5_InitialValue      0
#define PORTB_PIN6_InitialValue      0
#define PORTB_PIN7_InitialValue      0
				     
#define PORTC_PIN0_InitialValue      0 
#define PORTC_PIN1_InitialValue      0
#define PORTC_PIN2_InitialValue      0
#define PORTC_PIN3_InitialValue      0
#define PORTC_PIN4_InitialValue      0
#define PORTC_PIN5_InitialValue      0
#define PORTC_PIN6_InitialValue      0
#define PORTC_PIN7_InitialValue      0
				    
#define PORTD_PIN0_InitialValue      0 
#define PORTD_PIN1_InitialValue      0
#define PORTD_PIN2_InitialValue      0
#define PORTD_PIN3_InitialValue      0
#define PORTD_PIN4_InitialValue      0
#define PORTD_PIN5_InitialValue      0
#define PORTD_PIN6_InitialValue      0
#define PORTD_PIN7_InitialValue      0
					       

#endif
