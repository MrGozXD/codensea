#include <stdio.h>
#include <stdlib.h>

#define SIZE_DICO 256
#define STRING_SIZE 512*1024

extern int dictionnaire[SIZE_DICO];

// declaration de nouveaux types de variables
typedef char* String;
typedef int* Dictionnary;

// prototypes
void countCharStatic (String s); // Travail sur le tableau statique
Dictionnary countCharDynamic (String s); // Même fonction mais en dynamique
void display (Dictionnary d);
String readFile(String fileName);
