//
// Created by Administrator on 2022/5/23.
//

#ifndef UNTITLED_THREADPOOL__H
#define UNTITLED_THREADPOOL__H
#include <vector>
#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>

const int Max_Thread_Num=100;


template <typename T>
class ThreadPool_ {
public:
    ThreadPool_(int threadNum=1);
    ~ThreadPool_();
    bool AddTask(T *task);
    //工作线程
    static void *ThreadFunc(void *arg);
    void Start();
private:
    //工作线程
    std::vector<std::thread> m_threads;
    //任务队列
    std::queue<T *> m_tasks;
    //任务队列锁
    std::mutex m_mutex;
    //条件变量
    std::condition_variable m_condition;
    //线程池是否结束
    bool m_isExit;
};


#endif //UNTITLED_THREADPOOL__H
