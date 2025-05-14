/*
 * MDIO.h
 *
 * Created: 12/17/2024 1:33:44 PM
 *  Author: yaraa
 */ 


#ifndef MDIO_H_
#define MDIO_H_
#define NULL ((void*)0)
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
//#include "../MPORT/MPORT.h"
typedef enum {
	MDIO_enuOK,
	MDIO_enuNOK,
	MDIO_INVALID_PARAM,
	MDIO_enuNULL_PTR,
	MDIO_INVALID_PORT,
	MDIO_INVALID_PIN,
	MDIO_INVALID_CONFIG
	
	}MDIO_enuErrorStatus_t;
	
typedef enum {
	MDIO_PORTA,
	MDIO_PORTB,
	MDIO_PORTC,
	MDIO_PORTD
	
}MDIO_enuPortNum;

typedef enum {
	MDIO_enuPIN0,
	MDIO_enuPIN1,
	MDIO_enuPIN2,
	MDIO_enuPIN3,
	MDIO_enuPIN4,
	MDIO_enuPIN5,
	MDIO_enuPIN6,
	MDIO_enuPIN7		
	
}MDIO_enuPinNum;

typedef enum {
	MDIO_OUTPUT,
	MDIO_INPUT_PULLUP,
	MDIO_INPUT_PULLDOWN,

}MDIO_enuConfigration;
typedef enum {
	MDIO_enu_ALL_INTPUT_PULLUP ,
	MDIO_enu_ALL_INTPUT_PULLDOWN,
	MDIO_enu_ALL_OUTPUT
}MDIO_enuConfigrationPort;

typedef enum {
	MDIO_LOW ,
	MDIO_HIGH
}MDIO_enuState;

typedef enum {
	DIO_All_LOW = 0x00 ,
	DIO_All_HIGH = 0xff
}MDIO_enuPortState;

MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,MDIO_enuState Copy_enuState);

MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPortState Copy_enuPortState);

MDIO_enuErrorStatus_t MDIO_enuSetPortValue2(MDIO_enuPortNum Copy_enuPortNum, u8 Copy_enuPortState);

MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,u8* Add_pu8PinValue);

MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,MDIO_enuConfigration Copy_enuConfigration);

MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuConfigrationPort Copy_enuConfigration);
void MDIO_vInit(void);

#endif /* MDIO_H_ */