#include <stdlib.h>
#include <stdio.h>

/* lower and upper iteration limits centered around 1.0 */
static double const eps1m01 = 1.0 - 0x1P-01;
static double const eps1p01 = 1.0 + 0x1P-01;
static double const eps1m24 = 1.0 - 0x1P-24;
static double const eps1p24 = 1.0 + 0x1P-24;

int main(int argc, char* argv[argc+1])
{
  for (int i = 1; i < argc; ++i) { // process args
    double const a = strtod(argv[i], 0);
    double x = 1.0;
    /* power by 2 */
    for (;;){
      double prod = a*x;
      if (prod < eps1m01) {
	x *= 2.0;
      }
      else if (prod > eps1p01) {
	x *= 0.5;
      }
      else {
	break;
      }
    }

    /* Heron approximation */
    for (;;){
      double prod = a*x;
      if ((prod < eps1m24) || (prod > eps1p24)) {
	x *= (2.0 - prod);
      }
      else {
	break;
      }
    }

    /* print result */
    printf("heron: a=%.5e, \tx=%.5e,\ta*x=%.12f\n", a, x, a*x);
  }
  return 0;
}
