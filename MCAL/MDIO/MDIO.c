/*
 * MDIO.c
 *
 * Created: 12/17/2024 1:33:28 PM
 *  Author: yaraa
 */ 
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "MDIO.h"


#define DDRA (*((volatile u8*)0x3A))
#define DDRB (*((volatile u8*)0x37))
#define DDRC (*((volatile u8*)0x34))
#define DDRD (*((volatile u8*)0x31))

#define PORTA (*((volatile u8*)0x3B))
#define PORTB (*((volatile u8*)0x38))
#define PORTC (*((volatile u8*)0x35))
#define PORTD (*((volatile u8*)0x32))

#define PINA (*((volatile u8*)0x39))
#define PINB (*((volatile u8*)0x36))
#define PINC (*((volatile u8*)0x33))
#define PIND (*((volatile u8*)0x30))

extern u8 PinCfg [32];

MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,MDIO_enuState Copy_enuState){
	MDIO_enuErrorStatus_t Ret_enuError;
	Ret_enuError = MDIO_enuOK;
	if (Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuError = MDIO_INVALID_PORT;
	}
	else if (Copy_enuPinNum > MDIO_enuPIN7)
	{
		Ret_enuError = MDIO_INVALID_PIN;
	}
	else if (Copy_enuState > MDIO_HIGH)
	{
		Ret_enuError = MDIO_INVALID_PARAM;
	}else{
			switch(Copy_enuPortNum){
				case MDIO_PORTA:
				if (Copy_enuState == MDIO_LOW)
				{
					CLR_BIT(PORTA,Copy_enuPinNum);
				}else if (Copy_enuState == MDIO_HIGH)
				{
					SET_BIT(PORTA, Copy_enuPinNum);
				}
				break;
				case MDIO_PORTB :
				if (Copy_enuState == MDIO_LOW)
				{
					CLR_BIT(PORTB,Copy_enuPinNum);
				}else if (Copy_enuState == MDIO_HIGH)
				{
					SET_BIT(PORTB, Copy_enuPinNum);
				}
				break;
				case MDIO_PORTC:
				if (Copy_enuState == MDIO_LOW)
				{
					CLR_BIT(PORTC,Copy_enuPinNum);
				}else if (Copy_enuState == MDIO_HIGH)
				{
					SET_BIT(PORTC, Copy_enuPinNum);
				}
				break;
				case MDIO_PORTD:
				if (Copy_enuState == MDIO_LOW)
				{
					CLR_BIT(PORTD,Copy_enuPinNum);
				}else if (Copy_enuState == MDIO_HIGH)
				{
					SET_BIT(PORTD, Copy_enuPinNum);
				}
				break;
			}
	}
	return Ret_enuError;
}

MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPortState Copy_enuPortState){
	MDIO_enuErrorStatus_t Ret_enuError;
	Ret_enuError = MDIO_enuOK;
	if (Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuError = MDIO_INVALID_PORT;
	}
	else if (Copy_enuPortState != DIO_All_HIGH && Copy_enuPortState != DIO_All_LOW)
	{
		Ret_enuError = MDIO_INVALID_CONFIG;
	}
	else{
		switch(Copy_enuPortNum){
			case MDIO_PORTA:
				PORTA = (u8)Copy_enuPortState;
			break;
			case MDIO_PORTB :
				PORTB = (u8)Copy_enuPortState;
			break;
			case MDIO_PORTC:
				PORTC = (u8)Copy_enuPortState;
			break;
			case MDIO_PORTD:
				PORTD = (u8)Copy_enuPortState;
			break;
		}
	}
	return Ret_enuError;
	
}

