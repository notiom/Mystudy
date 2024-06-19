#include <thread>
#include <iostream>
#include <mutex>
#include <string>
#include <condition_variable>
#include <queue>

// 生产者与消费者模型
// 生产者加任务到任务队列，消费者去取出这些任务
std::queue<int> g_queue;
std::condition_variable g_cv;
//定义一个锁
std::mutex g_mutex;

void Producer()
{
    // 定义生产者
    for(int i = 0; i < 100;i++)
    {
        std::unique_lock<std::mutex> lock(g_mutex);
        g_queue.push(i);
        // 通知消费者来取任务
        g_cv.notify_one();
        std::cout << "Producer : " << i << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::microseconds(100)); //延时100ms
}

void Consumer()
{   
    // 定义消费者
    while(1)
    {
        std::unique_lock<std::mutex> lock(g_mutex);
        //如果队列为空，就要等待
        g_cv.wait(lock,[]() {return !g_queue.empty();});
        int task = g_queue.front();
        g_queue.pop();

        std::cout << "Consumer : " << task << std::endl;

    }
}

int main7()
{
    std::thread t1(Producer);
    std::thread t2(Consumer);
    t1.join();
    t2.join();
    return 0;
}


