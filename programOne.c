#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define VALID 0
#define INVALID 1

#define BASE_TWO 2

#define VALUE_ARGUMENT 1
#define RADIX_ARGUMENT 2
#define OPERAND_ARGUMENT 3

typedef enum
{
	RADIX_EIGHT = 8,
	RADIX_TEN = 10,
	RADIX_SIXTEEN = 16
} radixValues;

typedef enum
{
	OPERAND_SIZE_FOUR = 4,
	OPERAND_SIZE_EIGHT = 8,
	OPERAND_SIZE_SIXTEEN = 16
} operandValues;

int invalidInput(int value, int radix, int operandSize);

int main(int argc, char*argv[])
{
	int valueArg = atoi(argv[VALUE_ARGUMENT]);
	int radixArg = atoi(argv[RADIX_ARGUMENT]);
	int operandArg = atoi(argv[OPERAND_ARGUMENT]);
	if (invalidInput(valueArg, radixArg, operandArg) == INVALID)
	{
		return -1;
	}
	
	return 0;	
}

int invalidInput(int value, int radix, int operandSize)
{
	int inputValidity = VALID;
	if ((radix != RADIX_EIGHT) && (radix != RADIX_TEN) && (radix != RADIX_SIXTEEN))
	{
		printf("Radix invalid\n");		
		inputValidity = INVALID;
	}
	if ((operandSize != OPERAND_SIZE_FOUR) && (operandSize != OPERAND_SIZE_EIGHT) && (operandSize != OPERAND_SIZE_SIXTEEN))
	{
		printf("Operand invalid\n");
		inputValidity = INVALID;
	}
	
	int maxValue = pow(BASE_TWO, operandSize);
	if (value > maxValue)
	{
		printf("Input outside of operand range\n");
		inputValidity = INVALID;
	}
	return inputValidity;
}
