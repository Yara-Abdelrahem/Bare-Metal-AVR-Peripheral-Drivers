/*
 * Seven_SegmentCfg.h
 *
 * Created: 1/7/2025 2:05:01 AM
 *  Author: yaraa
 */ 


#ifndef SEVEN_SEGMENTCFG_H_
#define SEVEN_SEGMENTCFG_H_

#define NULL ((void*)0)
#include "../../../STD_TYPES.h"
#include "../../../BIT_MATH.h"

#define NUM_OF_Seven_Segment 2
#define Seven_Segment1 0
#define Seven_Segment2 1
#define Seven_Segment_PINS 8
#define Seven_Segment_VALUE 10

// Port A
#define PIN_A0 0x00  // Port A, Pin 0
#define PIN_A1 0x01  // Port A, Pin 1
#define PIN_A2 0x02  // Port A, Pin 2
#define PIN_A3 0x03  // Port A, Pin 3
#define PIN_A4 0x04  // Port A, Pin 4
#define PIN_A5 0x05  // Port A, Pin 5
#define PIN_A6 0x06  // Port A, Pin 6
#define PIN_A7 0x07  // Port A, Pin 7

// Port B
#define PIN_B0 0x10  // Port B, Pin 0
#define PIN_B1 0x11  // Port B, Pin 1
#define PIN_B2 0x12  // Port B, Pin 2
#define PIN_B3 0x13  // Port B, Pin 3
#define PIN_B4 0x14  // Port B, Pin 4
#define PIN_B5 0x15  // Port B, Pin 5
#define PIN_B6 0x16  // Port B, Pin 6
#define PIN_B7 0x17  // Port B, Pin 7

// Port C
#define PIN_C0 0x20  // Port C, Pin 0
#define PIN_C1 0x21  // Port C, Pin 1
#define PIN_C2 0x22  // Port C, Pin 2
#define PIN_C3 0x23  // Port C, Pin 3
#define PIN_C4 0x24  // Port C, Pin 4
#define PIN_C5 0x25  // Port C, Pin 5
#define PIN_C6 0x26  // Port C, Pin 6
#define PIN_C7 0x27  // Port C, Pin 7

// Port D
#define PIN_D0 0x30  // Port D, Pin 0
#define PIN_D1 0x31  // Port D, Pin 1
#define PIN_D2 0x32  // Port D, Pin 2
#define PIN_D3 0x33  // Port D, Pin 3
#define PIN_D4 0x34  // Port D, Pin 4
#define PIN_D5 0x35  // Port D, Pin 5
#define PIN_D6 0x36  // Port D, Pin 6
#define PIN_D7 0x37  // Port D, Pin 7

typedef enum {
	SevenSegment_ANODE,
	SevenSegment_CATHODE
}Seven_Segment_ConnectionOpt_t;
typedef struct{
	// a,b,c,d,e,f,g,dot
	u8 pin_arr[Seven_Segment_PINS];
	Seven_Segment_ConnectionOpt_t connection;
}Seven_SegmentCfg_t2;

#endif /* SEVEN_SEGMENTCFG_H_ */