#include "fftw3.h"
#define N 8

int main(void) {
  fftw_complex *in, *out;
  fftw_plan p;

  in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
  out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

  for (int i = 0; i < N; ++i){
    in[i][0] = 1.0;
    in[i][1] = 0.0;
  }

  fftw_execute(p);

  fftw_destroy_plan(p);
  fftw_free(in);
  fftw_free(out);
  
  return 0;
}
