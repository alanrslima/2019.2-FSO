#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


void trata_sinal( int sig )
{
  signal( SIGINT, trata_sinal ); // reinstala handler
  printf( "recebi o sinal SIGINT\n" );
};

int main() {
 // instala handler para SIGINT pela primeira vez
//  printf("Meu pID é %d", getpid());
 signal( SIGINT, trata_sinal );
//  while(1)
//   pause();
};