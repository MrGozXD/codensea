#include "structures.h"

int main(int argc, char const *argv[])
{
    /* L’initialisation de la structure peut se faire en même temps 
    ou après la déclaration de lastructure. */

    NINJA nin1;
    strcpy(nin1.nom, "Rock Lee");
    nin1.chakra = 500;

    NINJA nin2 = {"Sasuke", 1500};

    NINJA *nin3 = createNINJA("Naruto", 3000, NULL, NULL);
    NINJA *nin4 = createNINJA("Kakashi", 2000, NULL, NULL);
    NINJA *nin5 = createNINJA("Yamato", 2500, NULL, NULL);

    dispNinja(nin1);
    dispNinja(nin2);
    dispNinjaPt(nin3);
    dispNinjaPt(nin4);
    dispNinjaPt(nin5);

    return 0;
}
