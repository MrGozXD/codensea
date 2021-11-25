#include "fonctions.h"
#include <time.h>

int main(void)
{

	float x = 0.5;
	float res;
	int cpt;
	TABfloat tab, tabdest;

	srand(time(NULL));

	res = myfct3(x);
	printf("Le resultat de sqrt(%f) est %.3f\n", x, res);
	myfct2(tab);

	for (cpt = 0; cpt < MAX_NUM; cpt++)
	{
		tabdest[cpt] = myfct3(tab[cpt]);
	}

	printf("La fonction mysqrtfct a été appelée %d fois\n",
		   COMPT_GLOBAL);

	return 0;
}
