/*
 * LCDCfg.c
 *
 * Created: 2/3/2025 12:08:31 PM
 *  Author: yaraa
 */ 

#define NULL ((void*)0)
#include "../../../STD_TYPES.h"
#include "../../../BIT_MATH.h"
#include "LCDCfg.h"

LCDCFG_t LCD={
	.RS = PIN_A0,
	.RW = PIN_A1,
	.E = PIN_A2,
	.D_arr={PIN_B0,PIN_B1, PIN_B2,PIN_B3,PIN_B4,PIN_B5,PIN_B6,PIN_B7}
	};