#include <stdio.h>
#include <stlib.h>

#define NBLETTRES 20

typedef struct ninja
{
    char nom[NBLETTRES + 1];
    int chakra;
} NINJA;

/* Equivalent à :

struct ninja
{
    char nom[NBLETTRES+1];
    int chakra;
};

typedef struct ninja NINJA;

*/
