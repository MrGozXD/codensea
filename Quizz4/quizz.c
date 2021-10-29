#include "quizz.h"

void entrerDonnees(ListStructEtu list, int s)
{
	for (int i=0;i<s;i++)
    {
		printf("Saisie de l'étudiant %d \n",i);
		list[i].id=i;
		printf("Nom ? : ");
		scanf("%s",list[i].nom);
		printf("Note ? : ");
		scanf("%d",&(list[i].note));	
	}	
}

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