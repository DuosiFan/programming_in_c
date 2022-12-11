#include <stdio.h>

int sum(int a, int b);

int main(void){
  int a = 5;
  int b = 1;
  printf("Hello, world!\n");
  printf("a + b = %d", sum(a, b));
  return 0;
}

int sum(int a, int b){
  return a + b;
}
