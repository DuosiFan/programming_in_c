# if only static library is available in -L<library path>
a1.out: main.c
	clang -I../ -L../ main.c -o $@ -lfoo
# if both static and shared library and you want to link
# the static one, just include the .a file at the end of
# other objects
a2.out: main.c
	clang -I../ main.c ../libfoo.a -o $@ 

# use a thirdparty library
FFTW3_ROOT := /home/duosifan/tools/fftw3-3.3.10
FFTW3_INC  := $(FFTW3_ROOT)/include
FFTW3_LIB  := $(FFTW3_ROOT)/lib
a3.out: test_3rdparty.c
	clang -I$(FFTW3_INC) test_3rdparty.c $(FFTW3_LIB)/libfftw3.a -o $@ -lm
