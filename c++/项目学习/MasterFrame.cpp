// ThreadPool.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>

#include <chrono>
#include <thread>
#include <utility>
#include <functional>

#include <memory>
#include <deque>
class EventBase
{
public:
	virtual void Start()
	{
		std::cout << "事件触发" << std::endl;
	}
};
class Event1 :public EventBase
{
public:
	void Start()
	{
		std::cout << "Event1事件触发" << std::endl;
	}
};

class Event2 :public EventBase
{
public:
	void Start()
	{
		std::cout << "Event2事件触发" << std::endl;
	}
};
class MainDefine
{
	
public:
	MainDefine() {
		auto t = std::shared_ptr<Event1>(new Event1());
		eventDeque.push_back(t);
		eventDeque.push_back(std::shared_ptr<Event2>(new Event2()));

	}
	void EventStart(std::shared_ptr<EventBase>& eventBase)
	{
		eventBase->Start();
	}
	std::deque<std::shared_ptr<EventBase>> Get()
	{
		return eventDeque;
	}
private:
	std::deque<std::shared_ptr<EventBase>> eventDeque;
};


int main()
{
	MainDefine md;
	auto dq = md.Get();
	
	for (size_t i = 0; i < dq.size(); i++)
	{
		md.EventStart(dq[i]);
	}
}
