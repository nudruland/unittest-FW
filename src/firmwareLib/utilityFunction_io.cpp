#include "utilityFunction_io.h"

uint16_t calculateCrc16bits(uint8_t *message, uint8_t length)
{
	uint8_t CRCHi = 0xFF;
	uint8_t CRCLo = 0xFF;
	uint16_t Index;
	uint16_t ret;

	while( length-- )
	{
		Index = CRCLo ^ *message++ ;
		CRCLo = CRCHi ^ CRC_Table_Hi[Index];
		CRCHi = CRC_Table_Lo[Index];
	}
	ret = ((unsigned short)CRCHi << 8);
	ret |= (unsigned short)CRCLo;
	return ret;
}


