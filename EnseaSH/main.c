#include "headerEnseaSH.h"

int main(int argc, char const *argv[])
{
    char *command;
    // TODO : define en const les messages
    dispMessage(WELCOME_MSG); 
    while(1){
        command = readCommand();
        if (command != NULL)
        {
            // TODO : execute command
        }
    }
    dispMessage(QUIT_MSG); 
    return 0;
}

