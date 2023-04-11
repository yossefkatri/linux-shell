#include "libs.h"
#include "consts.h"

void debugPrint(const char* value, bool isDebug)
{
    if(isDebug)
    {
        printf(value);
        printf("\n");
    }
}
char* tostring(int num)
{
    int i, rem, len = 0, n;
 
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    char* str =(char*)malloc(len*sizeof(char)+1);
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    return str;
}
void printMessage(pid_t pid, const char* msg,bool isDebug)
{
            char* pidStr;
            size_t size = strlen(msg)+6;
            pidStr = tostring(pid);         
            char* final = (char*)malloc(size*sizeof(char)+sizeof(pid_t)+1);
            strcat(final,"PID[");
            strcat(final,pidStr);
            free(pidStr);
            strcat(final,"] ");
            strcat(final,msg);
            debugPrint(final, isDebug);
            free(final);
}