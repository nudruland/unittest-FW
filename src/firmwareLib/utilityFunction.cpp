#include "utilityFunction.h"

bool_t DPM_MeterErr = FALSE;
bool_t MID_MeterErr = FALSE;

void EM_UpdateMetersError(bool_t value)
{
	switch(EM_MetersTable[EM_CurrentMeterMgm].EM_MeterType)
	{
	case EM_DPM_TYPE:
		DPM_MeterErr = value;
		break;
	case EM_MID_TYPE:
		MID_MeterErr = value;
		break;
	default:
		break;
	}
}