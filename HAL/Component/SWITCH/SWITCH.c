/*
 * SWITCH.c
 *
 * Created: 1/5/2025 1:19:13 PM
 *  Author: yaraa
 */ 
#include "SWITCH.h"
extern SWITCHCfg_t SwitchCfg[NUM_OF_SWITCHES];
void SWITCH_init(){
	u8 currPinPort = 0;
	int iter;
	for(iter=0;iter<NUM_OF_SWITCHES;iter++)
	{ 
		currPinPort = (SwitchCfg[iter].port<<4) + SwitchCfg[iter].pin;
		MPORT_enuSetPinDirection(currPinPort , MPORT_INPUT);
	}
}
SWITCH_enuErrorStatus_t SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State){
	SWITCH_enuErrorStatus_t Ret_enuErrorStatus = switch_enuNOK;
	if(Copy_u8SwitchName > NUM_OF_SWITCHES){
		Ret_enuErrorStatus = switch_INVALID_PARAM;
		}else{
		Ret_enuErrorStatus = switch_enuOK;
		Ret_enuErrorStatus = MDIO_enuGetPinValue(SwitchCfg[Copy_u8SwitchName].port, SwitchCfg[Copy_u8SwitchName].pin, Add_pu8State);
	}
	return Ret_enuErrorStatus ;
}

