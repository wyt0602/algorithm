
#include <iostream>
#include "util/BitArray.h"

int main()
{
    BitArray bit_set = BitArray(65, true);
    bit_set.fill(1, 64, false);
    bit_set.set(65, true);

   // bit_set.setAll(true);
    int value = bit_set.getFirstNonZero();
    std::cout << "firstNonZero=" << value << std::endl;
    //bit_set.set(value, false);
    int i = 1;
    while (i < 6){
	std::cout << "i=" << i << ":" << bit_set.get(i) << std::endl;
	++i;
    }

    return 0;
}
