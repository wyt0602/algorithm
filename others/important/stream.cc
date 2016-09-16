#include <sstream>
#include <string>

#include <iostream>
#include <vector>

using namespace std;

istream& getStream(istream &in, istringstream &stream)
{
    string line;
    auto &ret = getline(in, line);
    istringstream temp(line);
    stream = temp;
    
    return ret;
}

int main()
{
    istringstream in;
    while (getStream(cin, in)){
	vector<string> words;
	string temp;
	while (in >> temp){
	    words.push_back(temp);
	}
	for (auto item : words)
	    cout << item << endl;

	words.clear();
    }
}
