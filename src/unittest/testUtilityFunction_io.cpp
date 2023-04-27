/******************************************************************************
 *                                                                            *
 * Copyright (C) 2023 Luca Tricerri                                           *
 * All Rights Reserved.                                                       *
 *                                                                            *
 ******************************************************************************/

/**
 * @triccyx@gmail.com
 */

#include <tuple>

#include "utilityFunction_io.h"
#include "gtest/gtest.h"
// Simple UT

/*
void setup(void)
{
	DPM_MeterErr = FALSE;
	MID_MeterErr = FALSE;
}*/

//qua devo definire message e length
uint8_t message[] = {1,2,3,4,5,6,7,8,9,10};
uint8_t length = 10;

TEST(ExternalMeter, Set_DPM_MeterError_TRUE)
{
	//Setup
	//setup();

	uint16_t result;
	//EM_CurrentMeterMgm = EM_DPM_TYPE;
	//EM_MetersTable[EM_CurrentMeterMgm].EM_MeterType = EM_DPM_TYPE;
	

	//Execute
	result = calculateCrc16bits(message, length);

	//Check
	EXPECT_EQ(0xC3B3,result);
	EXPECT_EQ(0xC3B4,result);
}
