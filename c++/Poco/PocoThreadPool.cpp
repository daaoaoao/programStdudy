#include "Poco/ThreadPool.h"
#include "Poco/Runnable.h"
#include <iostream>
class HelloRunnable: public Poco::Runnable
{
    virtual void run()
    {
        std::cout << "Hello, myspace" << std::endl;
    }
};

int main(int argc, char** argv)
{
    Poco::ThreadPool pool(3, 6);//最少2个线程，最多6个线程
    HelloRunnable runnable;
    if( pool.available() > 0 )
    {
        pool.start(runnable);
    }
    pool.joinAll();
    return 0;
}