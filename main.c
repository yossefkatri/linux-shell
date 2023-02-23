#include <stdio.h>
#define INPUT_LENGTH 100
#define SHELL_NAME "miniShell>"
#define EXIT "exit"

int strcmp (const char* str1, const char* str2);
char *gets(char *str);
int printf(const char *__restrict__ __format, ...);

void analyzeCode(char* command)
{
    
}

void main(void)
{
    char input[INPUT_LENGTH]="";
    do
    {
        printf(SHELL_NAME);
        gets(input);
        analyzeCode(input);
    }while (strcmp(EXIT,input));
}