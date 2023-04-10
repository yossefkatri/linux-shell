#include "libs.h"
#include "consts.h"

void debugPrint(const char* value, bool isDebug)
{
    if(isDebug)
    {
        printf(value);
    }
}
char** getArgsList(char command[])
{
    char** args= (char**)malloc(PARAMS_NUM*sizeof(char*));
    char* token = strtok(command, SEPERATORS);
     int i = 0;
    while (token != NULL)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, SEPERATORS);
    }
    args[i] = NULL;
    return args;
}
void executeCommand(char command[])
{
    pid_t pid = fork();
    if (pid == 0)
    {
        //child proccess
        char** argv = getArgsList(command);
        execvp(argv[0],argv);
        perror("Error");
        exit(1);
    }
    else if (pid > 0)
    {
        //father proccess
        int status;
        pid_t result = wait(&status);
        if (result == -1)
        {
            perror("Error: something wrong with command executing");
        }
    }
    else
    {
        perror("error: can't execute the command");
    }
}
 void main(int argc, char *argv[])
{
    bool isdebug =false;
    if (argc > 1 && !strcmp(argv[1],DEBUG_CONST))
    {
        isdebug = true;
    }
    debugPrint("debug mode on\n",isdebug);
    char input[INPUT_LENGTH]="";
    do
    {
        printf(SHELL_NAME);
        gets(input);
        if(!strcmp(EXIT,input))
        {
            return;
        }
        executeCommand(input);
    }while(1);
}