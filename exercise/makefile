file=exer$(n).c
HEADER=-I../headers
VPATH=. ../headers ../util ../sort
CFLAGS+=-Wall $(HEADER)

all:$(file)
	gcc -Wall -o test $^

list:$(file) GetList.o MergeSort_l.o
	gcc $(CFLAGS) -o test $^

GetList.o: ../util/GetList.c ../headers/GetList.h
MergeSort_l.o: ../sort/MergeSort_l.c ../headers/GetList.h

clean:
	-rm test *.o
