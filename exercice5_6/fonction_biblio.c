// fonction de bibliotheque getchar/putchar

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char c;
    while( (c=getchar()) != EOF )
    {
        putchar(c);
    }
   
    exit (0);
}
