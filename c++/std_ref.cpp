#include <iostream>
#include <memory>
#include <functional>
void Test(int &a,int &b,int &c)
{
    std::cout<<"a="<<a<<" b="<<b<<" c="<<c<<std::endl;
    ++a;
    ++b;
}

int main()
{
    int a=1,b=2,c=3;
    std::function<void(int&,int&,int&)> f=std::bind(Test,a,b,c);
    
    std::function<void()> f1=std::bind(Test,a,std::ref(b),std::ref(c));
    f1();
    a=10;b=20;c=30;
    f(a,b,c);
    //std::function<void()> f2=std::bind(Test,a,std::ref(b),std::cref(c));
    f1();
    std::cout<<"a="<<a<<" b="<<b<<" c="<<c<<std::endl;
}