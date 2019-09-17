/* 
 * PES Project One Program One header code implementation
 *	Tristan Duenas
 *	GCC C99 compiler
 */

#ifndef __PROGRAM_ONE_H__
#define __PROGRAM_ONE_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <inttypes.h>

#define VALID 0
#define INVALID 1

#define BASE_TWO 2

#define INPUT_ARGUMENT 1

#define MAX_BINARY_STRING_SIZE 17

#define BINARY_HEADER_SIZE 2

#define SIGN_MAG_OPERAND_SIZE_FOUR_MASK 0x8;
#define SIGN_MAG_OPERAND_SIZE_EIGHT_MASK 0x80;
#define SIGN_MAG_OPERAND_SIZE_SIXTEEN_MASK 0x8000;

#define SIGNED_RANGE_DIVISOR 2
#define ONE 1

#define MAX_INPUT_SETS 11
#define MAX_STRING_INPUT_SIZE 20
#define INPUTS_IN_A_SET 3
#define INPUT_ONE 0
#define INPUT_TWO 1
#define INPUT_THREE 2

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

/*
 * Verifies input value, radix, and operand size are valid prior to performing any operations on the input value.
 */
uint8_t invalidInput(char *valueString, char *radixString, char *operandSizeString, int16_t* value, uint8_t* radix, uint8_t* operandSize);

/*
 * Prints to the console a formatted table of conversion on an input value with a specified radix and operand size.
 */
void printTable(char* origValue, int16_t value,  uint8_t radix, uint8_t operandSize);

/*
 * Converts operand size amount of bits of a unsigned 16 bit value to a binary char array.
 */
void convertToBinaryString(int16_t value, uint8_t operandSize, char *binaryString);

/*
 * Returns the sign magnitude format of an input value based on a specified operand size.
 */
uint16_t getSignMagnitude(int16_t value, uint8_t operandSize, int8_t* signMagValidity);

#endif
