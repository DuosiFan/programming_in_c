#include <stdio.h>
#include <stddef.h>

int is_sorted(double* a, size_t n);
void print_array(double* a, size_t n, FILE* stream);

int main(void)
{
  FILE* log = fopen("log.test_sorted", "a");
  fprintf(log, "Start logging\n\n");

  size_t n = 0;
  double data01[] = {1.0, 2.0, 3.0, 4.0};
  n = sizeof(data01)/sizeof(*data01);
  
  fprintf(log, "Testing is_sorted function\n");
  if (is_sorted(data01, n)) {
    print_array(data01, n, log);
    fprintf(log, "is_sorted pass\n");
  }
  else {
    fprintf(log, "is_sorted fail\n");
  }

  double data02[] = {3.0, 3.0, 3.0};
  n = sizeof(data02)/sizeof(*data02);
  if (is_sorted(data02, n)) {
    print_array(data02, n, log);
    fprintf(log, "is_sorted pass\n");
  }
  else {
    fprintf(log, "is_sorted fail\n");
  }

  double data03[] = {3.0, 2.0, 3.0};
  n = sizeof(data03)/sizeof(*data03);
  if (!is_sorted(data03, n)) {
    print_array(data03, n, log);
    fprintf(log, "is_sorted pass\n");
  }
  else {
    fprintf(log, "is_sorted fail\n");
  }

  
  fprintf(log, "End logging and close file.\n\n");
  return 0;
}

/* check if array a is sorted (ascending) */
int is_sorted(double* a, size_t n) {
  if (n == 1) { return 1; }
  
  for (size_t i = 1; i < n; ++i) {
    if (a[i] < a[i-1]) { return 0; }
  }
    
  return 1;
}

/* print an array for logging */
void print_array(double* a, size_t n, FILE* stream) {
  fprintf(stream, "array of length %zu\n", n);
  for (size_t i = 0; i < n; ++i) {
    fprintf(stream, "%15.7f", a[i]);
  }
  fprintf(stream, "\n");
}
