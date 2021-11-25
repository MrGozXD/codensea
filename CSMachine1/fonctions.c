#include "fonctions.h"

unsigned char findInArray(unsigned char array[], unsigned char value)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] == value)
        {
            return i;
        }
        else if (i == SIZE - 1)
        {
            return 0;
        }
    }
}

void fillArray(unsigned char array[SIZE])
{
    array[0] = 0;
    for (int i = 1; i < SIZE; i++)
    {
        unsigned char test = rand()%SIZE; // valeur aléatoire comprise entre 0 et 255
        while (findInArray(array, test) != 0)
        {
            test = test + 1;
            if (test == 0)
            {
                test = 1;
            }
        }
        array[i] = test;
    }
}

void displayArray(unsigned char array[SIZE])
{
    for (int i = 65; i < 91; i++)
    {
        printf("%c => (%d) \n", i, findInArray(array, i));
    }
}

unsigned char *cypher(unsigned char *sInput, unsigned char array[SIZE])
{
    unsigned char *sOutput = calloc(strlen(sInput), sizeof(unsigned char));
    for (int i = 0; i < strlen(sInput); i++)
    {
        sOutput[i]=findInArray(array,sInput[i]);
    }  
    return sOutput;
}

unsigned char *decypher(unsigned char *sInput, unsigned char array[SIZE])
{
    unsigned char *sOutput = calloc(strlen(sInput), sizeof(unsigned char));
    for (int i = 0; i < strlen(sInput); i++)
    {
        sOutput[i]=findInArray(sInput,array[i]);
    }  
    return sOutput;
}