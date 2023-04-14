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

#include "utilityFunction.h"
#include "gtest/gtest.h"
// Simple UT

void setup(void)
{
	DPM_MeterErr = FALSE;
	MID_MeterErr = FALSE;
}

TEST(ExternalMeter, Set_DPM_MeterError_TRUE)
{
	//Setup
	setup();
	EM_CurrentMeterMgm = EM_DPM_TYPE;
	EM_MetersTable[EM_CurrentMeterMgm].EM_MeterType = EM_DPM_TYPE;
	
	//Execute
	EM_UpdateMetersError(TRUE);

	//Check
	EXPECT_EQ(FALSE,DPM_MeterErr);
	EXPECT_EQ(FALSE,MID_MeterErr);
}
