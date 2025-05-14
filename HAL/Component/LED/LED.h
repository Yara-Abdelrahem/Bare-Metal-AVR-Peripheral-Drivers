/*
 * Component.h
 *
 * Created: 1/5/2025 9:46:35 AM
 *  Author: yaraa
 */ 


#ifndef LED_H_
#define LED_H_
#include "LEDCfg.h"
#include "../../../MCAL/MPORT/MPORT.h"
#include "../../../MCAL/MDIO/MDIO.h"

typedef enum {
	enuOK,
	enuNOK,
	INVALID_PARAM,
	INVALID_PORT,
	INVALID_PIN,
	INVALID_CONFIG
	
}LED_enuErrorStatus_t;

typedef enum{
	LOW,
	HIGH
	}LED_STATE;
void LED_init();
LED_enuErrorStatus_t LED_enuSetLedState(u8 Copy_u8LedName, u8 Copy_u8State);
#endif /* LED_H_ */