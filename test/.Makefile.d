test_heap.o: test_heap.c ../headers/Sort.h ../headers/GetArray.h
test_insertion.o: test_insertion.c ../headers/Sort.h \
 ../headers/GetArray.h
test_merge.o: test_merge.c ../headers/Sort.h ../headers/GetArray.h
test_nth.o: test_nth.c ../headers/Sort.h ../headers/ArrayNew.h
test_quick.o: test_quick.c ../headers/Sort.h ../headers/GetArray.h
ArrayNew.o: ../util/ArrayNew.c ../headers/Sort.h ../headers/ArrayNew.h
GetArray.o: ../util/GetArray.c ../headers/Log.h ../headers/GetArray.h
GetList.o: ../util/GetList.c ../headers/GetList.h
Queue.o: ../util/Queue.c ../headers/Queue.h ../headers/Stack.h
Stack.o: ../util/Stack.c ../headers/Stack.h
HeapSort.o: ../sort/HeapSort.c ../headers/Sort.h
InsertionSort.o: ../sort/InsertionSort.c ../headers/Sort.h
MergeSort.o: ../sort/MergeSort.c ../headers/Sort.h
MergeSort_l.o: ../sort/MergeSort_l.c ../headers/GetList.h
NthElement.o: ../sort/NthElement.c ../headers/Sort.h
QuickSort.o: ../sort/QuickSort.c ../headers/Sort.h
