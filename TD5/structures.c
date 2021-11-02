#include "structures.h"

NINJA *createNINJA(char name[], int chakra, NINJA *p, NINJA *n)
{
    // Création d'un ninja et allocation dynamique
    NINJA *newNinja = (NINJA *)malloc(1, sizeof(NINJA)); // Cast le type de pointeur devant malloc/calloc

    strcpy(newNinja->nom, name);
    newNinja->chakra = chakra;
    newNinja->previous = p;
    newNinja->next = n;

    return newNinja;
}

void dispNinjaPt(NINJA *ninja)
{
    printf("Ninja : %s\nChakra : %d\n", ninja->nom, ninja->chakra);
}

void dispNinja(NINJA ninja)
{
    printf("Ninja : %s\nChakra : %d\n", ninja.nom, ninja.chakra);
}