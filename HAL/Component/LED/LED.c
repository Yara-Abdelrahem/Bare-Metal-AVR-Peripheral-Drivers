/*
 * Component.c
 *
 * Created: 1/5/2025 9:46:47 AM
 *  Author: yaraa
 */ 

#include "LED.h"
#include "LEDCfg.h"
extern LedCfg_t ledCfg[NUM_OF_LEDS];
void LED_init(){
	u8 currPinPort = 0;
	int iter;
	for(iter=0;iter<NUM_OF_LEDS;iter++)
	{ 
		currPinPort = (ledCfg[iter].port<<4) + ledCfg[iter].pin;
		MPORT_enuSetPinDirection(currPinPort , MPORT_OUTPUT);
	}
}
LED_enuErrorStatus_t LED_enuSetLedState(u8 Copy_u8LedName, u8 Copy_u8State){
	LED_enuErrorStatus_t Ret_enuErrorStatus = enuNOK;
	if(Copy_u8LedName > NUM_OF_LEDS){
		Ret_enuErrorStatus = INVALID_PARAM;
		}else if(Copy_u8State > HIGH){	
			Ret_enuErrorStatus =INVALID_CONFIG;
		}else{
		Ret_enuErrorStatus = enuOK;
		if (ledCfg[Copy_u8LedName].connection == Forward)
		{
			Ret_enuErrorStatus = MDIO_enuSetPinValue(ledCfg[Copy_u8LedName].port, ledCfg[Copy_u8LedName].pin, Copy_u8State);

		}else{
			Ret_enuErrorStatus = MDIO_enuSetPinValue(ledCfg[Copy_u8LedName].port, ledCfg[Copy_u8LedName].pin, !(Copy_u8State));
		}
		
	}
	return Ret_enuErrorStatus ;
}

