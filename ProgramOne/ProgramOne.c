/* 
 * PES Project One Program One source code implementation
 *	Tristan Duenas
 *	GCC C99 compiler
 * References:
 * http://www.cplusplus.com/reference/cstring/strtok/
 * https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/strtoimax.htm
 */

#include "ProgramOne.h"

int main(int argc, char *argv[])
{

	// Parse constant input string
	char values[MAX_INPUT_SETS][MAX_STRING_INPUT_SIZE];
	char radices[MAX_INPUT_SETS][MAX_STRING_INPUT_SIZE];
	char operands[MAX_INPUT_SETS][MAX_STRING_INPUT_SIZE];
	// Remove {} from input string
	for (int32_t index = 0; index < strlen(argv[INPUT_ARGUMENT]); index++)
	{
		if ((argv[INPUT_ARGUMENT][index] == '{') || (argv[INPUT_ARGUMENT][index] == '}'))
		{
			argv[INPUT_ARGUMENT][index] = ' ';
		}
	}

	int8_t inputTypeCounter = 0;
	int8_t setNumber = 0;
	// Remove ',' from string
	// Referenced http://www.cplusplus.com/reference/cstring/strtok/
	char* ptr = strtok(argv[1], ",");
	while (ptr != NULL)
	{
		if (inputTypeCounter == INPUT_ONE)
		{
			strncpy(values[setNumber], ptr, MAX_STRING_INPUT_SIZE);
		}
		if (inputTypeCounter == INPUT_TWO)
		{
			strncpy(radices[setNumber], ptr, MAX_STRING_INPUT_SIZE);
		}
		if (inputTypeCounter == INPUT_THREE)
		{
			strncpy(operands[setNumber], ptr, MAX_STRING_INPUT_SIZE);
		}
		ptr = strtok(NULL,",");
		if (inputTypeCounter < INPUTS_IN_A_SET)
		{		
			inputTypeCounter++;
		}		
		if (inputTypeCounter >= INPUTS_IN_A_SET)
		{
			setNumber++;
			inputTypeCounter = 0;
		}
	}

	// Output table
	for (int32_t index = 0; index < setNumber; index++)
	{
		printf("Input:	Value %s			Radix %s			Operand Size %s\n", values[index], radices[index], operands[index]);
		int16_t value = 0;
		uint8_t radix = 0;
		uint8_t operandSize = 0;
		if (invalidInput(values[index], radices[index], operands[index], &value, &radix, &operandSize) == VALID)
		{
			printTable(value, radix, operandSize);
		}
		printf("\n\n");
	}

	return 0;	
}

uint8_t invalidInput(char *valueString, char *radixString, char *operandSizeString, int16_t* value, uint8_t* radix, uint8_t* operandSize)
{
	int16_t inputValidity = VALID;

	*radix = atoi(radixString);
	*operandSize = atoi(operandSizeString);
	if (((*radix) != RADIX_EIGHT) && ((*radix) != RADIX_TEN) && ((*radix) != RADIX_SIXTEEN))
	{
		printf("Error bad input. Radix invalid.\n");		
		inputValidity = INVALID;
	}
	if (((*operandSize) != OPERAND_SIZE_FOUR) && ((*operandSize) != OPERAND_SIZE_EIGHT) && ((*operandSize) != OPERAND_SIZE_SIXTEEN))
	{
		printf("Error bad input. Operand invalid.\n");
		inputValidity = INVALID;
	}
	
	if (inputValidity == VALID)
	{
		// Referenced https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/strtoimax.htm
		char* endPtr;
		int16_t tempValue = strtoimax(valueString, &endPtr, *radix);
		uint16_t maxValue = pow((double)BASE_TWO, (double)(*operandSize)) - ONE;
		if (tempValue > maxValue)
		{
			printf("Error bad input. Input outside of operand range.\n");
			inputValidity = INVALID;
		}
		else
		{
			*value = (int16_t)tempValue;
		}
	}
	return inputValidity;
}



