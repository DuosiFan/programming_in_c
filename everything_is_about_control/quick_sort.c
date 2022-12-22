#include <stdio.h>
#include <stddef.h>

int is_sorted(int* a, size_t n);
size_t partition(int* a, size_t l, size_t h);
void swap(int* a, int* b);

int main(void) {

  return 0;
}

/* check if array a is sorted (ascending)
   Empty array or single element is defined as sorted */
int is_sorted(int* a, size_t n) {
  if (n <= 1) { return 1; }
  
  for (size_t i = 1; i < n; ++i) {
    if (a[i] < a[i-1]) { return 0; }
  }
    
  return 1;
}

size_t partition(int* a, size_t l, size_t h) {
  return 0;
}

void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
