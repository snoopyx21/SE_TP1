#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void raler(char * msg)
{
   perror(msg);
   exit(1);
}

void copie()
{
   int fd1, fd2;
   char c; 
   ssize_t n;

   fd1=open("toto",O_RDONLY); 
   // ouverture du fichier toto
   if (fd1 == -1) raler("open toto");
   fd2=open("titi",O_WRONLY | O_CREAT | O_TRUNC, 0666);
   // ouverture et ecriture dans le fichier titi
   if (fd2 == -1) raler("open titi");
   
   while ( (n=read(fd1, &c, 1)) > 0)
   // verification si la primitive renvoie bien un nombre d'octets lu POSITIF
       if (write(fd2, &c, 1) == -1)
           raler("write");        
   if (n == -1) raler("read");
   if (close(fd1) == -1) raler("close toto");
   if (close(fd2) == -1) raler("close titi");
}

int main()
{
   copie();
   return 0;
}
