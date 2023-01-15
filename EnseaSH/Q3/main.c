#include "headerEnseaSh.h"

int main(int argc, char const *argv[])
{
    char *command;
    dispMessage(WELCOME_MSG);
    while (1)
    {
        command = readUserInput();
        if (command != NULL)
        {
            executeCommand(command);
        }
    }
    return 0;
}
