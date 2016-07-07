/**
 * @file BinarySearch.cc
 * @Brief  Binary search implementation
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-06-21
 */

#include <iostream>
#include <vector>
#include <deque>

#include "util/BinarySearch.h"

bool isIn2(std::vector<int>::const_iterator low, std::vector<int>::const_iterator high, int value)
{

    while (low != high){
	std::vector<int>::const_iterator mid = low + (high - low) / 2;

	if (value == *mid)
	    return true;
	if (value > *mid)
	    low = mid + 1;
	else
	    high = mid; //why? assure [low, high)
    }

    return false;
}

int main()
{
    //int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<float> a = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

    int i = 0;
    while (i < 20){
	if (isIn(a.cbegin(), a.cend(), i*0.1))
	    std::cout << i*0.1 << " is in a!" << std::endl;
	else
	    std::cout << i*0.1 << " is not in a!" << std::endl;
	++i;
    }

    return 0;

}
