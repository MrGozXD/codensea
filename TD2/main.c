#include "fonctions.h"

int main(void)
{
    decomposition(15);
    int TABint[DIM];
    int i = 2;
    int n = 0;
    while (n < 100)
    {
        if (isPrime(i))
        {
            TABint[n] = i;
            n++;
        }
        i++;
    }
    printf("Test %d \n", TABint[5]);
    return 0;
}