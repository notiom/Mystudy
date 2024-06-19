#include <thread>
#include <iostream>
#include <string>

void printHelloWorld(std::string msg)
{
    for(int i = 0;i < 10000;i++)
    {
        std::cout << msg << std::endl;
    }

}
int main1()
{
    // 1. 创建线程
    std::thread thread1(printHelloWorld,"hello Thread");

    // 2.主线程等待线程执行完毕
    // thread1.join();

    // 3.分离子线程和主线程
    // thread1.detach();

    //4.joinable判断是否可以使用join
    bool IsJoin = thread1.joinable();

    if(IsJoin)
    {
        // join会阻塞当前主线程
        thread1.join();
    }
    std::cout << "over" << std::endl;
    return 0;

}