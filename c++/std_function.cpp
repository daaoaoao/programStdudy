#include <bits/stdc++.h>

typedef std::function<void(int)> func;


void Test(int a)
{
    std::cout << a << std::endl;
}
//lambda
auto lambda = [](int a) {
    std::cout << a << std::endl;
};
//functor仿函数
class Functor
{
public:
    void operator()(int a)
    {
        std::cout << a << std::endl;
    }
};
//类的成员函数和静态成员函数
class TestClass
{
public:
    void Test(int a)
    {
        std::cout << a << std::endl;
    }
    static void Test2(int a)
    {
        std::cout << a << std::endl;
    }
};
//多个参数
void Test1(int a, int b)
{
    std::cout << a << " " << b << std::endl;
}

int main()
{
    //封装普通函数
    func f = Test;
    f(1);
    //封装lambda
    func f2 = lambda;
    f2(2);
    //封装类的成员函数
    TestClass tc;
    func f3 = std::bind(&TestClass::Test, &tc, std::placeholders::_1);
    f3(3);
    //封装类的静态成员函数
    func f4 = std::bind(&TestClass::Test2, std::placeholders::_1);
    f4(4);
    //封装多个参数
    auto func2 = std::bind(Test1, std::placeholders::_1, std::placeholders::_2);
    func2(5, 6);
    return 0;
}