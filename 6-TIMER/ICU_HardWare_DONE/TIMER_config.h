/**************************************************************/
/**************************************************************/
/********************* AUTHOR: A.NABIL ************************/
/********************* LAYER : MCAL    ************************/
/********************* SWC : TIMER_H_  ********************/
/**************************************************************/
/**************************************************************/


#ifndef CONFIG_H_
#define CONFIG_H_

/*Choosing Timer
 Options:
 1-TIMER0
 2-TIMER1
 3-TIMER3*/

#define TIMER TIMER0

/*                   Macros for TIMER0                    */

/*Choose the wave form generation "Timer/Counter Mode Of Operation"
 * Options :
  1-Normal_Mode
  2-CTC  "Clear Time on Compare Match"
  3-Fast_PWM
  4-Phase_Correct_PWM
  5-DELAY  //use TIMER0 as Function Delay
  */
#define Operation_Mode Fast_PWM



/*Choosing PreScalar Value in TIMER 0
  Options :
  1-NO_CLK_SRC
  2-NO_PRESCALAR
  3-DIVISION_BY_8
  4-DIVISION_BY_64
  5-DIVISION_BY_256
  6-DIVISION_BY_1024
  7-EXTERNAL_FALLING_EDGE
  8-EXTERNAL_RISING_EDGE
 */

#define PreScalar_Value  DIVISION_BY_8

#if Operation_Mode == Fast_PWM
/*Fast PWM Mode
 OPTIONS:
 1-COT_SOC   clear OC0 at TOP , Set OC0 on compare match //INVERTED MODE
 2-SOT_COC   set OC0 at TOP , clear OC0 on compare match //NON_INVERTED MODE
 */
#define Fast_PWM_MODE SOT_COC
#endif

#endif



