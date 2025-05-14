#include "MPORT.h"
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#define DDRA (*((volatile u8*)0x3A))
#define DDRB (*((volatile u8*)0x37))
#define DDRC (*((volatile u8*)0x34))
#define DDRD (*((volatile u8*)0x31))

#define PORTA (*((volatile u8*)0x3B))
#define PORTB (*((volatile u8*)0x38))
#define PORTC (*((volatile u8*)0x35))
#define PORTD (*((volatile u8*)0x32))
#define MODE 1
#define DIRECTION 0

extern u8 PinCfg2 [32][2];
MPORT_enuErrorStatus_t MPORT_enuSetPinDirection( u8 Copy_enuPinNum  ,  u8 Copy_enuPinDirection ){
	 u8 PORTNUM, PINNUM;
	    PORTNUM = (Copy_enuPinNum & 0xF0) >> 4;
	    PINNUM = Copy_enuPinNum & 0x0F;
			MPORT_enuErrorStatus_t Ret_enuError;
			Ret_enuError = MPORT_enuOK;
			//MPORT_enuPinDirection
			if (PORTNUM > MPORT_PORTD)
			{
				Ret_enuError = MPORT_INVALID_PORT;
			}
			else if (PINNUM > MPORT_enuPIN7)
			{
				Ret_enuError = MPORT_INVALID_PIN;
			}
			else if (Copy_enuPinDirection > MPORT_INPUT)
			{
				Ret_enuError = MPORT_INVALID_CONFIG;
			}
			else{
				switch(PORTNUM){
					case MPORT_PORTA:
					if (Copy_enuPinDirection == MPORT_OUTPUT)
					{
						SET_BIT(DDRA,PINNUM);
					}else if (Copy_enuPinDirection == MPORT_INPUT)
					{
						CLR_BIT(DDRA, PINNUM);
					}
					break;
					case MPORT_PORTB :
					if (Copy_enuPinDirection == MPORT_OUTPUT)
					{
						SET_BIT(DDRB,PINNUM);
					}else if (Copy_enuPinDirection == MPORT_INPUT)
					{
						CLR_BIT(DDRB, PINNUM);
					}
					break;
					case MPORT_PORTC:
					if (Copy_enuPinDirection == MPORT_OUTPUT)
					{
						SET_BIT(DDRC,PINNUM);
					}else if (Copy_enuPinDirection == MPORT_INPUT)
					{
						CLR_BIT(DDRC, PINNUM);
					}
					break;
					case MPORT_PORTD:
					if (Copy_enuPinDirection == MPORT_OUTPUT)
					{
						SET_BIT(DDRD,PINNUM);
					}else if (Copy_enuPinDirection == MPORT_INPUT)
					{
						CLR_BIT(DDRD, PINNUM);
					}
					break;
				}
			}

}

MPORT_enuErrorStatus_t MPORT_enuSetPinMode( u8 Copy_enuPinNum  ,  MPORT_enuPinMode_t Copy_enuPinMode ){
	 u8 PORTNUM, PINNUM;
	 PORTNUM = (Copy_enuPinNum & 0xF0) >> 4;
	 PINNUM = Copy_enuPinNum & 0x0F;
	 MPORT_enuErrorStatus_t Ret_enuError;
	 Ret_enuError = MPORT_enuOK;
	 //MPORT_enuPinDirection
	 if (PORTNUM > MPORT_PORTD)
	 {
		 Ret_enuError = MPORT_INVALID_PORT;
	 }
	 else if (PINNUM > MPORT_enuPIN7)
	 {
		 Ret_enuError = MPORT_INVALID_PIN;
	 }
	 else if (Copy_enuPinMode >= PORT_PIN_MODE_NO_MODE)
	 {
		 Ret_enuError = MPORT_INVALID_CONFIG;
	 }
	 else{
		 if (Copy_enuPinMode ==PORT_PIN_MODE_INPUT_PULLDOWN)
		 {
			 CLR_BIT(PORTNUM, PINNUM);
		 }else{
			 SET_BIT(PORTNUM,PINNUM);
		 }
	 }	
}

void MPORT_vInit(void) {
	for (u8 i = 0; i < 32; i++) {
		u8 num_port = i / 8;
		u8 num_pin  =i % 8;
		u8 port_pin = (num_port <<4)+ num_pin ;
		MPORT_enuSetPinDirection(port_pin , PinCfg2[i][DIRECTION]);
		MPORT_enuSetPinMode(port_pin , PinCfg2[i][MODE]);
	}
}