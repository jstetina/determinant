SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	gcc -std=c99 -Wall -Wextra -o $@ $< -lm 
clean:s
	rm -f $(PROGS)