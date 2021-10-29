#include "quizz.h"

int main(int argc, char const *argv[])
{
    // Création Data
    ListStructEtu data;
    int n;
    n = demanderNbEtudiants();
    entrerDonnees(data, n);
    printf("\nDonnees avant le tri\n\n");
    afficherDonnees(data, n);

    // Tri Notes
    trierDonneesNote(data, n);
    printf("\nDonnees après le tri de notes\n\n");
    afficherDonnees(data, n);

    // Tri Noms
    trierDonneesNom(data, n);
    printf("\nDonnees après le tri de noms\n\n");
    afficherDonnees(data, n);

    // Tri Noms Notes

    trierDonneesNoteNom(data, n);
    printf("\nDonnees après le tri Noms Notes\n\n");
    afficherDonnees(data, n);

    return 0;
}
