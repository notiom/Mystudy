#include <thread>
#include <iostream>
#include <mutex>

static int a = 0;
// 互斥锁
std::mutex mtx;
void func3_1()
{
    for(int i = 0;i < 10000;i++)
    {
        mtx.lock();
        a += 1;
        mtx.unlock();
    }
}

int main3()
{
    std::thread t1(func3_1);
    std::thread t2(func3_1);
    t1.join();
    t2.join();
    std::cout << "a = " << a << std::endl;
    return 0;
}