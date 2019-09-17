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
#define LAST_FOUR_BITS_MASK 0xF
#define BIT_SHIFT_AMOUNT_FOR_LAST_FOUR_BITS 12
#define MAX_BINARY_STRING_SIZE 4
#define ON 1
#define NUM_BYTES_IN_UINT_16 2
#define NUM_BITS_IN_UINT_16 16
#define FOUR_BITS 4
#define EIGHT_BITS 8
#define FIRST_BYTE 0
#define SECOND_BYTE 1
#define THREE 3
#define SHIFT_ONE 1
#define SHIFT_TWO 2
#define SHIFT_THREE 3

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
 * Gets the last 4 bits of an unsigned 16 bit value, and outputs those last 4 bits through an output pointer, along with whether or not 3 bits of those 4 are on.
 */
void testLastFourBitsThreeBitsOn(uint16_t input, uint8_t *lastFourBits, uint8_t *threeBitsOn);

/*
 * Prints to the console the last 4 bits of an unsigned 16 bit value, along with whether or not 3 bits are on.
 */
void outputLastFourBitsResult(uint8_t lastFourBits, uint8_t threeBitsOn);

/*
 * Reverses the byte order of an unsigned 16 bit value.
 */
void reverseByteOrder(uint16_t *input);

/*
 * Rotates n bits in an unsigned 16 bit value either left or right.
 */
void rotateValue(uint16_t *input, uint16_t numBits, rotateDirection direction);

#endif
