/*
 * ComponentCfg.c
 *
 * Created: 1/5/2025 9:46:17 AM
 *  Author: yaraa
 */ 
#include "SWITCHCfg.h"
SWITCHCfg_t SwitchCfg[NUM_OF_SWITCHES]=
{
	[SWITCH_ALERT] = {
		.port = SWITCH_PORTA,
		.pin= SWITCH_PIN3,
		.connection = PULLDOWN
	},
	[SWITCH_STOP] = {
		.port = SWITCH_PORTA,
		.pin = SWITCH_PIN4,
		.connection = PULLDOWN
	},
	[SWITCH_START] ={
		.pin = SWITCH_PIN5,
		.port = SWITCH_PORTA,
		.connection = PULLDOWN
	}
};