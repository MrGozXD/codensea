#include "langton.h"

ptETAT createNewState(int x, int y, int direction)
{
    
    /*création d'un etat et allocation dynamique*/
    ptETAT newState = calloc(1,sizeof(ETAT));
    
    /*Initialisation des coordonnées de la fourmi*/
    newState->fourmiDirection=direction;
    newState->fourmiX=x;
    newState->fourmiY=y;
    newState->next=NULL;

    /*Initialisation à 0 d'un tableau à 2 dimensions => double boucle. Inutile étant donné qu'on a utilisé calloc.
    for (size_t i = 0; i < DIMX; i++)
    {
        for (size_t j = 0; j < DIMY; j++)
        {
            newState->tableau[i][j]=0;
        }
    }*/
    return newState;
}

void createNextState (ptETAT tete)
{

    ptETAT old=tete;
    ptETAT new=createNewState(0,0,0);
    old->next=new;
    int rebond=0;   //0 : false, 1 : true

    // Balayage jusqu'à la fin de la chaîne
    while (old->next!=NULL)
    {
        old=old->next;
    }

    // Et chaînage du new élément (nouvelle compétence acquise)
    old->next=new;
    
    
    //FSM de la gestion des rebonds : si la fourmi touche un bord du tableau, elle effectue une rotation de pi/2

    switch (old->fourmiDirection)
    {
    case 0: // Cas Nord
        if (old->fourmiX==0)
        {
            old->fourmiDirection=2;
            rebond=1;
        }
        
        break;
    
    case 1: // Cas Est
        if (old->fourmiY==DIMY)
        {
            old->fourmiDirection=3;
            rebond=1;
        }
        
        break;
    
    case 2: // Cas Sud
        if (old->fourmiX==DIMX)
        {
            old->fourmiDirection=0;
            rebond=1;
        }
        break;
    
    case 3: // Cas Ouest
        if (old->fourmiY==0)
        {
            old->fourmiDirection=1;
            rebond=1;
        }
        break;
    
    default:
        break;
    }
    
    // Changement de direction de la fourmi 

    if ((old->tableau[old->fourmiX][old->fourmiY]==0)&&(rebond==0)) //
    {
        new->fourmiDirection=(old->fourmiDirection+1)%4; // direction+1
    }
    else if ((old->tableau[old->fourmiX][old->fourmiY]==1)&&(rebond==0))
    {
        new->fourmiDirection=(old->fourmiDirection+3)%4; // direction-1
    }

    // Recopie du tableau 
    for (size_t i = 0; i < DIMX; i++)
    {
        for (size_t j = 0; j < DIMY; j++)
        {
            new->tableau[i][j]=old->tableau[i][j];
        }
        
    }

    // Recopie de la position initiale de la fourmi
    new->fourmiX=old->fourmiX;
    new->fourmiY=old->fourmiY;

    /*Déplacement de la fourmi*/
    switch (new->fourmiDirection)
    {
    case 0: // Cas Nord
        new->fourmiX=old->fourmiX-1;
        new->fourmiY=old->fourmiY;
        break;

    case 1: // Cas Est
        new->fourmiX=old->fourmiX;
        new->fourmiY=old->fourmiY+1;
        break;

    case 2: // Cas Sud
        new->fourmiX=old->fourmiX+1;
        new->fourmiY=old->fourmiY;
        break;

    case 3: // Cas Ouest
        new->fourmiX=old->fourmiX;
        new->fourmiY=old->fourmiY-1;
        break;
    
    default:
        break;
    }

}

void displayState (ptETAT e)
{
    printf("\e[1;1H\e[2J");
    printf("---------------------\n");
    for (size_t i = 0; i < DIMX; i++)
    {
        //printf("\n");
        for (size_t j = 0; j < DIMY; j++)
        {
            if ((i==e->fourmiX)&&(j==e->fourmiY))
            {
                switch (e->fourmiDirection)
                {
                case 0:
                    printf("^");
                    break;
                case 1:
                    printf(">");
                    break;
                case 2:
                    printf("v");
                    break;
                case 3:
                    printf("<");
                    break;    
                
                default:
                    break;
                }
            }
            else
            {
                if (e->tableau[i][j]==0)
                {
                    printf(" ");
                }
                else
                {
                    printf("X");
                }
                
                
            }
            
            
        }
        
    }  
    printf("\n");
    printf("---------------------");

}