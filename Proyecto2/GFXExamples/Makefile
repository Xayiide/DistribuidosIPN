.PHONY = clean
CC     = gcc
CFLAGS = -Wall -Wextra -pedantic -g -lX11 -lm # link X11 and Math libs

# $@ is the target for the rule
# $^ is the full list of prerequisites

# example: gfx.o
# 	$(CC) $(CFLAGS) -o example gfx.o

example: example.c gfx.o
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Removing object files"
	@rm gfx.o

clean: 
	@echo "Cleaning up..."
	@rm example
