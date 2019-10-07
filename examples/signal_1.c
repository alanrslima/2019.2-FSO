#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <signal.h>

void beep(int x) {
  printf("beep\n");
};

int main () {

  printf("%d\n", getpid());
  signal(SIGUSR1, beep);
  while(1)
    pause();
  return (0);
};