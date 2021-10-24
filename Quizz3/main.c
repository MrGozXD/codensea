#include "fonctions.h"

int dictionnaire[SIZE_DICO]={0};

int main (int argc, char ** argv){
		if (argc !=2){
			printf("Wrong usage : use %s fileName \n",argv[0]);
			return (EXIT_FAILURE);
		}
		printf("*********** Dictionnaire du fichier %s *********** \n",argv[1]);

		String s=readFile(argv[1]);
		Dictionnary d = countCharDynamic(s);

		display(d);
		
		return (EXIT_SUCCESS);		
}
