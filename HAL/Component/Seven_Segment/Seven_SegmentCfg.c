/*
 * Seven_SegmentCfg.c
 *
 * Created: 1/7/2025 2:05:31 AM
 *  Author: yaraa
 */ 
#include "Seven_SegmentCfg.h"

// common cathode
u8 Seven_Segment_val[Seven_Segment_VALUE] = {
	//dot g f e  d c b a
	// 8 4 2 1   8 4  2  1
	0x3F,  // 0
	0x06,  // 1
	0x5B,  // 2
	0x4F,  // 3
	0x66,  // 4
	0x6D,  // 5
	0x7D,  // 6
	0x07,  // 7
	0x7F,  // 8
	0x6F   // 9
};
Seven_SegmentCfg_t2 Seven_SegmentCfg2[NUM_OF_Seven_Segment] = {
	[Seven_Segment1] = {
		.pin_arr={PIN_A0, PIN_A1,PIN_A2,PIN_A3,PIN_A4,PIN_A5, PIN_A6,PIN_A7},
		.connection = SevenSegment_CATHODE
	},
	[Seven_Segment2] = {
		.pin_arr={PIN_B0, PIN_B1,PIN_B2,PIN_B3,PIN_B4,PIN_B5, PIN_B6,PIN_B7},
		.connection = SevenSegment_CATHODE
	}
};