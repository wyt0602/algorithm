/**
 * @file Prime.h
 * @Brief  Prime handle
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-07-06
 */

#ifndef PRIME_H_
#define PRIME_H_

#include <memory>
#include "util/BitArray.h"


class Prime{
    public:
	Prime() {result = std::make_shared<vector<int>>();}
	bool isPrime(int number);
	std::shared_ptr<std::vector<int>> getPrime(int to);

    private:
	void buildPrimeArray(int number);
	float betterSqrt(float x)
	{
	    float xhalf = 0.5f*x;
	    int i = *(int*)&x;       // get bits for floating VALUE 
	    i = 0x5f375a86-(i>>1);   // gives initial guess y0
	    x = *(float*)&i;         // convert bits BACK to float
	    x = x*(1.5f-xhalf*x*x);  // Newton step, repeating increases accuracy
	    x = x*(1.5f-xhalf*x*x);  // Newton step, repeating increases accuracy
	    x = x*(1.5f-xhalf*x*x);  // Newton step, repeating increases accuracy

	    return 1/x;
	}

    private:
	std::shared_ptr<std::vector<int>> result;
};

void Prime::buildPrimeArray(int number)
{
    int sqrt = betterSqrt(number) + 1;
    BitArray bit_array(sqrt, true);
    bit_array.set(1, false);

    int pos = bit_array.getFirstNonZero();
    while (pos){
	result->push_back(pos);
	int benchmark = pos;
	while (pos <= sqrt){
	    if (pos%benchmark == 0)
		bit_array.set(pos, false);
	    ++pos;
	}
	pos = bit_array.getFirstNonZero();
    }
}
#endif
