SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	gcc -std=c99 -Wall -Wextra  -g -o $@ $<
clean:s
	rm -f $(PROGS)