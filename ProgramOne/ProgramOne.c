/* 
 * PES Project One Program One source code implementation
 *	Tristan Duenas
 *	GCC C99 compiler
 */

#include "ProgramOne.h"

int main(int argc, char *argv[])
{
	int16_t value = 0;
	uint8_t radix = 0;
	uint8_t operandSize = 0;
	if (invalidInput(argc, argv, &value, &radix, &operandSize) == VALID)
	{
		printTable(value, radix, operandSize);	
	}

	return 0;	
}

uint8_t invalidInput(int argc, char *argv[], int16_t* value, uint8_t* radix, uint8_t* operandSize)
{
	int16_t inputValidity = VALID;

	if (argc != NUMBER_OF_ARGUMENTS)
	{
		printf("Error bad input. Number of arguments incorrect.\n");
		inputValidity = INVALID;
	}
	else
	{
		*radix = atoi(argv[RADIX_ARGUMENT]);
		*operandSize = atoi(argv[OPERAND_ARGUMENT]);
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
			char* endPtr;
			*value = strtoimax(argv[VALUE_ARGUMENT], &endPtr, *radix);
			int16_t maxValue = (pow((double)BASE_TWO, (double)(*operandSize)) / SIGNED_RANGE_DIVISOR) - ONE;
			if ((*value) > maxValue)
			{
				printf("Error bad input. Input outside of operand range.\n");
				inputValidity = INVALID;
			}
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
	int16_t signedMagnitude = getSignMagnitude(value, operandSize);
	int16_t maxSignedMagnitude = maxSignedOnesComp;
	int16_t minSignedMagnitude = getSignMagnitude(-maxSignedMagnitude, operandSize);

	convertToBinaryString(absValue, operandSize, absBinaryString);
	convertToBinaryString(maxValue, operandSize, maxAbsBinaryString);
	convertToBinaryString(0, operandSize, minAbsBinaryString);
	convertToBinaryString(signedOnesComp, operandSize, signedOneCompBinaryString);
	convertToBinaryString(maxSignedOnesComp, operandSize, maxSignedOneCompBinaryString);
	convertToBinaryString(minSignedOnesComp, operandSize, minSignedOneCompBinaryString);	
	convertToBinaryString(signedTwosComp, operandSize, signedTwoCompBinaryString);
	convertToBinaryString(minSignedTwosComp, operandSize, minSignedTwoCompBinaryString);
	convertToBinaryString(signedMagnitude, operandSize, signMagnitudeBinaryString);
	convertToBinaryString(maxSignedMagnitude, operandSize, maxSignMagnitudeBinaryString);
	convertToBinaryString(minSignedMagnitude, operandSize, minSignMagnitudeBinaryString);

	printf("Input:	Value %d			Radix %d			Operand Size %d\n", value, radix, operandSize);
	printf("Output:					Value					Maximum				Minimum\n");
	printf("Binary (abs)							0b%s				0b%s				0b%s\n", absBinaryString, maxAbsBinaryString, minAbsBinaryString);
	printf("Octal (abs)								0%o					0%o					%o\n", absValue, maxValue, 0);
	printf("Decimal (abs)							%d						%d						%d\n", absValue, maxValue, 0);
	printf("Hexadecimal (abs)						0x%x					0x%x					0x%x\n", absValue, maxValue, 0);
	printf("Signed One's Compliment (abs)		0b%s				0b%s				0b%s\n", signedOneCompBinaryString, maxSignedOneCompBinaryString, minSignedOneCompBinaryString);
	printf("Signed Two's Compliment (abs)		0b%s				0b%s				0b%s\n", signedTwoCompBinaryString, maxSignedOneCompBinaryString, minSignedTwoCompBinaryString);
	printf("Sign-Magnitude							0b%s				0b%s				0b%s\n", signMagnitudeBinaryString, maxSignMagnitudeBinaryString, minSignMagnitudeBinaryString);
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

uint16_t getSignMagnitude(int16_t value, uint8_t operandSize)
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
