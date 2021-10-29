#include "quizz.h"

int main(int argc, char const *argv[])
{
    ListStructEtu data;
    int n;
    n=demanderNbEtudiants();
    entrerDonnees(data, n);
    return 0;
}
