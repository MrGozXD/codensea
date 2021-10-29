#include "quizz.h"

void entrerDonnees(ListStructEtu list, int s)
{
    
    
	for (int i=0;i<s;i++)
    {
		printf("Saisie de l'étudiant %d \n",i);
		list[i].id=i;
		printf("Nom ? : ");
		scanf("%s",list[i].nom);
		list[i].note=demanderNoteEtudiant();	
	}
    
}

// TODO : demanderNomEtudiant, check si la chaîne rentrée est bien en dessous de  MAX_NOM_LENGTH

int demanderNbEtudiants(void)
{
    int n;
    printf("Nombre d'etudiants (max=%d)? : ",MAX_LIST_SIZE);
    scanf("%d", &n);
    while(n>MAX_LIST_SIZE)
    {
        printf("\nEntrez un nombre compris entre 0 et %d : ",MAX_LIST_SIZE);
        scanf("%d", &n);
    }
    return n;
}

int demanderNoteEtudiant(void)
{
    int n;
    printf("Note ? : ");
    scanf("%d", &n);
    while(!((n <= MAX_NOTE) && (n >= MIN_NOTE)))
    {
        printf("\nEntrez un nombre compris entre %d et %d : ",MIN_NOTE,MAX_NOTE);
        scanf("%d", &n);
    }
    return n;
}



void afficherDonnees(ListStructEtu list, int s)
{
    printf("Liste des étudiants\n|Id \t| Nom \t| Note \t|\n");
    for (size_t i = 0; i < s; i++)
    {
        printf("|%d \t| %s \t| %d \t| \n",list[i].id, list[i].nom, list[i].note);
    }
    
}