#include <thread>
#include <iostream>
#include <mutex>
#include <string>
#include <condition_variable>
#include <queue>
#include <vector>
//手撕线程池
class ThreadPool
{
public:
    ThreadPool(int numThreads) : stop(false)
    {
        for(int i = 0;i < numThreads;i++)
        {
            // emplace_back和push_back的区别
            // empalce是直接在vec的末尾构造一个对象
            // push是新创建一个临时对象，在调用拷贝构造或者移动
            // 如果对象已经被创建好，那二者几乎无区别
            threads.emplace_back([this] 
            {
                while(1)
                {
                    std::unique_lock<std::mutex> lock(mtx);
                    condition.wait(lock,[this] 
                    {
                        return !tasks.empty() || stop;
                    });
                    if (stop && tasks.empty())
                    {
                        return;
                    }
                    // move函数可以将一个对象赋予到另一个对象中，并销毁原有的对象
                    std::function<void()>  task(std::move(tasks.front()));
                    tasks.pop();
                    lock.unlock();
                    task();
                }
            });
        }
    }   
    // 析构函数
    ~ThreadPool()
    {
        std::unique_lock<std::mutex> lock(mtx);
        stop = true;

        condition.notify_all();
        for(auto& t: this->threads)
        {
            t.join();
        }
    }
    template<class F,class... Args>
    // 右值引用也叫万能引用
    void enqueue(F &&f,Args&&... args)
    {
        //将这些参数预先绑定在task中
        //c++完美转发
        std::function<void()>task = 
            std::bind(std::forward<F>(f), std::forward<Args>(args)...);

        std::unique_lock<std::mutex> lock(mtx);
        tasks.emplace(std::move(task));

        condition.notify_one();
    }
    
private:
    // 线程数组
    std::vector<std::thread> threads;
    //任务队列
    std::queue<std::function<void()>> tasks;

    std::mutex mtx;
    std::condition_variable condition;

    //定义线程池什么时候终止
    bool stop;
};

int main()
{
    ThreadPool pool(4);

    for(int i = 0; i < 2;i++)
    {
        pool.enqueue([i] 
        {
            std::cout << "tasks: " << i << "is running" << std::endl;
            //休息一秒
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "tasks: " << i << "is done" << std::endl;
        });
    }
    return 0;
}