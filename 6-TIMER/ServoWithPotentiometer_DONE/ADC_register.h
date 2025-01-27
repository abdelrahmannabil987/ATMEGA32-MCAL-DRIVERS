/*****************************************/
/*****************************************/
/***************  MHAL LAYER  ************/
/***************  A.NABIL    *************/
/***************  ADC_REGISTER_H_ ********/
/*****************************************/
/*****************************************/


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_


#define ADMUX      *((volatile u8*)0x27) //ADc MULTIPLICTION SELECTION REGISTER
                                         
#define ADMUX_REFS1          7           //Reference Selection Bit1
#define ADMUX_REFS0          6           //Reference Selection Bit0
#define ADMUX_ADLAR          5           //ADC left adjust result

#define ADCSRA      *((volatile u8*)0x26)  //ADC control status register A

#define ADCSRA_ADEN       7      //ADC Enable
#define ADCSRA_ADSC       6      //Start Conversion (take a screen shot of the current analog value (one time))
#define ADCSRA_ADATE      5      //ADC AUTO trigger Enable (another src triggers the ADC like interrupt)
#define ADCSRA_ADIF       4      //Interrupt Flag
#define ADCSRA_ADIE       3      //Interrupt Enable
#define ADCSRA_ADPS2      2      //Prescalar Bit2
#define ADCSRA_ADPS1      1      //Prescalar Bit1
#define ADCSRA_ADPS0      0      //Prescalar Bit0


#define ADCH     *((volatile u8*)0x25)     //ADC High Register
#define ADCL      *((volatile u8*)0x24)    //ADC Low Register

#define SFIOR     *((volatile u8*)0x50)    //Special Function Register to choose the Auto Trigger Source
#define SFIOR_ADTS0   5
#define SFIOR_ADTS1   6
#define SFIOR_ADTS2   7


#define ADC_DATA *((volatile u16*)0x24)









#endif
