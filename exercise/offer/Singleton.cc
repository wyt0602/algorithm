#include <iostream>
#include <thread>
#include <mutex>
#include <assert.h>

class Singleton{
    private:
	Singleton(int num) : id(num) {}

    public:
	static void init();
	int getId() {return id;}
	static Singleton& getInstance();

    private:
	static std::once_flag once;
	static Singleton *ps;
	int id;
};

std::once_flag Singleton::once;
Singleton* Singleton::ps = NULL;
void Singleton::init()
{
    ps = new Singleton(0);
    ps->id++;
}
Singleton& Singleton::getInstance()
{
    if (ps != NULL)
	return *ps;
    else
	std::call_once(once, Singleton::init);

    assert(ps != NULL);
    return *ps;
}


int main()
{
    std::thread threads[10];
    for (int i=0; i<10; ++i)
	threads[i] = std::thread(Singleton::getInstance);

    for (auto &th : threads) th.join();

    std::cout << (Singleton::getInstance()).getId() << std::endl;

    return 0;
}
