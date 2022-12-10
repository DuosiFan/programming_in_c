## Compilation process in C
#
# reference:
# (https://passlab.github.io/ITSC3181/notes/lecture02
#  _CompilationAssemblingLinkingProgramExecution.pdf)

NAME := hello_world

# linking
# generate executable file
# bind appropriate either static or dynamic(a.k.a. shared)
# libraries. If both available, most linkers prefer to
# dynamic library
$(NAME).app: $(NAME).o
	@echo Checking the path of linker
	clang --print-prog-name=ld
	clang $(NAME).o -o $(NAME).app

# assembling
# generate relocatable object file (.o binary)
$(NAME).o: $(NAME).s
	clang -c $< -o $@

# compilation
# generate assembly language (.s)
# verify function usage with provided prototypes
$(NAME).s: $(NAME).i
	clang -S $< -o $@

# preprocessing
# create .i file
# expand header files(#include...)
# substitute macros(#define...) and inline functions
$(NAME).i: $(NAME).c
	clang -E $< -o $@

# remarks:
# 1. For the general information of symbols (function in most time)
#    use nm command (useful for inspecting static library funcs)
#
#    nm hello_world.app
#---------------------------------------------------------------------
#    ...
#    0000000000001140 T main                  <-- main function
#                     U printf@GLIBC_2.2.5    <-- library function
#    00000000000010b0 t register_tm_clones
#    0000000000001050 T _start
#    0000000000001190 T sum                   <-- local function
#    0000000000004030 D __TMC_END__
#    ...
#---------------------------------------------------------------------
# 2. The ldd utility can display shared libraries required by
#    an executable
#
#    ldd hello_world.app
#---------------------------------------------------------------------
#    linux-vdso.so.1 (0x00007ffecc922000)
#    libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f6b5f622000)
#    /lib64/ld-linux-x86-64.so.2 (0x00007f6b5f85f000)
#---------------------------------------------------------------------
#
#    other tools may also be useful such as readelf and objdump
# 3. For shared library, we can check the search history of a dynamic
#    library (.so) by
#
#    LD_DEBUG=libs ./hello_world.app
#
#---------------------------------------------------------------------
#      4143:	find library=libc.so.6 [0]; searching
#      4143:	 search cache=/etc/ld.so.cache
#      4143:	  trying file=/lib/x86_64-linux-gnu/libc.so.6
#      4143:	
#      4143:	
#      4143:	calling init: /lib64/ld-linux-x86-64.so.2
#      4143:	
#      4143:	
#      4143:	calling init: /lib/x86_64-linux-gnu/libc.so.6
#      4143:	
#      4143:	
#      4143:	initialize program: ./hello_world.app
#      4143:	
#      4143:	
#      4143:	transferring control: ./hello_world.app
#      4143:	
#      4143:	
#      4143:	calling fini: ./hello_world.app [0]
#      4143:
#----------------------------------------------------------------------


# if we pass -save-temps option, all intermediate files will be saved
all_in_one.app: hello_world.c
	clang $< -o $@
