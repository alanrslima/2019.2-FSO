#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main () {

  fork();
  fork();

  printf("Sistemas Operativos II\n");
  exit (0) ;
}