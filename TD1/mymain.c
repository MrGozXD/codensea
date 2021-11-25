#include "myfcts.h"

int main()
{
    int x = 0;
    int a = 9;
    int b = 5;
    int c = 2;
    int y = 20;
    int z = min2(x, y);
    int w = min4(c, a, b, y);
    printf("Le minimum est %d \n", z);
    min2_display(a, y);
    printf("Le minimum est %d \n", w);
    return 0;
}