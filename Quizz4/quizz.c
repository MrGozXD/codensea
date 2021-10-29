#include "quizz.h"

void entrerDonnees(ListStructEtu list, int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("Saisie de l'étudiant %d \n", i);
        list[i].id = i;
        printf("Nom ? : ");
        scanf("%s", list[i].nom);
        list[i].note = demanderNoteEtudiant();
    }
}

// TODO : demanderNomEtudiant, check si la chaîne rentrée est bien en dessous de  MAX_NOM_LENGTH (utiliser strlen)

int demanderNbEtudiants(void)
{
    int n;
    printf("Nombre d'etudiants (max=%d)? : ", MAX_LIST_SIZE);
    scanf("%d", &n);
    while (n > MAX_LIST_SIZE)
    {
        printf("\nEntrez un nombre compris entre 0 et %d : ", MAX_LIST_SIZE);
        scanf("%d", &n);
    }
    return n;
}

int demanderNoteEtudiant(void)
{
    int n;
    printf("Note ? : ");
    scanf("%d", &n);
    while (!((n <= MAX_NOTE) && (n >= MIN_NOTE)))
    {
        printf("\nEntrez un nombre compris entre %d et %d : ", MIN_NOTE, MAX_NOTE);
        scanf("%d", &n);
    }
    return n;
}

void afficherDonnees(ListStructEtu list, int s)
{
    printf("Liste des étudiants\n|Id \t| Nom \t| Note \t|\n");
    for (size_t i = 0; i < s; i++)
    {
        printf("|%d \t| %s \t| %d \t| \n", list[i].id, list[i].nom, list[i].note);
    }
}

void trierDonneesNote(ListStructEtu list, int s)
{
    int i, j;
    StructEtu temp;
    for (i = s - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (list[j + 1].note < list[j].note)
            {
                temp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = temp;
            }
        }
        /* pour i allant de (taille de T)-1 à 1
       pour j allant de 0 à i-1
           si T[j+1] < T[j]
               (T[j+1], T[j]) = (T[j], T[j+1])*/
    }
}

void trierDonneesNom(ListStructEtu list, int s)
{
    int i, j;
    StructEtu temp;
    for (i = s - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (strcmp(list[j + 1].nom, list[j].nom) < 0)
            {
                temp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = temp;
            }
        }
        /* pour i allant de (taille de T)-1 à 1
       pour j allant de 0 à i-1
           si T[j+1] < T[j]
               (T[j+1], T[j]) = (T[j], T[j+1])*/
    }
}

void trierDonneesNoteNom(ListStructEtu list, int s)
{
    int i, j;
    StructEtu temp;
    for (i = s - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (strcmp(list[j + 1].nom, list[j].nom) < 0)
            {
                temp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = temp;
            }
        }
        trierDonneesNote(list, s);
        /* pour i allant de (taille de T)-1 à 1
       pour j allant de 0 à i-1
           si T[j+1] < T[j]
               (T[j+1], T[j]) = (T[j], T[j+1])*/
    }
}