# if only static library is available in -L<library path>
a1.out: main.c
	clang -I../ -L../ main.c -o $@ -lfoo
# if both static and shared library is available
a2.out: main.c
	clang -I../ main.c ../libfoo.a  -o $@ 
