#include <stdint.h>
#ifndef Cmd_Structure_Guard
#define Cmd_Structure_Guard
	/*typedef struct _CmdData
	{
		uint8_t r, g, b;
	} CmdData;
	extern CmdData mystruct;
	extern CmdData *cmd;
	uint8_t CmdDataArr[2];*/
	
	typedef union _CmdStructure
	{
		//#pragma anon_unions
		struct _CmdData
			{uint8_t r, g, b;}CmdData;
			uint8_t CmdStructArr[3];	
	} CmdStructure;
	
	CmdStructure LampCmdStructure;
	//uint8_t CmdStructArr[3];
#endif


