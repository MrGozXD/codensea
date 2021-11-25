#include "fonctions.h"

void decomposition(int x)
{
    int n = 2;
    while (x != 1)
    {
        if (x % n == 0)
        {
            x = x / n;
            printf("%d \n", n);
        }
        else
        {
            n++;
        }
    }
}

void initTab(TABint, int n)
{
    int i;
    for (i = 0, i < n, i++)
    {
        TABint[i] = 0;
    }
}

int fact(int n)
{
    int facto = 1;
    int i;
    for (i = 1; i <= n; i++)
        facto *= i;
    return facto;
}

int isPrime(int x)
{
    int z = fact(x - 1) + 1;
    if (z % x == 0)
    {
        return 1;
    }
    else
        return 0;
}
