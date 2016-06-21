file=exer$(n).c
index=-$(n)-

file_list=-8- -9- -10- -11- -12- -14-
flag_list=$(findstring $(index),$(file_list))

file_stack=-13- -16- -17-
flag_stack=$(findstring $(index),$(file_stack))

file_array=
flag_array=$(findstring $(index),$(file_array))

choice=
ifneq ($(flag_list),)
	choice=list
endif

ifneq ($(flag_stack),)
	choice=stack
endif

ifneq ($(flag_array),)
	choice=array
endif

HEADER=-I../headers
VPATH=. ../headers ../util ../sort
CFLAGS+=-Wall $(HEADER)

all:
ifeq ($(choice),)
	gcc -Wall -o test $(file)
else
	@make $(choice)
endif

list:$(file) GetList.o MergeSort_l.o
	gcc $(CFLAGS) -o test $^

stack:$(file) GetList.o Stack.o MergeSort_l.o Queue.o
	gcc $(CFLAGS) -o test $^

array:$(file) AraayNew.o HeapSort.o 
	gcc $(CFLAGS) -o test $^

GetList.o: ../util/GetList.c ../headers/GetList.h
MergeSort_l.o: ../sort/MergeSort_l.c ../headers/GetList.h
Stack.o: ../util/Stack.c ../headers/Stack.h ../headers/Log.h
Queue.o: ../util/Queue.c ../headers/Queue.h ../headers/Stack.h
ArrayNew.o: ArrayNew.c ../headers/Sort.h ../headers/ArrayNew.h
HeapSort.o: HeapSort.c ../headers/Sort.h

clean:
	-rm test *.o
