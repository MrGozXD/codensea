#include "structures.h"

int main(int argc, char const *argv[])
{
    NINJA nin1;
    strcopy(nin1.nom, "Rock Lee");
    nin1.chakra = 500;

    //
    NINJA nin2 = {"Sasuke", 1500};

    return 0;
}
