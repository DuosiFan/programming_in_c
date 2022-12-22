#include <stdio.h>
#include <stddef.h>

int is_sorted(int* a, size_t n);
void merge(int* a, size_t l, size_t r, size_t m);
void merge_sort(int* a, size_t l, size_t r);

int main(void)
{
  FILE* log = fopen("log.chanllenge_1", "w");
  fprintf(log, "Start logging\n\n");
  
  fprintf(log, "Testing empty list\n");
  int* a00 = NULL;
  merge_sort(a00, 0, 0);
  if (is_sorted(a00, 0)) {
    fprintf(log, "PASSED\n\n");
  }
  else {
    fprintf(log, "FAILED\n\n");
  }

  fprintf(log, "Testing one element\n");
  fprintf(log, "a = [1]\n");
  int a01[] = {1};
  merge_sort(a01, 0, 0);
  if (is_sorted(a01, 0)) {
    fprintf(log, "PASSED\n\n");
  }
  else {
    fprintf(log, "FAILED\n\n");
  }

  fprintf(log, "Testing small array\n");
  fprintf(log, "a = [38, 27, 43, 3, 9, 82, 10]\n");
  int a02[] = {38, 27, 43, 3, 9, 82, 10};
  merge_sort(a02, 0, 6);
  if (is_sorted(a02, 0)) {
    fprintf(log, "PASSED\n\n");
  }
  else {
    fprintf(log, "FAILED\n\n");
  }  
  
  fprintf(log, "End logging and close file.\n\n");
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

/* merge two sorted array a[l...m] and a[m+1,...,r] into one sorted
   array a[l...r] (index inclusive)
   
   Assumptions:
   1. l <= m < r
   2. no out of bounds

*/
void merge(int* a, size_t l, size_t r, size_t m) {
  size_t nl = m - l + 1;
  size_t nr = r - m;

  /* copy to temp array */
  int left[nl];
  int right[nr];
  for (size_t i = 0; i < nl; ++i) { left[i] = a[l+i]; }
  for (size_t i = 0; i < nr; ++i) { right[i] = a[m+1+i]; }

  /* compare common part */
  size_t i = 0;
  size_t j = 0;
  size_t k = l;
  while ((i < nl) && (j < nr)) {
    if (left[i] < right[j]) {
      a[k++] = left[i++];
    }
    else {
      a[k++] = right[j++];
    }
  }

  /* copy remaining elements */
  while (i < nl) {
    a[k++] = left[i++];
  }
  while (j < nr) {
    a[k++] = right[j++];
  }
}

/* merge sort a[l...r] (inclusive) */
void merge_sort(int* a, size_t l, size_t r) {
  if (l < r) {
    size_t m = l + ((r - l) >> 1);
    merge_sort(a, l,   m);
    merge_sort(a, m+1, r);
    merge(a, l, r, m);
  }
}
