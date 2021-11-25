#include "fonctions.h"

// ./main Cyrano.txt chiffre.txt 3

int main(int argc, char const **argv)
{
    /*if (argc != 4)
    {
        printf("Wrong usage : use %s fileName \n", argv[0]);
        return (EXIT_FAILURE);
    }*/
    printf("***** Chiffrement du fichier %s avec la clef %s *****\n", argv[1], argv[3]);
    char translate[SIZE] = {0};

    /*
    translate[65]=239;
    translate[239]=40;

    printf("Essai de findInArray : %d \n", findInArray(translate,239));
    printf("Essai de findInArray : %d \n", findInArray(translate,40));
    printf("Essai de findInArray : %d \n", findInArray(translate,100));
    */

    srand(argv[3]);
    //srand(3);
    fillArray(translate);
    displayArray(translate);

    unsigned char *test=cypher("ABRACADABRA",translate);
    unsigned char *retour=decypher(test,translate);
    printf("%s\n",test);
    for (int i = 0; i < strlen(test); i++)
    {
        printf("%x ",*(test+i));
    }
    printf("\n%s\n",retour);
    

    return 0;
}
