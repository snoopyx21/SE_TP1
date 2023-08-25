#include <stdio.h>
#include <unistd.h>
#define BUFSIZE 50

int bufer_getchar(void){
   static char tampon[BUFSIZE];
   static char * tamp = tampon;
   static int n = 0;

   if (!n) {
       n = read (0, tampon, BUFSIZE);
       tamp = tampon;
   }
   return (--n >= 0) ?(int)*tamp++:EOF;
}

int main(){
   buf_getchar();  
}
