#include "quizz.h"

int main(int argc, char const *argv[])
{
    ListStructEtu data;
    int n;
    n=demanderNbEtudiants();
    entrerDonnees(data, n);
    printf("\nDonnees avant le tri\n\n");
    afficherDonnees(data,n);
    trierDonnees(data,n);
    printf("\nDonnees après le tri\n\n");
    afficherDonnees(data,n);
    return 0;
}
