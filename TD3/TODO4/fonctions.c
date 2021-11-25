#include "fonctions.h"

/* initialisation de variable globale */
int COMPT_GLOBAL = 0;

void myfct1()
{
	printf("%s\n", WELCOMING_MESSAGE);
}

void myfct2(TABfloat tab)
{
	int i;
	for (i = 0; i < TAILLE; i++)
	{
		tab[i] = ((rand() % 10000) / 100.0);
	}
}

float myfct3(float arg1)
{
	int i;
	float x = arg1;
	for (i = 0; i < MAX_NUM; i++)
	{
		x = (x + arg1 / x) / 2;
	}
	COMPT_GLOBAL++;
	return x;
}

void permute(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}