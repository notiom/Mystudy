#include <thread>
#include <iostream>
#include <mutex>
#include <string>
//单例模式
//某些函数在多个线程里只被执行一次

class Log
{
public:

    //构造函数
    Log() {};
    // 禁用拷贝构造函数
    Log(const Log& log) = delete;
    Log& operator=(const Log& log) = delete;

    static Log& GetInstance()
    {
        // static Log log; //设计模式 懒汉模式
        // static Log* log = nullptr;
        // if(!log) log = new Log(); //设计模式 饿汉模式
        // return* log;
        std::call_once(once,[](){log = new Log();});
        return *log;
    }
    void WriteLog(std::string msg)
    {
        std::cout << __TIME__ << ' ' << msg << std::endl;
    }
private:
    // 静态成员变量需要在类外有一个明确的定义
    static Log* log;
    static std::once_flag once;
};

//初始化静态成员变量
Log* Log::log = nullptr;
std::once_flag Log::once;

void print_error()
{
    Log::GetInstance().WriteLog("error");
}
int main6()
{
    std::thread t1(print_error);
    std::thread t2(print_error);
    t1.join();
    t2.join();

    // 问题1 : 当线程1和线程2同时判断log是否为null时，都判断为null，对象被创建两次
    // 解决方案 : call_once

    return 0;
}