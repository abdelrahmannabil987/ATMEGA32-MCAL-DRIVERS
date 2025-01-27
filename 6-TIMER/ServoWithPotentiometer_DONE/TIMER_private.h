/**************************************************************/
/**************************************************************/
/********************* AUTHOR: A.NABIL ************************/
/********************* LAYER : MCAL    ************************/
/********************* SWC : TIMER_H_  ********************/
/**************************************************************/
/**************************************************************/

#ifndef PRIVATE_H_
#define PRIVATE_H_


#define TIMER0     1
#define TIMER1     2
#define TIMER2     3



#define Normal_Mode              1
#define CTC                      2
#define Fast_PWM                 3
#define Phase_Correct_PWM        4
#define DELAY                    5


#define COT_SOC   1     /*clear OC0 at TOP , Set OC0 on compare match*/
#define SOT_COC   2     /*set OC0 at TOP , clear OC0 on compare match*/

#define NO_CLK_SRC                0
#define NO_PRESCALAR              1
#define DIVISION_BY_8             2
#define DIVISION_BY_64            3
#define DIVISION_BY_256           4
#define DIVISION_BY_1024          5
#define EXTERNAL_FALLING_EDGE     6
#define EXTERNAL_RISING_EDGE      7

#endif
