#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() { 
  int r, pid, s;
    r = fork(); // fork() another process
    if (r < 0) { // error occurred
      fprintf(stderr, "Fork Failed\n");
      exit(-1);
    }
    else if (r == 0) { // child process
      printf("sou o filho com PID: %d, meu pai tem PID: %d\n", getpid(), getppid() );
      for (int i=0; i<5; i++){
        printf("Executando filho %d\n", i);
        sleep(1);
      };
      // inserir qq código aqui ... inclusive exec
    }
    else { // processo pai
      printf("sou o pai com PID: %d\n", getpid() );
      printf("criei um filho com PID: %d\n", r);

      // inserir qq codigo aqui ...
      // agora vou esperar meu filho terminar
      pid = wait( &s );
      printf( "meu filho com pid %d terminou com status %d\n", pid, s );
      exit(0);
  };
};