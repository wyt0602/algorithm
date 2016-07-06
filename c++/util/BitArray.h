/**
 * @file BitArray.h
 * @Brief  Bit array implementation
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-06-17
 */
#ifndef BIT_ARRAY_H_
#define BIT_ARRAY_H_

#include <string.h>

class BitArray
{
    public:
	BitArray(int bit_size, bool value = false);
	~BitArray() { delete [] start;}

	int get(int position);
	int getFirstNonZero();//return, 0 is no one; other is the position
	bool set(int position, bool value);
	bool fill(int from, int to, bool value);
	void clear() { memset(start, 0, size);}
	void setAll(bool value) 
	{
	    if (value)
		memset(start, 0xff, size);
	    else
		clear();
	}

    private:
	char *start;
	int end;
	int size;  //byte number
};

BitArray::BitArray(int bit_size, bool value)
{
    if (bit_size%8 == 0)
	size = bit_size / 8;
    else
	size = bit_size / 8 + 1;

    start = new char[size];
    end = bit_size;
    setAll(value);
}

/* --------------------------------------------------------------------------*/
/**
 * @Brief  get Get the value by position
 *
 * @Param position The given position
 *
 * @Returns   -1 is error; other means value in the given position
 */
/* ----------------------------------------------------------------------------*/
inline int BitArray::get(int position)
{
    if (position <= 0 || position > end)
	return -1;

    int byte_index = (position - 1) / 8;
    int bit_index = (position - 1) % 8;

    return (start[byte_index] >> bit_index) & 0x1;
}

int BitArray::getFirstNonZero()
{
    unsigned int *p = (unsigned int*)start;
    int index = 0;
    int count = size / 4;

    //check by four bytes
    while (count){
	if (*p)
	    break;
	++p;
	index += 4;
	--count;
    }

    if (index == size)
	return 0;

    char *start_pos = start + index; //means the start position of next four bytes
    int i = 0;
    //check by byte;
    //two sitituation:
    //(1)four bytes remained
    //(2)less than four bytes remained  : -> index+1 == size
    while (i < 3){
	if (index+1 == size || *start_pos) //index+1 means from start to current position
	    break;
	++i;
	++start_pos;
	++index;
    }

    //check by bit
    char goal = *(start + index);
    for (i = 0; i < 8; ++i){
	if ((goal >> i) & 0x1)
	    break;
	if (index*8+i+1 == end || i == 8)
	    return 0;
    }

    return index*8+i+1;
}


inline bool BitArray::set(int position, bool value)
{
    if (position <= 0 || position > end)
	return false;

    int byte_index = (position - 1) / 8;
    int bit_index = (position - 1) % 8;

    if (value)
	start[byte_index] = start[byte_index] | (0x1 << bit_index);
    else
	start[byte_index] = start[byte_index] & (~(0x1 << bit_index));

    return true;
}

bool BitArray::fill(int from, int to, bool value)
{
    if ((from && to) <= 0 || from > to || to > end)
	return false;

    //situation 1, no complete byte
    int byte_index = (from - 1) / 8;
    int bit_index = (from - 1) % 8;
    if (bit_index != 0 && (to-1)/8 > byte_index){
	if (value)
	    start[byte_index] = start[byte_index] | (~((0x1<<bit_index) - 1));
	else
	    start[byte_index] = start[byte_index] & ((0x1<<bit_index) - 1);
	from = from + (8 - (from-1)%8); //change to next byte
    } else if (bit_index != 0){
	while (from <= to){
	    set(from, value);
	    ++from;
	}
	return true;
    }


    //situation 2
    while ((from + 7) <= to){ // test if there is still one byte needs to fill
	if (value)
	    start[(from-1)/8] = 0xff;
	else
	    start[(from-1)/8] = 0;

	from = from + 8; //change to next byte
    }

    //situation 3
    if (to%8 != 0){
	if (value)
	    start[(to-1)/8] = start[(to-1)/8] | ((0x1<<to%8) - 1);
	else
	    start[(to-1)/8] = start[(to-1)/8] & (~((0x1<<to%8) - 1));
    }

    return true;
}

#endif
