/* 
 * PES Project One Program Two header code implementation
 *	Tristan Duenas
 *	GCC C99 compiler
 */

#ifndef __PROGRAM_TWO_H__
#define __PROGRAM_TWO_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#define ASCII_CODE_ARGUMENT_NUMBER 1

/*
 * Takes an unsigned 8 bit ascii code as an input and prints to the console the 
ascii code, the type of ascii code it is (lower case, upper case, digit, white space, special character), and the ascii character if it can print it.
 */
void displayASCII(uint8_t ascii);

#endif
