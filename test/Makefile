#get the name of the current makefile
MAKEFILENAME:=$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))

#directory for make, use space not : for dividing
VPATH=. ../headers ../util ../sort

#headers for gcc
GCCINC=-I../headers

#lib not standard
LIB_SUFFIX=

#parameter for gcc
CC=gcc
DEBUG=-pg -g
CFLAGS+=-Wall $(GCCINC) -g
DNAYMIC=-Wl,-rpath=
STATIC=-static

SRC:=$(foreach DIR,$(VPATH),$(wildcard $(DIR)/*.c))
SRC:=$(notdir $(SRC))
OBJS:=$(patsubst %.c,%.o,$(SRC))

#######################user's define start##############################

all:HeapSort QuickSort

HeapSort:HeapSort.o test_heap.o GetArray.o
	$(CC) $(CFLAGS) -o heap_test $^

QuickSort:QuickSort.o test_quick.o GetArray.o
	$(CC) $(CFLAGS) -o quick_test $^

MergeSort:MergeSort.o test_merge.o GetArray.o
	$(CC) $(CFLAGS) -o merge_test $^

InsertionSort:InsertionSort.o test_insertion.o GetArray.o
	$(CC) $(CFLAGS) -o insertion_test $^

NthElement:NthElement.o InsertionSort.o test_nth.o ArrayNew.o HeapSort.o
	$(CC) $(CFLAGS) -o nth_test $^

#######################user's define end################################

#include dependency file
-include .$(MAKEFILENAME).d

#generate dependency file
GenDependency:$(SRC)
	gcc -MM $^ $(GCCINC) > .$(MAKEFILENAME).d

#clean the current directory
.PHONY:clean
clean:
	-rm *.o *_test *.txt core *.out
	make GenDependency -f $(MAKEFILENAME)

#package the source
.PHONY:package
package:
	tar -cvf projectname.tar $(VPATH)

