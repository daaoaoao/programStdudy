//
// Created by Administrator on 2022/5/23.
//

#include "Semaphore.h"

Semaphore::Semaphore(int num) :mutexCount_(num){

}

Semaphore::~Semaphore() {

}

void Semaphore::SetAvailable(int num) {
    std::unique_lock<std::mutex> lock(mutex_);
    mutexCount_=num;

}

void Semaphore::Acquire(int num) {
    std::unique_lock<std::mutex> lock(mutex_);
    mutexCount_-=num;
    if(mutexCount_<0)
    {
        cond_.wait(lock);//阻塞
    }
}

void Semaphore::Release(int num) {
    std::unique_lock<std::mutex> lock(mutex_);

    if(num+mutexCount_>=0)
    {
        cond_.notify_all();
        mutexCount_+=num;
    }
    else
    {
        for(int i=0;i<num;i++)
        {
            cond_.notify_one();
            mutexCount_++;
        }

    }
}

//释放锁全部
void Semaphore::ReleaseAll()
{
    std::unique_lock<std::mutex> lock(mutex_);
    cond_.notify_all();
    mutexCount_ = 0;
}

//可获取锁数量
int Semaphore::Available()
{
    std::unique_lock<std::mutex> lock(mutex_);
    return mutexCount_;
}
