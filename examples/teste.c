#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (){ 

  pid_t  pid;
  for (int i=0; i<4; i++){
    pid = fork();
  };
  printf("FSO\n");
  return 0;
}