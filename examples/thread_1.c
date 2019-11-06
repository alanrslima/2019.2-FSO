#include <stdio.h>

int x = 0;

void func_a(int v){
  printf("A %d\n", v);
}

void func_c(int v){
  printf("C %d\n", v);
}

void func_b(int v){
  printf("B %d\n", v);
  func_c(v+1);
}

int main (void) {
  CreateThread(func_a(x), func_b(x+1));
  return 0;
}