/*
 * ComponentCfg.c
 *
 * Created: 1/5/2025 9:46:17 AM
 *  Author: yaraa
 */ 
#include "LEDCfg.h"
LedCfg_t ledCfg[NUM_OF_LEDS]=
{
	[LED_ALERT] = {
		.port = lED_PORTA,
		.pin= lED_PIN0,
		.connection = Forward
	},
	[LED_STOP] = {
		.port = lED_PORTA,
		.pin = lED_PIN1,
		.connection = Forward
	},
	[LED_START] ={
		.pin = lED_PIN2,
		.port = lED_PORTA,
		.connection = Forward
	}
};