MDIO_enuErrorStatus_t MDIO_enuSetPortValue2(MDIO_enuPortNum Copy_enuPortNum, u8 Copy_enuPortState) {
	MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuOK;

	// Validate Port Number
	if (Copy_enuPortNum > MDIO_PORTD) {
		return MDIO_INVALID_PORT;
	}

	// Validate Port State (Ensure it's an 8-bit value)
	if (Copy_enuPortState > 0xFF) {
		return MDIO_INVALID_CONFIG;
	}

	// Set Port Value
	switch (Copy_enuPortNum) {
		case MDIO_PORTA:
		PORTA = Copy_enuPortState;
		break;
		case MDIO_PORTB:
		PORTB = Copy_enuPortState;
		break;
		case MDIO_PORTC:
		PORTC = Copy_enuPortState;
		break;
		case MDIO_PORTD:
		PORTD = Copy_enuPortState;
		break;
		default:
		Ret_enuError = MDIO_INVALID_PORT; // This should never occur due to prior validation
		break;
	}

	return Ret_enuError;
}

MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,u8* Add_pu8PinValue){
		MDIO_enuErrorStatus_t Ret_enuError;
		Ret_enuError = MDIO_enuOK;
		if (Copy_enuPortNum > MDIO_PORTD)
		{
			Ret_enuError = MDIO_INVALID_PORT;
		}
		else if (Copy_enuPinNum > MDIO_enuPIN7)
		{
			Ret_enuError = MDIO_INVALID_PIN;
		}else if (Add_pu8PinValue == NULL)
		{
			Ret_enuError = MDIO_enuNULL_PTR;
		}else{
			switch(Copy_enuPortNum){
				case MDIO_PORTA:
					*Add_pu8PinValue = GET_BIT(PINA , Copy_enuPinNum);
				break;
				case MDIO_PORTB :
					*Add_pu8PinValue = GET_BIT(PINB , Copy_enuPinNum);
				break;
				case MDIO_PORTC:
					*Add_pu8PinValue = GET_BIT(PINC , Copy_enuPinNum);
				break;
				case MDIO_PORTD:
					*Add_pu8PinValue = GET_BIT(PIND , Copy_enuPinNum);
				break;
			}
		}
}

MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,MDIO_enuConfigration Copy_enuConfigration){
	MDIO_enuErrorStatus_t Ret_enuError;
	Ret_enuError = MDIO_enuOK;
	if (Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuError = MDIO_INVALID_PORT;
	}
	else if (Copy_enuPinNum > MDIO_enuPIN7)
	{
		Ret_enuError = MDIO_INVALID_PIN;
	}
	else if (Copy_enuConfigration > MDIO_INPUT_PULLDOWN)
	{
		Ret_enuError = MDIO_INVALID_CONFIG;
	}
	else{
		switch(Copy_enuPortNum){
			case MDIO_PORTA:
			if (Copy_enuConfigration == MDIO_OUTPUT)
			{
				SET_BIT(DDRA,Copy_enuPinNum);
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLUP)
			{
				CLR_BIT(DDRA, Copy_enuPinNum);
				SET_BIT(PORTA , Copy_enuPinNum);
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLDOWN)
			{
				CLR_BIT(DDRA, Copy_enuPinNum);
				CLR_BIT(PORTA , Copy_enuPinNum);
			}
			break;
			case MDIO_PORTB :
			if (Copy_enuConfigration == MDIO_OUTPUT)
			{
				SET_BIT(DDRB,Copy_enuPinNum);
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLUP)
			{
				CLR_BIT(DDRB, Copy_enuPinNum);
				SET_BIT(PORTB , Copy_enuPinNum);
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLDOWN)
			{
				CLR_BIT(DDRB, Copy_enuPinNum);
				CLR_BIT(PORTB , Copy_enuPinNum);
			}
			break;
			case MDIO_PORTC:
			if (Copy_enuConfigration == MDIO_OUTPUT)
			{
				SET_BIT(DDRC,Copy_enuPinNum);
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLUP)
			{
				CLR_BIT(DDRC, Copy_enuPinNum);
				SET_BIT(PORTC, Copy_enuPinNum);
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLDOWN)
			{
				CLR_BIT(DDRC, Copy_enuPinNum);
				CLR_BIT(PORTC , Copy_enuPinNum);
			}
			break;
			case MDIO_PORTD:
			if (Copy_enuConfigration == MDIO_OUTPUT)
			{
				SET_BIT(DDRD,Copy_enuPinNum);
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLUP)
			{
				CLR_BIT(DDRD, Copy_enuPinNum);
				SET_BIT(PORTD , Copy_enuPinNum);
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLDOWN)
			{
				CLR_BIT(DDRD, Copy_enuPinNum);
				CLR_BIT(PORTD , Copy_enuPinNum);
			}
			break;
		}
		
	}
	return Ret_enuError;
}

MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuConfigrationPort Copy_enuConfigration){
	MDIO_enuErrorStatus_t Ret_enuError;
	Ret_enuError = MDIO_enuOK;
	if (Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuError = MDIO_INVALID_PORT;
	}
	else if((Copy_enuConfigration != MDIO_enu_ALL_INTPUT_PULLDOWN)&&(Copy_enuConfigration != MDIO_enu_ALL_OUTPUT))
	{
		Ret_enuError = MDIO_INVALID_CONFIG;
	}
	else{
		switch(Copy_enuPortNum){
			case MDIO_PORTA:
			if (Copy_enuConfigration == MDIO_OUTPUT)
			{
				DDRA=MDIO_enu_ALL_OUTPUT;
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLDOWN)
			{
				DDRA=MDIO_enu_ALL_INTPUT_PULLDOWN;
				PORTA=MDIO_enu_ALL_OUTPUT;

			}else if (Copy_enuConfigration == MDIO_INPUT_PULLUP)
			{
				DDRA=MDIO_enu_ALL_INTPUT_PULLUP;
				PORTA=MDIO_enu_ALL_INTPUT_PULLUP;
			}
			break;
			case MDIO_PORTB :
			if (Copy_enuConfigration == MDIO_OUTPUT)
			{
				DDRB=MDIO_enu_ALL_OUTPUT;
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLDOWN)
			{
				DDRB=MDIO_enu_ALL_INTPUT_PULLDOWN;
				PORTB=MDIO_enu_ALL_OUTPUT;

			}else if (Copy_enuConfigration == MDIO_INPUT_PULLUP)
			{
				DDRB=MDIO_enu_ALL_INTPUT_PULLUP;
				PORTB=MDIO_enu_ALL_INTPUT_PULLUP;
			}
			break;
			case MDIO_PORTC:
			if (Copy_enuConfigration == MDIO_OUTPUT)
			{
				DDRC=MDIO_enu_ALL_OUTPUT;
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLDOWN)
			{
				DDRC=MDIO_enu_ALL_INTPUT_PULLDOWN;
				PORTC=MDIO_enu_ALL_OUTPUT;

			}else if (Copy_enuConfigration == MDIO_INPUT_PULLUP)
			{
				DDRC=MDIO_enu_ALL_INTPUT_PULLUP;
				PORTC=MDIO_enu_ALL_INTPUT_PULLUP;
			}
			break;
			if (Copy_enuConfigration == MDIO_OUTPUT)
			{
				DDRD=MDIO_enu_ALL_OUTPUT;
			}else if (Copy_enuConfigration == MDIO_INPUT_PULLDOWN)
			{
				DDRD=MDIO_enu_ALL_INTPUT_PULLDOWN;
				PORTD=MDIO_enu_ALL_OUTPUT;

			}else if (Copy_enuConfigration == MDIO_INPUT_PULLUP)
			{
				DDRD=MDIO_enu_ALL_INTPUT_PULLUP;
				PORTD=MDIO_enu_ALL_INTPUT_PULLUP;
			}
			break;
		}
	}
	return Ret_enuError;
}

void MDIO_vInit(void) {
	for (u8 i = 0; i < 32; i++) {
		u8 num_port=i/8;
		u8 num_pin=i%8;
		MDIO_enuSetPinConfigration(num_port , num_pin , PinCfg[i]);
	}
}
