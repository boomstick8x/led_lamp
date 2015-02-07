#include <stdint.h>
#ifndef Cmd_Structure_Guard
#define Cmd_Structure_Guard
	typedef union _CmdStructure
	{
		struct _CmdData
			{
			unsigned char CmdByte;
			uint8_t R_received, G_received, B_received, R_current, G_current, B_current;
			} CmdData;
			uint8_t CmdStructArr[7];	
	} CmdStructure;
	
	CmdStructure LampCmdStructure;
	
	unsigned char *CmdByte = &LampCmdStructure.CmdData.CmdByte;
	uint8_t *R_received = &LampCmdStructure.CmdData.R_received;
	uint8_t *R_current = &LampCmdStructure.CmdData.R_current;
	uint8_t *G_received = &LampCmdStructure.CmdData.G_received;
	uint8_t *G_current = &LampCmdStructure.CmdData.G_current;
	uint8_t *B_received = &LampCmdStructure.CmdData.B_received;
	uint8_t *B_current = &LampCmdStructure.CmdData.B_current;
	 
#endif


	
