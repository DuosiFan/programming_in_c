#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* logfile = fopen("mylog.txt", "a");
  if (!logfile) {
    perror("fopen failed");
    return EXIT_FAILURE;
  }

  fputs("feeling good today\n", logfile);
  return EXIT_SUCCESS;
}
