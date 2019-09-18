#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

void reteimprand() {
  srand(time(NULL));
  int x = rand() % 200;
  printf("-> %d\n", x);
  exit(10);
};


int main () {
  if (fork()){
    int y;
    wait(&y);
    printf("recebi %d\n", WEXITSTATUS(y));
  } else {
    reteimprand();
  };
};