#include <stdint.h>
#ifndef Cmd_Structure_Guard
#define Cmd_Structure_Guard

	typedef union _CmdStructure
	{
		struct _CmdData
			{
			uint8_t R_received, G_received, B_received, Color_StayTime, Color_ChangeTime, Enable_Random, R_current, G_current, B_current;
			} CmdData;
			uint8_t CmdStructArr[8];	
	} CmdStructure;
	
	CmdStructure LampCmdStructure;
	
	uint8_t *Enable_Random = &LampCmdStructure.CmdData.Enable_Random;
	uint8_t *StayTime = &LampCmdStructure.CmdData.Color_StayTime;
	uint8_t *ChangeTime = &LampCmdStructure.CmdData.Color_ChangeTime;
	uint8_t *R_received = &LampCmdStructure.CmdData.R_received;
	uint8_t *R_current = &LampCmdStructure.CmdData.R_current;
	uint8_t *G_received = &LampCmdStructure.CmdData.G_received;
	uint8_t *G_current = &LampCmdStructure.CmdData.G_current;
	uint8_t *B_received = &LampCmdStructure.CmdData.B_received;
	uint8_t *B_current = &LampCmdStructure.CmdData.B_current;
	 
#endif


	
