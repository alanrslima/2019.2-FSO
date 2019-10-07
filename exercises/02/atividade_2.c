#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#define TAM_MAX 2000

int matriz_a[TAM_MAX][TAM_MAX];
int matriz_b[TAM_MAX][TAM_MAX];
int matriz_response[TAM_MAX][TAM_MAX];
int n;
int f1 = 0, f2 = 0;

void filho_1();
void filho_2();


int main() {

  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &matriz_a[i][j]);
    }
  }

  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &matriz_b[i][j]);
    } 
  }

  signal(SIGUSR1, filho_1 );
  signal(SIGUSR2, filho_2 );

  pid_t p1, p2;

  if ((p1 = fork()) == 0) {
    signal(SIGCHLD, filho_1 );
    for(int i = 0; i < n/2; ++i) {
      for(int j = 0; j < n; ++j) {
        matriz_response[i][j] = 0;
        for(int k = 0; k < n; ++k) {
          matriz_response[i][j] += matriz_a[i][k] * matriz_b[k][j];
        }         
      }
    }
    kill(getppid(), SIGUSR1);
    pause();
    for(int i = 0; i < n/2; ++i) {
      printf("%d", matriz_response[i][0]);
      for(int j = 1; j < n; ++j) {
        printf(" %d", matriz_response[i][j]);     
      }
      printf("\n");
    }
    exit(0);
  } else {
    if ((p2 = fork()) == 0) {
      signal(SIGCHLD, filho_2 );
      for(int i = n/2; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
          matriz_response[i][j] = 0;
          for(int k = 0; k < n; ++k) {
            matriz_response[i][j] += matriz_a[i][k] * matriz_b[k][j];
          }         
        }
      }
      kill(getppid(), SIGUSR2);
      pause();
      for(int i = n/2; i < n; i++){
        printf("%d", matriz_response[i][0]);
        for(int j = 1; j < n; j ++){
          printf(" %d", matriz_response[i][j]);
        }
        printf("\n");
      }
      exit(0);
    } else {
      // Processo PAI
      pause();
      while((f1 == 0) || (f2 == 0)){
        pause();
      }
      int l;
      kill(p1, SIGCHLD);
      wait(&l);
      kill(p2, SIGCHLD);
      wait(&l);
    }
  }
  return 0;
}

void filho_1() {
  f1++;
}

void filho_2() {
  f2++;
}
