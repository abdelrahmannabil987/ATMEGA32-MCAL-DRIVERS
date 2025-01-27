/************************************/
/************************************/
/********    MCAL Layer *************/
/********    MCAL Layer *************/
/********    SWC:PORT   *************/
/************************************/
/************************************/


#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_


/*this marcos are in private not config file because these macros helps me not options for user and not accessable to him*/
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)   CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0


#define PORTA_DIR     CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR     CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR     CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR     CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)

#define PORTA_InitialValue     CONC(PORTA_PIN7_InitialValue,PORTA_PIN6_InitialValue,PORTA_PIN5_InitialValue,PORTA_PIN4_InitialValue,PORTA_PIN3_InitialValue,PORTA_PIN2_InitialValue,PORTA_PIN1_InitialValue,PORTA_PIN0_InitialValue)
#define PORTB_InitialValue     CONC(PORTB_PIN7_InitialValue,PORTB_PIN6_InitialValue,PORTB_PIN5_InitialValue,PORTB_PIN4_InitialValue,PORTB_PIN3_InitialValue,PORTB_PIN2_InitialValue,PORTB_PIN1_InitialValue,PORTB_PIN0_InitialValue)
#define PORTC_InitialValue     CONC(PORTC_PIN7_InitialValue,PORTC_PIN6_InitialValue,PORTC_PIN5_InitialValue,PORTC_PIN4_InitialValue,PORTC_PIN3_InitialValue,PORTC_PIN2_InitialValue,PORTC_PIN1_InitialValue,PORTC_PIN0_InitialValue)
#define PORTD_InitialValue     CONC(PORTD_PIN7_InitialValue,PORTD_PIN6_InitialValue,PORTD_PIN5_InitialValue,PORTD_PIN4_InitialValue,PORTD_PIN3_InitialValue,PORTD_PIN2_InitialValue,PORTD_PIN1_InitialValue,PORTD_PIN0_InitialValue)








#endif
