#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NBLETTRES 20

typedef struct ninja
{
    char nom[NBLETTRES + 1];
    int chakra;
    struct ninja *previous; // Impossible d'utiliser le nom du typedef
    struct ninja *next;
} NINJA;

/* Equivalent à :

struct ninja
{
    char nom[NBLETTRES+1];
    int chakra;
    struct ninja* previous;
    struct ninja* next;
};

typedef struct ninja NINJA;

*/

typedef struct clan
{
    char nom[NBLETTRES + 1];
    int nombre;
    NINJA *hokage;
    NINJA *genin;
} CLAN;

NINJA *createNINJA(char[], int, NINJA *, NINJA *);
void dispNinja(NINJA);     // Affichage ninja statique
void dispNinjaPt(NINJA *); // Affichage ninja dynamique