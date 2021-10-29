#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOM_LENGTH 50
#define MAX_LIST_SIZE 20

typedef struct etudiant
{
    int id;
    char nom[MAX_NOM_LENGTH];
    int note;
}StructEtu;

typedef StructEtu ListStructEtu[MAX_LIST_SIZE];

void entrerDonnees(ListStructEtu list, int s);
void afficherDonnees(ListStructEtu list, int s);
void trierDonnees(ListStructEtu list, int s);
void trierDonneesNom(ListStructEtu list, int s);
int demanderNbEtudiants(void);