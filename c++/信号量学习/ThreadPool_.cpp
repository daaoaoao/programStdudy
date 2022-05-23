//
// Created by Administrator on 2022/5/23.
//

#include "ThreadPool_.h"

template<typename T>
ThreadPool_<T>::ThreadPool_(int threadNum):m_isExit(false)
{
    if(threadNum<=0||threadNum>Max_Thread_Num) {
        throw std::exception();
    }
    for(int i=0;i<threadNum;i++) {
        m_threads.emplace_back(ThreadFunc,this);
    }
}

template<typename T>
inline ThreadPool_<T>::~ThreadPool_() {
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_isExit=true;
    }
    m_condition.notify_all();
    for(auto &thread:m_threads) {
        thread.join();
    }
}
//添加任务
template<typename T>
bool ThreadPool_<T>::AddTask(T *task) {
    //添加任务加锁
    std::unique_lock<std::mutex> lock(m_mutex);
    if(m_isExit) {
        return false;
    }
    m_tasks.push(task);
    lock.unlock();
    m_condition.notify_one();
    return true;
}

template<typename T>
void ThreadPool_<T>::Start() {
    while(!m_isExit) {
        std::unique_lock<std::mutex> lock(this->m_mutex);
        //队列为空，等待
        while(m_tasks.empty()&&!m_isExit) {
            this->m_condition.wait(lock);
        }
        T *task=this->m_tasks.front();
        this->m_tasks.pop();
        if(task) {
            task->run();
        }
    }
}
//线程函数
template<typename T>
void *ThreadPool_<T>::ThreadFunc(void *arg) {
   ThreadPool_ *pool=(ThreadPool_ *)arg;
   pool->Start();
   return pool;
}



