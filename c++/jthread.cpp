#include <iostream>
#include "Semaphore.h"
#include "json.hpp"
#include <chrono>
#include <thread>
#include <utility>

void Test1(int n)
{
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Test1: " << n << std::endl;
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
void Test2(int n)
{
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Test2: " << n << std::endl;
		++n;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
class CTest1
{
public:
	void bar()
	{
		for (int i = 0; i < 5; ++i)
		{
			std::cout << "CTest1Test3: " << n << std::endl;
			++n;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
	int n = 0;
};

class baz
{
public:
	void operator()()
	{
		for (int i = 0; i < 5; ++i) {
			std::cout << "Thread 4 executing\n";
			++n;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
	int n = 0;
};
int main()
{
	int n = 0;
	CTest1 ct;
	baz b;
	std::jthread t0;//t0不是线程
	std::jthread t1(Test1, n + 1);//按值传递
	std::jthread t2a(Test2,std::ref(n));//按引用传递
	std::jthread t2b(std::move(t2a));//t2b现在运行Test2，t2a不再是线程
	std::jthread t3(&CTest1::bar,&ct);//t3在对象f上运行CTest1::bar()
	std::jthread t4(b);//t4在对象b上运行baz::operator()
	t1.join();
	t2b.join();
	t3.join();
	std::cout << "Final value of n is:" << n << "\n";
	std::cout << "Final value of class:n is:" << ct.n << "\n";
}