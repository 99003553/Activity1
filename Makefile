TARGET=activity.out
OBJS=test.o src/mystring.o src/myutils.o src/bitmask.o
TOPDIR=${PWD}

run:
	gcc 
clean:
	rm -rf ${OBJS} ${TARGET}
