/**
 * @file BinarySearch.h
 * @Brief  Binary search template implementation
 * @author wu yangtao , w_y_tao@163.com
 * @version version v1.0
 * @date 2016-06-21
 */

#ifndef IS_IN_H_
#define IS_IN_H_

template <typename T>
bool isIn(T low, T high, typename T::value_type value)
{
    while (low != high){
	auto mid = low + (high - low) / 2;

	if (value == *mid)
	    return true;
	if (value > *mid)
	    low = mid + 1;
	else
	    high = mid; //why not high=mid-1? assure [low, high)
    }

    return false;
}

#endif
