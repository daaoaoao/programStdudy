
#include <iostream>
#include <unistd.h>
#include <thread>
#include "Semaphore.h"
//定义函数A
//创建信号量
Semaphore sem(0);
void A(int i)
{

    std::cout << "A" << i << std::endl;
    sleep(1);
    //释放锁
    sem.Release();
}
//定义函数B
void B(int i)
{
    //获取锁
    sem.Acquire();
    std::cout << "B" << i << std::endl;
    sleep(1);
}
int main(void)
{

    //创建线程
    auto t1 = std::thread(A, 1);
    auto t2 = std::thread(B, 2);
    //A执行完毕后，让B执行
    t1.join();
    t2.join();
    return 0;
}