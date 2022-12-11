#include <stdio.h>

#include "../foo.h"

int main(void) {
  int a = 5;
  printf("a = %d\n", bar(a));
  return 0;
}
