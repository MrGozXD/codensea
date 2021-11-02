#include "fonctions.h"

/**
 * Fonction createNinja
 * Crée une structure NINJA à partir de son nom et de son niveau de chakra.
 * Mets les pointeurs précédents et suivants à NULL.
 * @param nom Nom du ninja
 * @param chakra Niveau du chakra du ninja
 * @return Pointeur sur le ninja créé
 */
NINJA* createNinja(char nom[NBLETTRES+1], int chakra, NINJA* p, NINJA* n){
	NINJA *nin;
	nin=(NINJA*)malloc(sizeof(NINJA));
	strcpy(nin->nom, nom);
	nin->chakra=chakra;
	nin->previous=p;
	nin->next=n;
	return nin;
}

/**
 * Fonction createClan
 * Crée une structure CLAN à partir du nom du clan et d'une structure NINJA.
 * Mets les pointeurs à la structure NINJA.
 * @param nom Nom du clan
 * @param hokage Poineur sur une structure NINJA chef de liste
 * @return Pointeur sur le clan créé
 */
CLAN* createClan(char nom[NBLETTRES+1],NINJA* hokage){
	CLAN* clan;
	clan=(CLAN*)malloc(sizeof(CLAN));
	strcpy(clan->nom, nom);
	if(hokage!=NULL){
		clan->nombre=1;		
		clan->hokage = hokage;
		clan->genin = hokage;
	}else{
		clan->nombre=0;		
		clan->hokage = NULL;
		clan->genin = NULL;		
	}
	return clan;
}

/**
 * Fonction isClanEmpty
 * Teste si une structure CLAN est vide.
 * @param clan Pointeur sur la structure CLAN concernée
 * @return 1 si le clan est vide, 0 sinon.
 */
int isClanEmpty(CLAN* clan){
	if(clan->hokage==NULL) return 1;
	else return 0;
}

/**
 * Fonction searchNinjaByName
 * Trouve le pointeur sur la structure NINJA dont le nom est celui recherché.
 * @param clan Pointeur sur la structure CLAN concernée
 * @param nom Nom du ninja recherché
 * @return Pointeur sur le ninja recherché.
 */
NINJA* searchNinjaByName(CLAN* clan, char nom[NBLETTRES+1]){
	NINJA *found=NULL;
	if(clan!=NULL){
		NINJA *cur=clan->hokage;
		while(cur!=NULL){
			if(strcmp(cur->nom,nom)==0){
				found=cur;
				break;
			}
			cur=cur->next;
		}
	}
	return found;
}

/**
 * Fonction 
 * 
 */
void fonction01(CLAN* clan){
	NINJA *cur=clan->genin;
	NINJA *previous;
	while(cur!=NULL){
		previous=cur->previous;
		free(cur);
		clan->nombre--;
		cur=previous;
	}
	free(clan);
}

/**
 * Fonction 
 *
 */
void fonction02(CLAN* clan, NINJA* hokage){
	if(clan!=NULL){
		if(!isClanEmpty(clan)){
			hokage->next=clan->hokage;
			clan->hokage->previous=hokage;
			clan->hokage=hokage;
		}
		else{
			clan->hokage=hokage;
			clan->genin=hokage;
		}
		clan->nombre++;
	}
}

/**
 * Fonction 
 * 
 */
void fonction03(CLAN* clan, NINJA* genin){
	if(clan!=NULL){
		if(!isClanEmpty(clan)){
			genin->previous=clan->genin;
			clan->genin->next=genin;
			clan->genin=genin;
		}
		else{
			clan->hokage=genin;
			clan->genin=genin;
		}
		clan->nombre++;
	}
}

/**
 * Fonction
 *
 */
int fonction04(CLAN* clan, NINJA* nin, char nom[NBLETTRES+1]){
	NINJA* found=NULL;
	NINJA* previous=NULL;
	found=searchNinjaByName(clan,nom);
	if(found!=NULL){
		if(found!=clan->hokage){
			previous=found->previous;
			found->previous=nin;
			nin->next=found;
			previous->next=nin;
			nin->previous=previous;
			clan->nombre++;
		}
		else{
			function02(clan,nin);
		}
		return 0;
	}
	else{
		printf("insertion impossible car aucun Ninja de ce nom.\n");
		return -1;
	}
}

/**
 * Fonction 
 * 
 */
int fonction05(CLAN* clan, NINJA* nin, char nom[NBLETTRES+1]){
	NINJA* found=NULL;
	NINJA* next=NULL;
	found=searchNinjaByName(clan,nom);
	if(found!=NULL){
		if(found!=clan->genin){
			next=found->next;
			found->next=nin;
			nin->previous=found;
			next->previous=nin;
			nin->next=next;	
			clan->nombre++;		
		}
		else{
			function03(clan,nin);
		}
		return 0;
	}
	else{
		printf("insertion impossible car aucun Ninja de ce nom.\n");
		return -1;
	}
}

/**
 * Fonction 
 * 
 */
void fonction06(CLAN *clan){
	NINJA* nin=NULL;
	if(clan!=NULL){
		if(!isClanEmpty(clan)){
			nin=clan->hokage;
			if(clan->hokage->next!=NULL){
				clan->hokage=clan->hokage->next;
				clan->hokage->previous=NULL;
			}
			else{
				printf("Mort du clan\n");
			}
			free(nin);
			clan->nombre--;
		}
		else{
			printf("Il n'y avait déjà plus de ninja dans ce clan...\n");
		}
	}
	else{
		printf("Le clan etait deja mort...\n");
	}
}

/**
 * Fonction 
 * 
 */
void fonction07(CLAN *clan){
	NINJA* nin=NULL;
	if(clan!=NULL){
		if(!isClanEmpty(clan)){
			nin=clan->genin;
			if(clan->genin->previous!=NULL){
				clan->genin=clan->genin->previous;
				clan->genin->next=NULL;
			}
			else{
				printf("Mort du clan\n");
			}
			free(nin);
			clan->nombre--;
		}
		else{
			printf("Il n'y avait déjà plus de ninja dans ce clan...\n");
		}
	}
	else{
		printf("Le clan etait deja mort...\n");
	}
}

/**
 * Fonction 
 * 
 */
void fonction08(CLAN *clan, char nom[NBLETTRES+1]){
	NINJA* nin=NULL;
	NINJA* previous=NULL;
	NINJA* next=NULL;
	if(clan!=NULL){
		if(!isClanEmpty(clan)){
			nin=searchNinjaByName(clan,nom);
			if(nin!=NULL){
				if(nin==clan->hokage){
					function06(clan);
				}
				else{
					if(nin==clan->genin){
						function07(clan);
					}
					else{
						previous=nin->previous;
						next=nin->next;
						previous->next=next;
						next->previous=previous;
						free(nin);
						clan->nombre--;
					}
				}
			}
			else{
				printf("Aucun ninja de ce nom.\n");
			}
		}
		else{
			printf("Il n'y avait déjà plus de ninja dans ce clan...\n");
		}
	}
	else{
		printf("Le clan etait deja mort...\n");
	}
}