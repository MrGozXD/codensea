#include "fonctions.h"

void countCharStatic (String s){
	while(*s!='\0'){	
		dictionnaire[*s]++;
		s++;	
		}
	
	}

Dictionnary countCharDynamic (String s){
	Dictionnary  d = calloc(SIZE_DICO,sizeof(int));
	while(*s!='\0'){
		(*(d+(*s)))++;
		s++;	
		}
	return d;
	}
	
void display(Dictionnary d){
	int i;
	for(i='A'; i<='Z';i++)
		{
		printf("%c => %d \t %c => %d\n",i,d[i],i+32,d[i+32]);	
		}
	}


String readFile(String fileName){
	String buf = calloc (STRING_SIZE,sizeof(char));
	FILE * filePtr=fopen(fileName,"r");
	fread(buf, 1,STRING_SIZE, filePtr);
	fclose(filePtr);
	return buf;
}
