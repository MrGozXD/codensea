#include "langton.h"

int main(void)
{
    int count = 5; //à mettre en scanf
    ptETAT Fourmi=createNewState(0,0,0);
    //ptETAT OldFourmi=Fourmi;
    

    for (size_t i = 0; i < count; i++)
    {
        createNextState(Fourmi);
        displayState(Fourmi);
    }
    
    return 0;
}
