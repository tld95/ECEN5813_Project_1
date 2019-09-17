/* 
 * PES Project One Program Two source code implementation
 *	Tristan Duenas
 *	GCC C99 compiler
 * References
 * http://www.cplusplus.com/reference/cstring/strtok/
 */

#include "ProgramTwo.h"

int main(int argc, char *argv[])
{
	// Parse constant input string
	// Remove {} from input string
	char ascii_string[MAX_ASCII_STRING_INPUT_SIZE];
	memset(ascii_string, 0, sizeof(char) * MAX_ASCII_STRING_INPUT_SIZE);
	strncpy(ascii_string, &argv[INPUT_ARGUMENT][1], strlen(argv[INPUT_ARGUMENT])-2);
	char values[MAX_ASCII_INPUTS][MAX_ASCI_CHAR_STRING_INPUT_SIZE];


	int8_t numASCII_inputs = 0;
	// Remove ',' from string
	// Referenced http://www.cplusplus.com/reference/cstring/strtok/
	char* ptr = strtok(ascii_string, ",");
	while (ptr != NULL)
	{
		strcpy(values[numASCII_inputs], ptr);
		ptr = strtok(NULL,",");
		numASCII_inputs++;
	}

	for (int32_t index = 0; index < numASCII_inputs; index++)
	{
		uint8_t ascii = atoi(values[index]);
		displayASCII(ascii);
		printf("\n");
	}

	return 0;	
}

void displayASCII(uint8_t ascii)
{
	if (islower(ascii))
	{
		printf("Code:%d	Type: Lower Case	ASCII Char:%c\n", ascii, ascii);
	}
	else if (isupper(ascii))
	{
		printf("Code:%d	Type: Upper Case	ASCII Char:%c\n", ascii, ascii);
	}
	else if (isdigit(ascii))
	{
		printf("Code:%d   Type: Digit   ASCII Char:%c\n", ascii, ascii);
	}
	else if (isspace(ascii) || iscntrl(ascii))
	{
		if (isprint(ascii))
		{
			printf("Code:%d   Type: White Space   ASCII Char:%c\n", ascii, ascii);
		}
		else
		{
			printf("Code:%d   Type: White Space   ASCII Char:\n", ascii);
		}
	}
	else if (ispunct(ascii))
	{
		if (isprint(ascii))
		{
			printf("Code:%d   Type: Special Character   ASCII Char:%c\n", ascii, ascii);
		}
		else
		{
			printf("Code:%d   Type: Special Character   ASCII Char:\n", ascii);
		}
	}
	else
	{
		printf("Input code is not a valid ascii character.");
	}
}
