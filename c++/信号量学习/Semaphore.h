//
// Created by Administrator on 2022/5/23.
//

#ifndef UNTITLED_SEMAPHORE_H
#define UNTITLED_SEMAPHORE_H
#include <iostream>
#include <mutex>
#include <condition_variable>

class Semaphore {
public:
    Semaphore(int num=0);
    ~Semaphore();
    //设置锁数量
    void SetAvailable(int num);
    //获取锁
    void Acquire(int num=1);
    //释放锁
    void Release(int num=1);
    //释放锁全部
    void ReleaseAll();
    //可获取锁数量
    int Available();

private:
    std::mutex mutex_;//锁
    int mutexCount_;//并发锁数量
    std::condition_variable cond_;//条件变量

};

#endif //UNTITLED_SEMAPHORE_H
