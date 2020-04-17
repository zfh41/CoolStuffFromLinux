#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char** argv, char* envp[])
{
    int index = 1;
    int res;
    char *test;
    char *sort[25];
    
    
    for (int i = 0; i <sizeof(&envp) ; i++)
    {
        printf("envp[i]:     %s\n", envp[i]);
        for ( int j = i + 1; j < sizeof(&envp) ; j++)
        {
            printf("envp[j]:     %s\n", envp[j]);
            res = strcmp(envp[j],envp[i]);
            if (res < 0)
            {
                test = envp[i];
                envp[i] = envp[j];
                envp[j] = test;
            }
        }
    }
    
    
    
    for( int i = 0; i <sizeof(&envp) ; i++)
    {
        printf("%s\n", envp[i]);
        
    }

    return 0;
    
}

    
