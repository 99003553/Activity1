TARGET=activty.out
OBJS=test.o src/mystring.o  src/bitmask.o src/myutils.o

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/inc
LDFLAGS=-lmystring -lmyutils -lbitmask
LIBPATH=${PWD}

all:activty.out

sall.out:test.o libmystring.a libmyutils.a libbitmask.a
	gcc -L${LIBPATH} $< -o $@ ${LDFLAGS} -static
libmystring.a:src/mystring.o 
	ar rc $@ $^
libmyutils.a:src/myutils.o 
	ar rc $@ $^
libbitmask.a:src/bitmask.o 
	ar rc $@ $^
%.o:src/%.c inc/%.h

test.o: test.c inc/*.h

test:
	./activty.out
