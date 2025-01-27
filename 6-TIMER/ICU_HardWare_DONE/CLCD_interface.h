/************************************************/
/************************************************/
/*****************   A.NABIL   ******************/
/*****************   HAL       ******************/
/*****************   CLCD      ******************/
/************************************************/
/************************************************/



#ifndef CLCD_INTERFACE_H_ 
#define CLCD_INTERFACE_H_



void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);



void CLCD_voidInit_BitMode(void);

void CLCD_voidsendstring(const char * copy_pcstring);//ascii so char


void CLCD_voidGoToXY(u8 Copy_u8Xpos, u8 Copy_u8Ypos);

void CLCD_voidwritespecialcharacter(u8 * copy_pu8pattern,u8 copy_u8patternNumber,u8 copy_u8XPos,u8 copy_u8YPos);

void CLCD_voidwriteNumber(u32 copy_u32Number);

void CLCD_voidSaveSpecialCharacterToCGRAM(u8 * copy_pu8pattern,u8 copy_u8patternNumber);


#endif 
