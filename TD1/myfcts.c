#include "myfcts.h"

int min2(int x, int y)
{
    if (x >= y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

void min2_display(int a, int b)
{
    printf("%d \n", min2(a, b));
}

int min4(int c, int d, int e, int f)
{
    int x = min2(c, d);
    int y = min2(e, f);
    return min2(x, y);
}