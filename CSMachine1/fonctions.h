#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

unsigned char findInArray(unsigned char array[SIZE], unsigned char value);
void fillArray(unsigned char array[SIZE]);
void displayArray(unsigned char array[SIZE]);
unsigned char * cypher(unsigned char * sInput,unsigned char array[SIZE]);
unsigned char *decypher(unsigned char *sInput, unsigned char array[SIZE]);