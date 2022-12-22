#include <stdio.h>

int main(void)
{
  char arg = 'm';

  switch (arg) {
  case 'm':
    puts("this is a magie");
    break;
  case 'r':
    puts("this is a raven");
    break;
  case 'j':
    puts("this is a jay");
    break;
  default:
    puts("this is an unknown corvid");
  }
  return 0;
}

