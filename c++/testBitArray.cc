
#include <iostream>
#include "util/BitArray.h"

int main()
{
    BitArray bit_set = BitArray(100);
    bit_set.fill(34, 37, true);
    bit_set.set(11, true);
    bit_set.set(42, true);
    bit_set.set(66, true);
    bit_set.set(75, true);
    bit_set.set(87, true);
    bit_set.set(95, true);
    bit_set.set(100, true);

   // bit_set.setAll(true);
    int value = bit_set.getFirstNonZero();
    std::cout << "firstNonZero=" << value << std::endl;
    bit_set.set(value, false);
    int i = 0;
    while (i < 22){
	std::cout << "i=" << i << ":" << bit_set.get(i) << std::endl;
	++i;
    }

    return 0;
}
