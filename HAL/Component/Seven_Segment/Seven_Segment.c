/*
 * Seven_Segment.c
 *
 * Created: 1/7/2025 2:05:43 AM
 *  Author: yaraa
 */ 

#include "Seven_Segment.h"
#include "Seven_SegmentCfg.h"
extern Seven_SegmentCfg_t2 Seven_SegmentCfg2[NUM_OF_Seven_Segment];
extern u8 Seven_Segment_val[Seven_Segment_VALUE];
void  HSEVENSEG_vInit(){
	u8 currPinPort = 0;
	int iter1 , iter2;
	for(iter1=0;iter1<NUM_OF_Seven_Segment;iter1++)
	{
		for (iter2 = 0 ; iter2 <Seven_Segment_PINS ; iter2++)
		{
			MPORT_enuSetPinDirection(Seven_SegmentCfg2[iter1].pin_arr[iter2], MPORT_OUTPUT);
		}
	}
}

void HSEVENSEG_vSetValue(u8 Copy_enuSevenSegNum, u8 Copy_u8Value) {
	if (Copy_enuSevenSegNum >= NUM_OF_Seven_Segment || Copy_u8Value > 9) {
		return;  // Invalid inputs
	}
	u8 segmentValue = Seven_Segment_val[Copy_u8Value];

	for (u8 i = 0; i < Seven_Segment_PINS; i++) {
		u8 pinState = GET_BIT(segmentValue, i);
		if (Seven_SegmentCfg2[Copy_enuSevenSegNum].connection == SevenSegment_ANODE) {
			pinState = !pinState;
		}
		u8 PORTNUM = (Seven_SegmentCfg2[Copy_enuSevenSegNum].pin_arr[i] & 0xF0)>>4;
		u8 PINNUM = Seven_SegmentCfg2[Copy_enuSevenSegNum].pin_arr[i] & 0x0F;

		MDIO_enuSetPinValue(PORTNUM, PINNUM, pinState);
	}
}
HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value){
	u8 count = 0;
	while (Copy_u16Value > 0 && count < NUM_OF_Seven_Segment) {
		u8 digit = Copy_u16Value % 10;
		Copy_u16Value = Copy_u16Value / 10;
		u8 segmentValue = Seven_Segment_val[digit];
		for (u8 i = 0; i < Seven_Segment_PINS; i++) {
			u8 pinState = GET_BIT(segmentValue, i);
			if (Seven_SegmentCfg2[count].connection == SevenSegment_ANODE) {
				pinState = !pinState;
			}
			u8 PORTNUM = (Seven_SegmentCfg2[count].pin_arr[i] & 0xF0)>>4;
			u8 PINNUM = Seven_SegmentCfg2[count].pin_arr[i] & 0x0F;
			MDIO_enuSetPinValue(PORTNUM, PINNUM, pinState);			
		}
		count++;
	}	
}
