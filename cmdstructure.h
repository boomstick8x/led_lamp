#include <stdint.h>
#ifndef Cmd_Structure_Guard
#define Cmd_Structure_Guard
	typedef union _CmdStructure
	{
		struct _CmdData
			{uint8_t R, G, B;} CmdData;
			uint8_t CmdStructArr[2];	
	} CmdStructure;
	
	CmdStructure LampCmdStructure;
	
	uint8_t *RED = &LampCmdStructure.CmdData.R;
	uint8_t *GREEN = &LampCmdStructure.CmdData.G;
	uint8_t *BLUE = &LampCmdStructure.CmdData.B;
#endif


	
