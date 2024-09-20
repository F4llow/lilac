# lilac/Makefile

CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -fPIC
ARFLAGS = rcs
LIB_NAME = liblilac.a

all: $(LIB_NAME)

$(LIB_NAME): lilac.o
	$(AR) $(ARFLAGS) $@ $^

lilac.o: lilac.c lilac.h
	$(CC) $(CFLAGS) -c lilac.c

clean:
	rm -f *.o $(LIB_NAME)

