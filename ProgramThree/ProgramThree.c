/* 
 * PES Project One Program Three source code implementation
 *	Tristan Duenas
 *	GCC C99 compiler
 */

#include "ProgramThree.h"

int main(int argc, char *argv[])
{
	uint16_t input = 0xCAFE;
	uint8_t lastFourBits = 0;
	uint8_t threeBitsOn = 0;	

	printf("Starting Value: 0x%X\n", input);

	testLastFourBitsThreeBitsOn(input, &lastFourBits, &threeBitsOn);
	outputLastFourBitsResult(lastFourBits, threeBitsOn);
	
	reverseByteOrder(&input);
	printf("Reversed Byte Order: 0x%X\n", input);

	testLastFourBitsThreeBitsOn(input, &lastFourBits, &threeBitsOn);
	outputLastFourBitsResult(lastFourBits, threeBitsOn);

	rotateValue(&input, FOUR_BITS, LEFT);
	printf("Rotated 4 bits to the left: 0x%X\n", input);

	testLastFourBitsThreeBitsOn(input, &lastFourBits, &threeBitsOn);
	outputLastFourBitsResult(lastFourBits, threeBitsOn);

	rotateValue(&input, EIGHT_BITS, LEFT);
	printf("Rotated 8 bits to the right: 0x%X\n", input);

	testLastFourBitsThreeBitsOn(input, &lastFourBits, &threeBitsOn);
	outputLastFourBitsResult(lastFourBits, threeBitsOn);

	return 0;	
}

void reverseByteOrder(uint16_t *input)
{
	uint8_t *bytes = (uint8_t*)input;
	uint8_t tempByte = bytes[FIRST_BYTE];
	bytes[FIRST_BYTE] = bytes[SECOND_BYTE];
	bytes[SECOND_BYTE] = tempByte;
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

void testLastFourBitsThreeBitsOn(uint16_t input, uint8_t *lastFourBits, uint8_t *threeBitsOn)
{
	*lastFourBits = ((input >> BIT_SHIFT_AMOUNT_FOR_LAST_FOUR_BITS) & LAST_FOUR_BITS_MASK);
	uint8_t bitOne = (*lastFourBits) & 0x1;
	uint8_t bitTwo = ((*lastFourBits) >> SHIFT_ONE) & 0x1;
	uint8_t bitThree = ((*lastFourBits) >> SHIFT_TWO) & 0x1;
	uint8_t bitFour = ((*lastFourBits) >> SHIFT_THREE) & 0x1;
	*threeBitsOn = ((bitOne + bitTwo + bitThree + bitFour) == THREE);
}

void outputLastFourBitsResult(uint8_t lastFourBits, uint8_t threeBitsOn)
{
	char binaryString[MAX_BINARY_STRING_SIZE];
	convertToBinaryString(lastFourBits, 4, binaryString);
	if (threeBitsOn == ON)
	{
		printf("%s, true\n", binaryString);
	}
	else
	{
		printf("%s, false\n", binaryString);
	}
}

void convertToBinaryString(uint16_t value, uint8_t amountOfBits, char* binaryString)
{
	memset(binaryString, 0, sizeof(char) *  MAX_BINARY_STRING_SIZE);
	for (uint8_t bit = 1; bit <= amountOfBits; bit++)
	{
		if (((value >> (amountOfBits-bit)) & FIRST_BIT) == 1)
		{
			binaryString[bit-1] = '1';
		}
		else
		{
			binaryString[bit-1] = '0';
		}
	}
}
