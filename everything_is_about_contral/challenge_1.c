#include <stdio.h>
#include <stddef.h>

int sorted(double* a, int n, int flag);

int main(void)
{
  
  return 0;
}

int sorted(double* a, int n, int flag) {
  /* flag
     0:         ascending
     otherwise: descending
   */
  if (!flag) { /* ascending */
    for (size_t i = 1; i < n; ++i)
      if (a[i] < a[i-1]) return 0;
  }
  else { /* descending */
    for (size_t i = 1; i < n; ++i)
      if (a[i] > a[i-1]) return 0;    
  }
  
  return 1;
}

