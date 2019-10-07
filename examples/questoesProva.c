#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  pid_t pB, pC, pD, pE, pF, pG;
  int i, s;

  printf("Sou o processo pA = %d \n ", getpid());
  if ((pB = fork()) == 0){
    printf("Sou o processo pB = %d | Meu pai é %d\n", getpid(), getppid());
  } else {
    if (( pC = fork()) == 0){
      printf("Sou o processo pC = %d | Meu pai é %d\n", getpid(), getppid());
      if ((pE = fork()) == 0) {
        printf("Sou o processo pE = %d | Meu pai é %d\n", getpid(), getppid());
      } else {};
    } else {
      if ((pD = fork()) == 0){
        printf("Sou o processo pD = %d | Meu pai é %d\n", getpid(), getppid());
        if ((pF = fork()) == 0){
          printf("Sou o processo pF = %d | Meu pai é %d\n", getpid(), getppid());
        } else {
          if ((pG = fork()) == 0){
            printf("Sou o processo pG = %d | Meu pai é %d\n", getpid(), getppid());
          } else {};
        }
      } else {};
    };
    scanf("%d", &i);
    exit(0);
  };
};