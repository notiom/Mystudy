#include <thread>
#include <iostream>
#include <mutex>

static int a = 0;
// 互斥锁
std::timed_mutex mtx5;
void func5_1()
{
    // for(int i = 0;i < 10000;i++)
    // {
    //     std::lock_guard<std::mutex> lg(mtx5);
    //     a += 1;
    // }
    for(int i = 0;i < 2;i++)
    {
        std::unique_lock<std::timed_mutex> lg(mtx5,std::defer_lock);
        // 只等待一段时间，超时便不再等待
        if(lg.try_lock_for(std::chrono::seconds(2)))
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            a += 1;
        }
    }
}

int main5()
{
    std::thread t1(func5_1);
    std::thread t2(func5_1);
    t1.join();
    t2.join();
    std::cout << "a = " << a << std::endl;
    return 0;
}

