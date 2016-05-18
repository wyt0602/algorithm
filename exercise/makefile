file=exer$(n).c
index=-$(n)-

file_list=-8- -9- -10- -11- -12-
flag_list=$(findstring $(index),$(file_list))

file_stack=-13-
flag_stack=$(findstring $(index),$(file_stack))

choice=
ifneq ($(flag_list),)
	choice=list
endif

ifneq ($(flag_stack),)
	choice=stack
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

stack:$(file) GetList.o Stack.o MergeSort_l.o
	gcc $(CFLAGS) -o test $^

GetList.o: ../util/GetList.c ../headers/GetList.h
MergeSort_l.o: ../sort/MergeSort_l.c ../headers/GetList.h
Stack.o: ../util/Stack.c ../headers/Stack.h ../headers/Log.h

clean:
	-rm test *.o
