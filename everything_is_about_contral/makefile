CC := clang
CFLAGS := -std=c17 -Wall -Werror -g

srcs := $(wildcard *.c)
targets := $(srcs:%.c=%.out)

all: $(targets)

%.out: %.c
	$(CC) $(CFLAGS) $< -o $@
