#get the name of the current makefile
MAKEFILENAME:=$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))

#directory for make, use space not : for dividing
VPATH=. ../util ../headers ../sort

#headers for gcc
GCCINC=-I../headers

#lib not standard
LIB_SUFFIX=

#parameter for gcc
CC=gcc
DEBUG=-pg -g
CFLAGS+=-Wall $(GCCINC)
DNAYMIC=-Wl,-rpath=
STATIC=-static

SRC:=$(foreach DIR,$(VPATH),$(wildcard $(DIR)/*.c))
SRC:=$(notdir $(SRC))
OBJS:=$(patsubst %.c,%.o,$(SRC))

#######################user's define start##############################

all:ArrayNew.o HeapSort.o stl.o test.o
	$(CC) -o test $^


#######################user's define end################################

#include dependency file
-include .$(MAKEFILENAME).d

#generate dependency file
GenDependency:$(SRC)
	gcc -MM $^ $(GCCINC) > .$(MAKEFILENAME).d

#clean the current directory
.PHONY:clean
clean:
	-rm *.o test
	make GenDependency -f $(MAKEFILENAME)

#package the source
.PHONY:package
package:
	tar -cvf projectname.tar $(VPATH)

