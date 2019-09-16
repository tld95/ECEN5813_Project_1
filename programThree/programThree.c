#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define LAST_THREE_BITS_MASK 0x7
#define BIT_SHIFT_AMOUNT_FOR_LAST_THREE_BITS 13
#define MAX_BINARY_STRING_SIZE 4
#define ON 1
#define NUM_BYTES_IN_UINT_16 2
#define NUM_BITS_IN_UINT_16 16

typedef enum
{
	LEFT = 0,
	RIGHT = 1
} rotateDirection;

void convertToBinaryString(uint16_t value, uint8_t operandSize, char* binaryString);
void testLasThreeBits(uint16_t input, uint8_t *lastThreeBits, uint8_t *lastThreeBitsOn);
void outputLastThreeBitsResult(uint8_t lastThreeBits, uint8_t lastThreeBitsOn);
void reverseByteOrder(uint16_t *input);
void rotateValue(uint16_t *input, uint16_t numBits, rotateDirection direction);

int main(int argc, char *argv[])
{
	uint16_t input = 0xCAFE;
	uint8_t lastThreeBits = 0;
	uint8_t lastThreeBitsOn = 0;	

	printf("Starting Value: 0x%X\n", input);

	testLasThreeBits(input, &lastThreeBits, &lastThreeBitsOn);
	outputLastThreeBitsResult(lastThreeBits, lastThreeBitsOn);
	
	reverseByteOrder(&input);
	printf("Reversed Byte Order: 0x%X\n", input);

	testLasThreeBits(input, &lastThreeBits, &lastThreeBitsOn);
	outputLastThreeBitsResult(lastThreeBits, lastThreeBitsOn);

	rotateValue(&input, 4, LEFT);
	printf("Rotated 4 bits to the left: 0x%X\n", input);

	testLasThreeBits(input, &lastThreeBits, &lastThreeBitsOn);
	outputLastThreeBitsResult(lastThreeBits, lastThreeBitsOn);

	rotateValue(&input, 8, LEFT);
	printf("Rotated 8 bits to the right: 0x%X\n", input);

	testLasThreeBits(input, &lastThreeBits, &lastThreeBitsOn);
	outputLastThreeBitsResult(lastThreeBits, lastThreeBitsOn);

	return 0;	
}

void reverseByteOrder(uint16_t *input)
{
	uint8_t *bytes = (uint8_t*)input;
	uint8_t tempByte = bytes[0];
	bytes[0] = bytes[1];
	bytes[1] = tempByte;
}

void rotateValue(uint16_t *input, uint16_t numBits, rotateDirection direction)
{
	uint16_t bitsSaved = 0;
	switch (direction)
	{
		case LEFT:
			bitsSaved = ((*input) >> (NUM_BITS_IN_UINT_16 - numBits));
			((*input) <<= numBits); 
			(*input) |= bitsSaved;
			break;
		case RIGHT:
			bitsSaved = ((*input) << (NUM_BITS_IN_UINT_16 - numBits)) >> (NUM_BITS_IN_UINT_16 - numBits);
			((*input) >>= numBits);
			(*input) |= (bitsSaved << (NUM_BITS_IN_UINT_16 - numBits));
			break;
		default:
			// Do nothing
			break;
	}
}

void testLasThreeBits(uint16_t input, uint8_t *lastThreeBits, uint8_t *lastThreeBitsOn)
{
	*lastThreeBits = ((input >> BIT_SHIFT_AMOUNT_FOR_LAST_THREE_BITS) & LAST_THREE_BITS_MASK);
	*lastThreeBitsOn = ((*lastThreeBits) == LAST_THREE_BITS_MASK);
}

void outputLastThreeBitsResult(uint8_t lastThreeBits, uint8_t lastThreeBitsOn)
{
	char binaryString[MAX_BINARY_STRING_SIZE];
	convertToBinaryString(lastThreeBits, 3, binaryString);
	if (lastThreeBitsOn == ON)
	{
		printf("%s, true\n", binaryString);
	}
	else
	{
		printf("%s, false\n", binaryString);
	}
}

void convertToBinaryString(uint16_t value, uint8_t operandSize, char* binaryString)
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
