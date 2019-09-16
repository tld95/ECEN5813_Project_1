/* 
 * PES Project One Program Three header code implementation
 *	Tristan Duenas
 *	GCC C99 compiler
 */

#ifndef __PROGRAM_THREE_H__
#define __PROGRAM_THREE_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define FIRST_BIT 0x1
#define LAST_THREE_BITS_MASK 0x7
#define BIT_SHIFT_AMOUNT_FOR_LAST_THREE_BITS 13
#define MAX_BINARY_STRING_SIZE 4
#define ON 1
#define NUM_BYTES_IN_UINT_16 2
#define NUM_BITS_IN_UINT_16 16
#define FOUR_BITS 4
#define EIGHT_BITS 8
#define FIRST_BYTE 0
#define SECOND_BYTE 1

typedef enum
{
	LEFT = 0,
	RIGHT = 1
} rotateDirection;

/*
 * Converts n bits of a unsigned 16 bit value to a binary char array.
 */
void convertToBinaryString(uint16_t value, uint8_t amountOfBits, char* binaryString);

/*
 * Gets the last 3 bits of an unsigned 16 bit value, and outputs those 3 bits    through an output pointer, along with whether or not the last 3 bits are on.
 */
void testLasThreeBits(uint16_t input, uint8_t *lastThreeBits, uint8_t *lastThreeBitsOn);

/*
 * Prints to the console the last 3 bits of an unsigned 16 bit value, along with whether or not the last 3 bits are on.
 */
void outputLastThreeBitsResult(uint8_t lastThreeBits, uint8_t lastThreeBitsOn);

/*
 * Reverses the byte order of an unsigned 16 bit value.
 */
void reverseByteOrder(uint16_t *input);

/*
 * Rotates n bits in an unsigned 16 bit value either left or right.
 */
void rotateValue(uint16_t *input, uint16_t numBits, rotateDirection direction);

#endif
