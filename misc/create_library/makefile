## Tips for create static libraries
#
# 1. If the create archive may be refered by thirdparty shared library, compile
# all objects (.o) with -fPIC flag. Otherwise, -fPIC is not necessary
# 2. Regular rule to create a library
#
# 	ar cr libfoo.a *.o
# 3. To show contents of libfoo.a
#
#	ar t libfoo.a
libfoo.a: foo.c
	clang -c foo.c -o foo.o
	ar cr libfoo.a foo.o