void printTable(int16_t value, uint8_t radix, uint8_t operandSize)
{
	char absBinaryString[MAX_BINARY_STRING_SIZE];
	char maxAbsBinaryString[MAX_BINARY_STRING_SIZE];
	char minAbsBinaryString[MAX_BINARY_STRING_SIZE];
	char signedOneCompBinaryString[MAX_BINARY_STRING_SIZE];
	char maxSignedOneCompBinaryString[MAX_BINARY_STRING_SIZE];
	char minSignedOneCompBinaryString[MAX_BINARY_STRING_SIZE];
	char signedTwoCompBinaryString[MAX_BINARY_STRING_SIZE];
	char minSignedTwoCompBinaryString[MAX_BINARY_STRING_SIZE];
	char signMagnitudeBinaryString[MAX_BINARY_STRING_SIZE];
	char maxSignMagnitudeBinaryString[MAX_BINARY_STRING_SIZE];
	char minSignMagnitudeBinaryString[MAX_BINARY_STRING_SIZE];

	uint16_t absValue = abs(value);
	uint16_t maxValue = pow(BASE_TWO, operandSize)-1;
	int16_t signedOnesComp = ~absValue;
	int16_t maxSignedOnesComp = pow(BASE_TWO, operandSize-1)-1;
	int16_t minSignedOnesComp = ~maxSignedOnesComp;
	int16_t signedTwosComp = signedOnesComp + 1;
	int16_t minSignedTwosComp = minSignedOnesComp + 1;
	int8_t signMagValidity = VALID;
	int16_t signedMagnitude = getSignMagnitude(value, operandSize, &signMagValidity);
	int16_t maxSignedMagnitude = maxSignedOnesComp;
	int8_t minSignMagValidity = VALID;
	int16_t minSignedMagnitude = getSignMagnitude(-maxSignedMagnitude, operandSize, &minSignMagValidity);

	convertToBinaryString(absValue, operandSize, absBinaryString);
	convertToBinaryString(maxValue, operandSize, maxAbsBinaryString);
	convertToBinaryString(0, operandSize, minAbsBinaryString);
	convertToBinaryString(signedOnesComp, operandSize, signedOneCompBinaryString);
	convertToBinaryString(maxSignedOnesComp, operandSize, maxSignedOneCompBinaryString);
	convertToBinaryString(minSignedOnesComp, operandSize, minSignedOneCompBinaryString);	
	convertToBinaryString(signedTwosComp, operandSize, signedTwoCompBinaryString);
	convertToBinaryString(minSignedTwosComp, operandSize, minSignedTwoCompBinaryString);
	if (signMagValidity == VALID)
	{
		convertToBinaryString(signedMagnitude, operandSize, signMagnitudeBinaryString);
	}
	else
	{
		strcpy(signMagnitudeBinaryString, "ERROR");
	}
	convertToBinaryString(maxSignedMagnitude, operandSize, maxSignMagnitudeBinaryString);
	convertToBinaryString(minSignedMagnitude, operandSize, minSignMagnitudeBinaryString);
	if (minSignMagValidity == VALID)
	{
		convertToBinaryString(minSignedMagnitude, operandSize, minSignMagnitudeBinaryString);
	}
	else
	{
		strcpy(minSignMagnitudeBinaryString, "ERROR");
	}

	printf("Output:					Value					Maximum				Minimum\n");
	printf("Binary (abs)					0b%s				0b%s				0b%s\n", absBinaryString, maxAbsBinaryString, minAbsBinaryString);
	printf("Octal (abs)					0%o					0%o					%o\n", absValue, maxValue, 0);
	printf("Decimal (abs)				%d						%d						%d\n", absValue, maxValue, 0);
	printf("Hexadecimal (abs)			0x%X					0x%X					0x%X\n", absValue, maxValue, 0);
	printf("Signed One's Compliment (abs)			0b%s				0b%s				0b%s\n", signedOneCompBinaryString, maxSignedOneCompBinaryString, minSignedOneCompBinaryString);
	printf("Signed Two's Compliment (abs)			0b%s				0b%s				0b%s\n", signedTwoCompBinaryString, maxSignedOneCompBinaryString, minSignedTwoCompBinaryString);
	printf("Sign-Magnitude				0b%s				0b%s				0b%s\n", signMagnitudeBinaryString, maxSignMagnitudeBinaryString, minSignMagnitudeBinaryString);
}

void convertToBinaryString(int16_t value, uint8_t operandSize, char* binaryString)
{
	memset(binaryString, 0, sizeof(char) *  MAX_BINARY_STRING_SIZE);
	for (uint8_t bit = 1; bit <= operandSize; bit++)
	{
		if (((value >> (operandSize-bit)) & 1) == 1)
		{
			binaryString[bit-1] = '1';
		}
		else
		{
			binaryString[bit-1] = '0';
		}
	}
}

uint16_t getSignMagnitude(int16_t value, uint8_t operandSize, int8_t* signMagValidity)
{
	if (abs(value) > (pow(BASE_TWO, operandSize-1)-1))
	{
		*signMagValidity = INVALID;
		return 0;
	}
	else
	{
		uint16_t signMag = abs(value);
		if (value < 0)
		{
			switch((operandValues)operandSize)
			{
				case OPERAND_SIZE_FOUR:
					signMag |= SIGN_MAG_OPERAND_SIZE_FOUR_MASK;
					break;
				case OPERAND_SIZE_EIGHT:
					signMag |= SIGN_MAG_OPERAND_SIZE_EIGHT_MASK;
					break;
				case OPERAND_SIZE_SIXTEEN:
					signMag |= SIGN_MAG_OPERAND_SIZE_SIXTEEN_MASK;
					break;
				default:
					// Do nothing
					break;
			};
		}
		return signMag;
	}
}
