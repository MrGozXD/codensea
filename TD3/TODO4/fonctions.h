#include <stdio.h>
#include <stdlib.h>

#define WELCOMING_MESSAGE "Welcome to mylib"
#define TAILLE 10
#define MAX_NUM 10

typedef float TABfloat[TAILLE];

/* déclaration de variable globale */
int COMPT_GLOBAL;

void myfct1();
void myfct2(TABfloat);
float myfct3(float);
void permute(int*,int*);