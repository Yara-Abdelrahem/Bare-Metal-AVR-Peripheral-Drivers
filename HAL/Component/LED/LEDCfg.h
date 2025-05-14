/*
 * ComponentCfg.h
 *
 * Created: 1/5/2025 9:46:04 AM
 *  Author: yaraa
 */ 


#ifndef LEDCFG_H_
#define LEDCFG_H_
#define NULL ((void*)0)

#include "../../../STD_TYPES.h"
#include "../../../BIT_MATH.h"

#define NUM_OF_LEDS 3
#define LED_START 0
#define LED_STOP 1
#define LED_ALERT 2

#define NUM_OF_SWITCHES 3
typedef enum {
	Forward ,
	Reverse
}LED_ConnectionOpt_t;

typedef struct{
	u8 port ;
	u8 pin;
	LED_ConnectionOpt_t connection;
	}LedCfg_t;
typedef enum {
	lED_PORTA,
	lED_PORTB,
	lED_PORTC,
	lED_PORTD
	
}enuPortNum;

typedef enum {
	lED_PIN0,
	lED_PIN1,
	lED_PIN2,
	lED_PIN3,
	lED_PIN4,
	lED_PIN5,
	lED_PIN6,
	lED_PIN7
	
}enuPinNum;

#endif /* COMPONENTCFG_H_ */