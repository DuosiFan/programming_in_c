#include <stdio.h>
#include <stdlib.h>

#include "../foo.h"

int main(void) {
  int a = 5;
  printf("a = %d\n", bar(a));

  int *b = NULL;
  b = malloc(5*sizeof(*b));
  for (int i = 0; i < 5; ++i) b[i] = i;
  return 0;
}
