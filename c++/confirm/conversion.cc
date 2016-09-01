#include <iostream>
#include <string>
using namespace std;

class Int
{
    public:
       	Int(string str) : word(str){}
	Int(const Int& my_word) {word = my_word.word; cout << "in copy" << endl;}
	Int& operator=(const Int& my_word) {word = my_word.word; cout << "in =" << endl;}
    public:
	string word;
};


int main(int argc, char **argv)
{
    Int j("world");
    Int i = string("hello");
    i = j;

    cout << i.word <<" "<< j.word << endl;

    return 0;
}
