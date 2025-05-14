/*
 * Layered_Architecture.c
 *
 * Created: 12/17/2024 1:31:14 PM
 * Author : yaraa
 */ 

#include <avr/io.h>
#include "./MCAL/MDIO/MDIO.h"
#include "./MCAL/MPORT/MPORT.h"
#include "HAL/Component/LED/Component.h"
#include "HAL/Component/LED/ComponentCfg.h"
#include "HAL/Component/SWITCH/SWITCH.h"
#include "HAL/Component/SWITCH/SWITCHCfg.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU 8000000UL
int main(void)
{
	MDIO_enuErrorStatus_t stat1 , stat2, stat3;
	u8 res1 , res2 , res3 , count=0;
	//MDIO_vInit();
	//MPORT_vInit();
	LED_init();
	SWITCH_init();
	//MPORT_enuSetPinDirection(PIN_A0 , MPORT_OUTPUT);
		while (1)
		{	
			
			//stat1 = MDIO_enuGetPinValue(MDIO_PORTA , MDIO_enuPIN3, &res1);
			SWITCH_enuGetSwitchState(SWITCH_ALERT , &res1);
			LED_enuSetLedState(LED_ALERT , res1);
			//portA0
			//stat1=MDIO_enuSetPinValue(MDIO_PORTA , MDIO_enuPIN0 , res1);
			
			//stat2 = MDIO_enuGetPinValue(MDIO_PORTA , MDIO_enuPIN4, &res2);
			//PORT A1
			//stat2=MDIO_enuSetPinValue(MDIO_PORTA , MDIO_enuPIN1 , res2);
			SWITCH_enuGetSwitchState(SWITCH_STOP , &res2);
			LED_enuSetLedState(LED_STOP , res2);
						
			//stat3 = MDIO_enuGetPinValue(MDIO_PORTA , MDIO_enuPIN5, &res3);
			//PORT A2
			SWITCH_enuGetSwitchState(SWITCH_START , &res3);
			LED_enuSetLedState(LED_START , res3);
			//stat3=MDIO_enuSetPinValue(MDIO_PORTA , MDIO_enuPIN2 , res3);
			_delay_ms(1000);

		}
}

