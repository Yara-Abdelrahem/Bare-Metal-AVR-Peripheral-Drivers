/*
 * ComponentCfg.h
 *
 * Created: 1/5/2025 9:46:04 AM
 *  Author: yaraa
 */ 


#ifndef SWITCHCFG_H_
#define SWITCHCFG_H_
#define NULL ((void*)0)
#include "../../../STD_TYPES.h"
#include "../../../BIT_MATH.h"


#define NUM_OF_SWITCHES 3
#define SWITCH_START 0
#define SWITCH_STOP 1
#define SWITCH_ALERT 2

typedef enum {
	PULLUP ,
	PULLDOWN
}SWITCH_ConnectionOpt_t;
	
typedef struct{
	u8 port ;
	u8 pin;
	SWITCH_ConnectionOpt_t connection;
}SWITCHCfg_t;
typedef enum {
	SWITCH_PORTA,
	SWITCH_PORTB,
	SWITCH_PORTC,
	SWITCH_PORTD
}SWITCHenuPortNum;

typedef enum {
	SWITCH_PIN0,
	SWITCH_PIN1,
	SWITCH_PIN2,
	SWITCH_PIN3,
	SWITCH_PIN4,
	SWITCH_PIN5,
	SWITCH_PIN6,
	SWITCH_PIN7
	
}SWITCHenuPinNum;

#endif /* COMPONENTCFG_H_ */