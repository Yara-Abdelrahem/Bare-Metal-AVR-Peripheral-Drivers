/*
 * Seven_Segment.h
 *
 * Created: 1/7/2025 2:05:17 AM
 *  Author: yaraa
 */ 


#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "Seven_SegmentCfg.h"
#include "../../../MCAL/MPORT/MPORT.h"
#include "../../../MCAL/MDIO/MDIO.h"

typedef enum{
	Seven_Segment_enuOK,
	Seven_Segment_enuNOK,
	Seven_Segment_INVALID_PARAM,
	Seven_Segment_enuNULL_PTR,
	Seven_Segment_INVALID_PORT,
	Seven_Segment_INVALID_PIN,
	Seven_Segment_INVALID_CONFIG
	}HSEVENSEG_enuErrorStatus_t;

void  HSEVENSEG_vInit();
void HSEVENSEG_vSetValue(u8 Copy_enuSevenSegNum , u8 Copy_u8Value);
HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value);



#endif /* SEVEN_SEGMENT_H_ */