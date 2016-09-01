#include <iostream>
#include <map>

using namespace std;
typedef void* (*getInstance) ();
map<string, getInstance> g_symble_index;

class Base{
    public:
	virtual void print() = 0;
};

class A : public Base{
    public:
	void print(){ cout << "A" << endl;}
};

class B : public Base{
    public:
	void print(){ cout << "B" << endl;}
};

class Regist{
    public:
	Regist(string func_name, getInstance func){g_symble_index[func_name] = func;}
};

#define DEFINEFUNC(className) void* get##className##Instance(){return (new className);}
#define REGISTER(className) Regist Regist_##className(#className, get##className##Instance);
DEFINEFUNC(A);
REGISTER(A);
DEFINEFUNC(B);
REGISTER(B);

int main(int argc, char **argv)
{
    string func_name(argv[1]);
    Base *pBase = (Base*)g_symble_index[func_name]();
    pBase->print();
    return 0;
}
