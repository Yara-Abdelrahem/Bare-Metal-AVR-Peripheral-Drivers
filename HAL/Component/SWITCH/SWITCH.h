/*
 * SWITCH.h
 *
 * Created: 1/5/2025 1:18:23 PM
 *  Author: yaraa
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_
#include "SWITCHCfg.h"
#include "../../../MCAL/MPORT/MPORT.h"
#include "../../../MCAL/MDIO/MDIO.h"

typedef enum {
	switch_enuOK,
	switch_enuNOK,
	switch_INVALID_PARAM,
	switch_enuNULL_PTR,
	switch_INVALID_PORT,
	switch_INVALID_PIN,
	switch_INVALID_CONFIG
	
}SWITCH_enuErrorStatus_t;

void SWITCH_init();
SWITCH_enuErrorStatus_t SWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State);


#endif /* SWITCH_H_ */