# example usage of ar
#
# 1. ar t libfoo.a: print a list of *.o in an archive
# 2. ar rcs libfoo.a *.o: create library with all objects

# If you just want to create a small library and use in
# applications, PIC is not necessary. However, if you need
# to collaborate with lots of shared libraries, use -fPIC
libfoo.a: foo.c
	clang -c foo.c -o foo.o
	ar cr libfoo.a foo.o
