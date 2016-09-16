#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void getPrimeArray(vector<int> &prime, int range)
{
    vector<bool> p_flag(range + 1, true);
    p_flag[0] = false;
    p_flag[1] = false;

    for (int i = 2; i <= sqrt(range); ++i){
	if (p_flag[i] == false)
	    continue;
	int j = i + 1;
	while (j <= range){
	    if (j % i == 0)
		p_flag[j] = false;
	    ++j;
	}
    }

    int index = 0;
    for (; index <= range; ++index){
	if (p_flag[index] == true)
	    prime.push_back(index);
    }
}

int main()
{
    int range;
    while (cin >> range){
	vector<int> prime;
	getPrimeArray(prime, range);
	for (auto item : prime){
	    cout << item << endl;
	}
	prime.clear();
    }

    return 0;
}
