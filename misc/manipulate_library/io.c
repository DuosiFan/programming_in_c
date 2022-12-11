#include <stdio.h>

#include "io.h"

int write_ascii(int *p, int n) {
  if (n < 1) return 1;

  printf("The first element is %d", *p);
  return 0;
}
