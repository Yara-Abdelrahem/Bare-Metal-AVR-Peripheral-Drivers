/*
 * Layered_Architecture.c
 *
 * Created: 12/17/2024 1:31:14 PM
 * Author : yaraa
 */ 

#include <avr/io.h>
#include "./MCAL/MDIO/MDIO.h"
#include "./MCAL/MPORT/MPORT.h"
#include "HAL/Component/Seven_Segment/Seven_Segment.h"
#include "HAL/Component/Seven_Segment/Seven_SegmentCfg.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU 8000000UL
int main(void)
{
	HSEVENSEG_vInit();
	while (1)
	{	
		HSEVENSEG_enuSetMultiDigitValue(55);
		_delay_ms(1000);

	}
}

