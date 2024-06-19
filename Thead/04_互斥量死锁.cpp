#include <thread>
#include <iostream>
#include <mutex>

std::mutex m1,m2;

void func4_1()
{
    for(int i = 0;i < 50;i++)
    {
        m1.lock();
        std::cout << "func1->m1函数" << std::endl;
        m2.lock();
        std::cout << "func1->m2函数" << std::endl;
        m1.unlock();
        m2.unlock();
    } 
}

void func4_2()
{
    for(int i = 0;i < 50;i++)
    {
        // 死锁的产生
        // m2.lock(); 
        //std::cout << "func2->m2函数" << std::endl;
        // m1.lock();
        // std::cout << "func2->m1函数" << std::endl;
        m1.lock();
        std::cout << "func2->m1函数" << std::endl;
        m2.lock();
        std::cout << "func2->m2函数" << std::endl;
        m1.unlock();
        m2.unlock();
    }
}

int main4()
{
    // 1.互斥量死锁
    std::thread t1(func4_1);
    std::thread t2(func4_2);

    t1.join();
    t2.join();
    std::cout << "over" << std::endl;

    //2.解决方案
    //谁先获取m1谁就m1,m2一起获取
    return 0;
}

