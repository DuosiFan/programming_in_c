#include <stdio.h>
#include <stddef.h>

int main(void)
{
  // Declarations
  double A[5] = {
    [0] = 9.0,
    [1] = 2.9,
    [4] = 3.E+25,
    [3] = 0.00007};
  for (size_t i = 0; i < 5; ++i) {
    // equivalent to if (i == 0) but this is a better style
    if (i) {
      printf("element %zu is %g, \tits square is %g\n", i, A[i], A[i]*A[i]);
    }
  }
    
  return 0;
}

