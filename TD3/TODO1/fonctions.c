#include "fonctions.h"

/**
 * @brief	Fonction types: affichage de différentes informations
 * concernant les types en langage C.
 */
void types()
{
	char a = 3;
	int b = 126;
	float c = 4.5;
	double d = 5.5;
	char res1 = 0;
	int res2 = 0;

	/* Taille des types */
	printf("Taille des types\n");
	printf("Nombre d'octets occupe par le type char : %lu\n", sizeof(char));
	printf("Nombre d'octets occupe par le type int : %lu\n", sizeof(int));
	printf("Nombre d'octets occupe par le type float : %lu\n",
		   sizeof(float));
	printf("Nombre d'octets occupe par le type double : %lu\n",
		   sizeof(double));
	printf("\n");

	/* Min/Max des types entiers */
	printf("Min/Max des types entiers\n");
	printf("char : [%d;%d]\n", CHAR_MIN, CHAR_MAX);
	printf("int : [%d;%d]\n", INT_MIN, INT_MAX);
	printf("unsigned char : [%d;%d]\n", 0, UCHAR_MAX);
	printf("\n");

	/* Min/Max des types entiers */
	printf("Min/Max des types à virgule flottante\n");
	printf("float : [%.3e;%.3e]\n", -FLT_MAX, FLT_MAX);
	printf("double : [%.3e;%.3e]\n", -DBL_MAX, DBL_MAX);
	printf("\n");

	/* Précision relative des nombres à virgule flottante */
	printf("Précision relative des nombres à virgule flottante\n");
	printf("float : %.3e\n", FLT_EPSILON);
	printf("double : %.3e\n", DBL_EPSILON);
	printf("\n");

	/* Affichage des variables */
	printf("Symboles pour afficher une variable d'un type donné\n");
	printf("char a = %d\n", a);
	printf("int b = %d\n", b);
	printf("float c = %f\n", c);
	printf("float c = %.2f avec 2 chiffres après la virgule\n", c);
	printf("double d = %lf\n", d);
	printf("\n");

	printf("A cogiter...\n");
	res1 = a + b;
	printf("la somme de a=%d et b=%d est %d\n", a, b, res1);
	res2 = a + b;
	printf("la somme de a=%d et b=%d est %d\n", a, b, res2);
	res2 = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12;
	printf("12! vaut %d\n", res2);
	res2 = res2 * 13;
	printf("13! vaut %d\n", res2);
	res2 = res2 * 14;
	printf("14! vaut %d\n", res2);
	printf("\n");
}

/**
 * @brief	Fonction convImp: affichage du résultat d'opérations
 * similaires faisant appel à des conversions implicites et conduisant
 * à des résultats différents.
 */
void convImp()
{
	int b = 126;
	float c = 4.5;
	int res1 = 0;
	float res2 = 0;

	res1 = b + c;
	res2 = b + c;

	printf("Conversion implicite\n");
	printf("la somme de b=%d et c=%f est %f\n", b, c, b + c);
	printf("la somme de b=%d et c=%f est %d\n", b, c, res1);
	printf("la somme de b=%d et c=%f est %f\n", b, c, res2);
	printf("\n");
}

/**
 * @brief	Fonction convExp: affichage de différents exemples
 * d'opérations similaires faisant appel à de la conversion implicite et
 * explicite et conduisant à des résultats différents.
 */
void convExp()
{
	int a = 5.5;
	int b = 4 / 5;
	float c = 4 / 5;
	float d = 4.0 / 5;
	float e = (float)4 / 5;
	float f = 4 / (float)5;

	printf(" Conversion explicite \n ");
	printf(" a = %d, b = %d, c = %f, d = %f, e = %f, f = %f \n ", a, b, c,
		   d, e, f);
	printf(" \n ");
}
