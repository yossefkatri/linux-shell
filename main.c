#include "utils.h"


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
void executeCommand(char command[],bool isDebug)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        //child proccess
        char** argv = getArgsList(command);
        char* buffer = (char*) malloc((16+strlen(command))*sizeof(char)+1);
        strcat(buffer,"Execute command ");
        strcat(buffer,command);
        printMessage(getpid(),buffer,isDebug);
        free(buffer);
        execvp(argv[0],argv);
        perror("Failed to execute command");
        printf("please see debug mode for more details\n");
        exit(1);
    }
    else if (pid > 0)
    {
        //father proccess
        printMessage(getpid(),"Succesfully started child proccess",isDebug);
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
    bool isDebug = false;
    printf("welcome to my mini shell, terminate send exit");
    printf("\n");
    if (argc > 1 && !strcmp(argv[1],DEBUG_CONST))
    {
        isDebug = true;
    }
    debugPrint("debug mode on",isDebug);
    char input[INPUT_LENGTH]="";
    do
    {
        printf(SHELL_NAME);
        gets(input);
        if(!strcmp(EXIT,input))
        {
            debugPrint("get exit signal",isDebug);
            printMessage(getpid(),"Father proccess is terminated",isDebug);
            return;
        }
        executeCommand(input,isDebug);
    }while(1);
}