// fonction primitive systeme read/write

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 
#define MAX_BUF 2056 


static char buf[MAX_BUF];
static int n;

int getchar_b(int taille)
{
    
    n = read(0,buf,taille);
    if ( n>0 )
        return n;
    else 
        return EOF;
}


int main(int argc,char *argv[])
{
    if (argc < 2)
        return 1; 
    int taille=atoi(argv[1]);
    do
    {
       n=getchar_b(taille);
       write(1,buf,n);
    }
    while( n==taille );
    return 0;
}

