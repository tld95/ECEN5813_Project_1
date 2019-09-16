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

#define NUMBER_OF_ARGUMENTS 4
#define VALUE_ARGUMENT 1
#define RADIX_ARGUMENT 2
#define OPERAND_ARGUMENT 3

#define MAX_BINARY_STRING_SIZE 17

#define BINARY_HEADER_SIZE 2

#define SIGN_MAG_OPERAND_SIZE_FOUR_MASK 0x8;
#define SIGN_MAG_OPERAND_SIZE_EIGHT_MASK 0x80;
#define SIGN_MAG_OPERAND_SIZE_SIXTEEN_MASK 0x8000;

#define SIGNED_RANGE_DIVISOR 2
#define ONE 1

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
uint8_t invalidInput(int argc, char *argv[], int16_t* value, uint8_t* radix, uint8_t* operandSize);

/*
 * Prints to the console a formatted table of conversion on an input value with a specified radix and operand size.
 */
void printTable(int16_t value, uint8_t radix, uint8_t operandSize);

/*
 * Converts operand size amount of bits of a unsigned 16 bit value to a binary char array.
 */
void convertToBinaryString(int16_t value, uint8_t operandSize, char *binaryString);

/*
 * Returns the sign magnitude format of an input value based on a specified operand size.
 */
uint16_t getSignMagnitude(int16_t value, uint8_t operandSize);

#endif
