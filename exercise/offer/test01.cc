#include <iostream>
using namespace std;

class A{
    public:
	A(int num = 0) : val(num) {cout << "in A()" << endl;}
	A(const A &a) {val = a.val; cout << "in A(A &a)" << endl;}
	A& operator=(A& a) {val = a.val; cout << "in =" << endl; return *this;}
	ostream& operator<< (ostream& os) {os << val << endl;}

    private:
	int val;
};

int main()
{
    A a(20);
    A b = a;
    A c;
    c = a;

    a << cout;
    b << cout;
    c << cout;

    return 0;
}
