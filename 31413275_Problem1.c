#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    // printf() displays the string inside quotation
    int binNum[32];
    
    int n = atoi(argv[1]);
    printf("%d:  ", n);
    int i = 0;
    while (n > 0) {
        binNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    
    
    double tot;
    
    for (int j = 31; j >= 0; j--)
    {
        printf("%d", binNum[j]);
    
        if ( j % 4 == 0 )
            printf(" ");
    }
    
    double l = 31;
    for(int k=0; k<=31 ; k++)
    {
       
        if ( binNum[k] == 1 )
        {
            tot += pow(2.0, l);
        }
        l--;
    }

    
    printf("\n");
    
    printf("%f:  ", tot);
    for(int k = 0; k<32 ; k++)
    {
        
        printf("%d", binNum[k]);
            
        if ( (k+1) % 4 == 0 )
            printf(" ");
    
    }
        
        
    printf("\n");
    
    
    return 0;
}
