#include "headerEnseaSH.h"

int main(int argc, char const *argv[])
{
    char *command;
    // TODO : define en const les messages
    dispMessage("Welcome to ENSEA Tiny Shell. \nTo quit, type 'exit'. \n"); 
    while(1){
        command = readCommand();
        if (command != NULL)
        {
            // TODO : execute command
        }
    }
    dispMessage("Bye bye !\n"); 
    return 0;
}

