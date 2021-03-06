TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/include
LDFLAGS=-lmystring -lmyutils -lbitmask
LIBPATH=${PWD}

all:activty.out

sall.out:test.o libmystring.a libmyutils.a libbitmask.a
	gcc -L${LIBPATH} $< -o $@ ${LDFLAGS} 
libmystring.a:src/mystring.o 
	ar rc $@ $^
libmyutils.a:src/myutils.o 
	ar rc $@ $^
libbitmask.a:src/bitmask.o 
	ar rc $@ $^
%.o:src/%.c include/%.h

test.o: test.c include/*.h

test:
	./activty.out

clean:
	rm -rf *.a *.o src/*.o ${TARGET}
