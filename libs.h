#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h> 
#include <unistd.h>  
#include <sys/wait.h> 
#include <string.h>


int strcmp (const char* str1, const char* str2);
char *gets(char *str);
int printf(const char *__restrict__ __format, ...);
char * strtok(char str[], const char *delims);
char * strcat(char *destination, const char *source);