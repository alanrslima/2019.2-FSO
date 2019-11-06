#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

#define TAM_MAX 2000

int main() {

  FILE *file;
  int c;
  file = fopen("input.txt", "r");

  if (file) {
    while(( c = getc(file)) != EOF){
      putchar(c);
    }
    fclose(file);
  }

  return 0;
}

