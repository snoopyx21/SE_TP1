
#include <unistd.h>
#define EOF -1

int my_getchar(void)
{
    unsigned char a;
    int n=read(0,&a,1);
    if (n <= 0) return EOF;
    else return a;
}

int main()
{
    unsigned char c;
    c=getchar();
    write(1,&c,1);
    return 0;
}    
