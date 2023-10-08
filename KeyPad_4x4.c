#include "KeyPad_4x4.h"

// Reset all columns to high level
void resetColumn(void)
{
	HAL_GPIO_WritePin(C1_PORT,C1_PIN,GPIO_PIN_SET);
	HAL_GPIO_WritePin(C2_PORT,C2_PIN,GPIO_PIN_SET);
	HAL_GPIO_WritePin(C3_PORT,C3_PIN,GPIO_PIN_SET);
	HAL_GPIO_WritePin(C4_PORT,C4_PIN,GPIO_PIN_SET);
}

// Read the button value of first column
uint8_t readCol1(void)
{
	HAL_GPIO_WritePin(C1_PORT,C1_PIN,GPIO_PIN_RESET);
	if(!HAL_GPIO_ReadPin(R1_PORT,R1_PIN))
	{
		HAL_GPIO_WritePin(C1_PORT,C1_PIN,GPIO_PIN_SET);
		return 1;
	}
	else if(!HAL_GPIO_ReadPin(R2_PORT,R2_PIN))
	{
		HAL_GPIO_WritePin(C1_PORT,C1_PIN,GPIO_PIN_SET);
		return 4;
	}
	else if(!HAL_GPIO_ReadPin(R3_PORT,R3_PIN))
	{
		HAL_GPIO_WritePin(C1_PORT,C1_PIN,GPIO_PIN_SET);
		return 7;
	}
	else if(!HAL_GPIO_ReadPin(R4_PORT,R4_PIN))
	{
		HAL_GPIO_WritePin(C1_PORT,C1_PIN,GPIO_PIN_SET);
		return 14;
	}
	else if(HAL_GPIO_ReadPin(R1_PORT,R1_PIN) || HAL_GPIO_ReadPin(R2_PORT,R2_PIN) || HAL_GPIO_ReadPin(R3_PORT,R3_PIN) || HAL_GPIO_ReadPin(R4_PORT,R4_PIN))
	{
		HAL_GPIO_WritePin(C1_PORT,C1_PIN,GPIO_PIN_SET);
		return 16;
	}
}

// Read the button value of second column
uint8_t readCol2(void)
{
	HAL_GPIO_WritePin(C2_PORT,C2_PIN,GPIO_PIN_RESET);
	if(!HAL_GPIO_ReadPin(R1_PORT,R1_PIN))
	{
		HAL_GPIO_WritePin(C2_PORT,C2_PIN,GPIO_PIN_SET);
		return 2;
	}
	else if(!HAL_GPIO_ReadPin(R2_PORT,R2_PIN))
	{
		HAL_GPIO_WritePin(C2_PORT,C2_PIN,GPIO_PIN_SET);
		return 5;
	}
	else if(!HAL_GPIO_ReadPin(R3_PORT,R3_PIN))
	{
		HAL_GPIO_WritePin(C2_PORT,C2_PIN,GPIO_PIN_SET);
		return 8;
	}
	else if(!HAL_GPIO_ReadPin(R4_PORT,R4_PIN))
	{
		HAL_GPIO_WritePin(C2_PORT,C2_PIN,GPIO_PIN_SET);
		return 0;
	}
	else if(HAL_GPIO_ReadPin(R1_PORT,R1_PIN) || HAL_GPIO_ReadPin(R2_PORT,R2_PIN) || HAL_GPIO_ReadPin(R3_PORT,R3_PIN) || HAL_GPIO_ReadPin(R4_PORT,R4_PIN))
	{
		HAL_GPIO_WritePin(C2_PORT,C2_PIN,GPIO_PIN_SET);
		return 16;
	}
}

// Read the button value of third column
uint8_t readCol3(void)
{
	HAL_GPIO_WritePin(C3_PORT,C3_PIN,GPIO_PIN_RESET);
	if(!HAL_GPIO_ReadPin(R1_PORT,R1_PIN))
	{
		HAL_GPIO_WritePin(C3_PORT,C3_PIN,GPIO_PIN_SET);
		return 3;
	}
	else if(!HAL_GPIO_ReadPin(R2_PORT,R2_PIN))
	{
		HAL_GPIO_WritePin(C3_PORT,C3_PIN,GPIO_PIN_SET);
		return 6;
	}
	else if(!HAL_GPIO_ReadPin(R3_PORT,R3_PIN))
	{
		HAL_GPIO_WritePin(C3_PORT,C3_PIN,GPIO_PIN_SET);
		return 9;
	}
	else if(!HAL_GPIO_ReadPin(R4_PORT,R4_PIN))
	{
		HAL_GPIO_WritePin(C3_PORT,C3_PIN,GPIO_PIN_SET);
		return 15;
	}
	else if(HAL_GPIO_ReadPin(R1_PORT,R1_PIN) || HAL_GPIO_ReadPin(R2_PORT,R2_PIN) || HAL_GPIO_ReadPin(R3_PORT,R3_PIN) || HAL_GPIO_ReadPin(R4_PORT,R4_PIN))
	{
		HAL_GPIO_WritePin(C3_PORT,C3_PIN,GPIO_PIN_SET);
		return 16;
	}
}

// Read the button value of fourth column
uint8_t readCol4(void)
{
	HAL_GPIO_WritePin(C4_PORT,C4_PIN,GPIO_PIN_RESET);
	if(!HAL_GPIO_ReadPin(R1_PORT,R1_PIN))
	{
		HAL_GPIO_WritePin(C4_PORT,C4_PIN,GPIO_PIN_SET);
		return 10;
	}
	else if(!HAL_GPIO_ReadPin(R2_PORT,R2_PIN))
	{
		HAL_GPIO_WritePin(C4_PORT,C4_PIN,GPIO_PIN_SET);
		return 11;
	}
	else if(!HAL_GPIO_ReadPin(R3_PORT,R3_PIN))
	{
		HAL_GPIO_WritePin(C4_PORT,C4_PIN,GPIO_PIN_SET);
		return 12;
	}
	else if(!HAL_GPIO_ReadPin(R4_PORT,R4_PIN))
	{
		HAL_GPIO_WritePin(C4_PORT,C4_PIN,GPIO_PIN_SET);
		return 13;
	}
	else if(HAL_GPIO_ReadPin(R1_PORT,R1_PIN) || HAL_GPIO_ReadPin(R2_PORT,R2_PIN) || HAL_GPIO_ReadPin(R3_PORT,R3_PIN) || HAL_GPIO_ReadPin(R4_PORT,R4_PIN))
	{
		HAL_GPIO_WritePin(C4_PORT,C4_PIN,GPIO_PIN_SET);
		return 16;
	}
}

// Read the button value
uint8_t readButton(void)
{
	uint8_t button;
	for(uint8_t col = 1; col < 5; col++)
	{
		if(col == 1)			button = readCol1();
		else if(col == 2)	button = readCol2();
		else if(col == 3)	button = readCol3();
		else if(col == 4)	button = readCol4();
			
		if(button == 16)	resetColumn();
		else if(button != 16)	break;
	}
	return button;
}
