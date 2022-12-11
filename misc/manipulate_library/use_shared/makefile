# In this way, the executable can be linked successfully.
# However, the system cannot find the library when we
# try to run it
#
#----------------------------------------------------------
# ./a1.out
#----------------------------------------------------------
# ./a1.out: error while loading shared libraries: libfoo.so:
# cannot open shared object file: No such file or directory
#----------------------------------------------------------
a1.out: main.c
	clang -I../ -L../ main.c -lfoo -o $@


# We have several options now.
# 1. Run the executable with LD_LIBRARY_PATH=<library path>
# environment library.
#
# LD_LIBRARY_PATH=../ ./a1.out
#
# However, we can also hardcode the path of library
a2.out: main.c
	clang -I../ -L../ -Wl,-rpath,../ main.c -lfoo -o $@
# we can see something here
#
# ldd a2.out
#	linux-vdso.so.1 (0x00007ffe2f7ea000)
#	libfoo.so => ../libfoo.so (0x00007ff8c1714000)
#	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007ff8c14dd000)
#	/lib64/ld-linux-x86-64.so.2 (0x00007ff8c1720000)
#
# we need to see the relative path for libfoo.so. If you copy a2.out to
# somewhere else, the loader cannot work. Therefore, I prefer to absolute
# path here.

LIBSPATH := /home/duosifan/Desktop/programming_in_c/misc/manipulate_library
a3.out: main.c
	clang -I../ -L../ -Wl,-rpath,$(LIBSPATH) main.c -lfoo -o $@

# Another problem is when two copies of a library is installed. A typical
# situation is that a library is installed as some dependency as a system
# package. However, you download a copy and build it by yourself. We need
# to know which library is loaded.

# use a thirdparty library
FFTW3_ROOT := /home/duosifan/tools/fftw3-3.3.10
FFTW3_INC  := $(FFTW3_ROOT)/include
FFTW3_LIB  := $(FFTW3_ROOT)/lib

a4.out: test_3rdparty.c
	clang -I$(FFTW3_INC) -L$(FFTW3_LIB) test_3rdparty.c -lfftw3 -lm -o $@

# use the default method above
#
# ldd a4.out
#	linux-vdso.so.1 (0x00007fff6b9de000)
#	libfftw3.so.3 => /lib/x86_64-linux-gnu/libfftw3.so.3 (0x00007f510ae17000)
#	libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f510ad30000)
#	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f510ab08000)
#	/lib64/ld-linux-x86-64.so.2 (0x00007f510b048000)
#
# we can see that it is using the system installed fftw3

a5.out: test_3rdparty.c
	clang -I$(FFTW3_INC) -L$(FFTW3_LIB) -Wl,-rpath,$(FFTW3_LIB) test_3rdparty.c -lfftw3 -lm -o $@
#
# ldd a5.out
# 	linux-vdso.so.1 (0x00007ffe425de000)
#	libfftw3.so.3 => /home/duosifan/tools/fftw3-3.3.10/lib/libfftw3.so.3 (0x00007f7475e5a000)
#	libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f7475d64000)
#	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f7475b3c000)
#	/lib64/ld-linux-x86-64.so.2 (0x00007f7475f7a000)

a6.out: test_mixed.c
	clang -I$(FFTW3_INC) -I../ -L$(FFTW3_LIB) -L$(LIBSPATH) -Wl,-rpath,$(FFTW3_LIB),-rpath,$(LIBSPATH) test_mixed.c -lfoo -lfftw3 -lm -o $@

#
# ldd a6.out
#	linux-vdso.so.1 (0x00007ffe22994000)
#	libfoo.so => /home/duosifan/Desktop/programming_in_c/misc/manipulate_library/libfoo.so (0x00007fd66a75e000)
#	libfftw3.so.3 => /home/duosifan/tools/fftw3-3.3.10/lib/libfftw3.so.3 (0x00007fd66a645000)
#	libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fd66a54f000)
#	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fd66a327000)
#	/lib64/ld-linux-x86-64.so.2 (0x00007fd66a76a000)




