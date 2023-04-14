typedef enum EM_MeterType_e
{
	EM_DPM_TYPE = 0,
	EM_MID_TYPE,
	EM_METER_TYPE_NUM
}EM_MeterType_t;

typedef enum EM_Vendor_e
{
	EM_VENDOR_DPM_FINDER_TRI 		= 0,
	EM_VENDOR_DPM_FINDER_MONO 		= 1,
	EM_VENDOR_DPM_GAVAZZI_TRI 		= 2,	/* code EM330DINAV53HS1X	*/
	EM_VENDOR_DPM_GAVAZZI_MONO		= 3,    /* code EM111DINAV51XS1X 	*/
	EM_VENDOR_DPM_GAVAZZI_TRI_PFB 	= 4,	/* code EM340DINAV23XS1PFB 	*/
	EM_VENDOR_DPM_GAVAZZI_MONO_PFB 	= 5,	/* code EM111DINAV81XS1PFB 	*/
	EM_VENDOR_MID_START_ENUM_OFFSET	= 6,
	EM_VENDOR_MID_FINDER_TRI 		= 6,
	EM_VENDOR_MID_FINDER_MONO 		= 7,
	EM_VENDOR_MID_GAVAZZI_TRI_PFB 	= 8,	/* code EM340DINAV23XS1PFB 	*/
	EM_VENDOR_MID_GAVAZZI_MONO_PFB	= 9,	/* code EM111DINAV81XS1PFB 	*/
}EM_Vendor_t;

typedef struct EM_MetersConfiguration_s
{
	EM_MeterType_t 	EM_MeterType;
	bool_t			EM_MeterEnabled;
	EM_Vendor_t		EM_MeterVendor;
	uint8_t			EM_MeterRtuAddress;
	bool_t			EM_ConfigRequired;
	bool_t			EM_Error;
	uint32_t		EM_ErrorCounter;
}EM_MetersTable_t;

typedef enum EM_MeterType_e
{
	EM_DPM_TYPE = 0,
	EM_MID_TYPE,
	EM_METER_TYPE_NUM
}EM_MeterType_t;

bool_t DPM_MeterErr = FALSE;
bool_t DPM_Meter_newData_rcvd = FALSE;

static EM_MetersTable_t EM_MetersTable[EM_METER_TYPE_NUM];
static EM_MeterType_t EM_CurrentMeterMgm;


static void EM_UpdateMetersError(bool_t value)
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