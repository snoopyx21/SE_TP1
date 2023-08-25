#include<unistd.h>
#include<sys/syscall.h>
#include<stdio.h>
 
#define BUFSIZZZ 24
 
int bgetchar(void)
{
    static char buf[BUFSIZZZ];
    static char *bufp;
    static int n = 0;
 
    if (n == 0) /* buffer is empty */
    {
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
 
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
 
int ugetchar(void)
{
    char c;
 
    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
 
 
 
int main()
{
    char c;
    while ((c = ugetchar()) != 'x')
    {
        putchar(c);
    }
 
    while ((c = bgetchar()) != 'x')
    {
        putchar(c);
    }
 
    return 0;
}
