#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{ 
  int r, pid, s;
  r = fork();
  if (r < 0){
    fprintf(stderr, "Fork failed\n");
    exit(-1);
  } else if (r == 0){
    printf("Sou o filho com PID: %d, meu pai tem PID: %d\n", getpid(), getppid());
  } else {
    printf("Sou o processo pai com PID: %d, criei um filho com PID: %d\n", getpid(), r);
    pid = wait(&s);
    printf("Meu filho com pid %d terminou com status %d\n", pid, s);
    exit(0);
  }
};