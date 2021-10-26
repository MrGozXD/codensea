#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DIMX 5
#define DIMY 5

typedef struct etat
{    
    int tableau[DIMX][DIMY];
    int fourmiDirection;        // 0 : Nord, 1 : Est, 2 : Sud, 3 : Ouest
    int fourmiX;
    int fourmiY;
    struct etat *next;
    
}ETAT;

typedef ETAT * ptETAT;

ptETAT createNewState(int x, int y, int direction);
void displayState(ptETAT e);
void createNextState(ptETAT tete);
