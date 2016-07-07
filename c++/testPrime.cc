
#include <stdio.h>
#include <algorithm>
#include "util/Prime.h"

class Print
{
    public:
	void operator()(int number)
	{
	    if (format != 0 && format%6 == 0)
		printf("\n");

	    printf("%8d ", number);
	    ++format;
	}

    private:
	static int format;
};
int Print::format = 0;

int main()
{
    std::shared_ptr<std::vector<int>> result;
    Prime prime;

    /*
    if (prime.isPrime(7246521))
	printf("is Prime!\n");
    else
	printf("is not Prime!\n");

    */
    
    result = prime.getPrime(7246525);
    std::vector<int>::iterator begin = result->begin();
    std::vector<int>::iterator end = result->end();

    for_each(begin, end, Print());
    printf("\n");

    return 0;
}
