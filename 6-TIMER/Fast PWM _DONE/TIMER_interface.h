/**************************************************************/
/**************************************************************/
/********************* AUTHOR: A.NABIL ************************/
/********************* LAYER : MCAL    ************************/
/********************* SWC : TIMER_H_  ********************/
/**************************************************************/
/**************************************************************/


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_



#define Periodic_delay     0
#define Non_Periodic_delay 1



void TIMER0_voidInit(void);

u8 TIMER0_u8SetCallBack_OF(void(*Copy_pvCallBackFUNC)(void));
u8 TIMER0_u8SetCallBack_CTC(void(*Copy_pvCallBackFUNC)(void));

void TIMER0_voidSetCompareMatchValue(u8 Copy_u8Value);

void TIMER0_voidSetPreLoadValue(u8 Copy_u8Preload);
u8 TIMER0_Delay_ms(u32 Copy_u16Delay_ms,void(*fnafterdelay)(void),u8 periodicity);

void TIMER1_voidSetTimerValue(u16 Copy_u16value);
u16 Timer1_u16ReadTimerValue(void);

void PreScalar(void);

void TIMER1_voidInit(void);
void Timer1_voidSetICR_TopValue(u16 Copy_u16TOP);
void Timer1_voidSetChannelA_Compare_Match(u16 Copy_u16Compare_Match);

void ICU_voidInit(void);
u8   ICU_voidSetTriggerEdge(u8 Copy_u8Edge);

#define ICU_RisingEdge  0
#define ICU_FallingEdge 1

void ICU_voidEnableInterrupt(void);
void ICU_voidDisableInterrupt(void);
u16  ICU_u16ReadInputCaptureREG(void);
u8 ICU_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));
#endif 
