#include <iostream>
#include <thread>

using namespace std;

class A
{
public:
    void hello()
    {
        std::cout << "Hello World!" << std::endl;
    }
};
void foo(int& x)
{
    x += 1;
    cout << "x = " << x << endl;
}

void too(int *x)
{
    *x += 1;
    cout << "x = " << *x << endl;
}
int main2()
{
    int a = 1;
    // 1. ref解决了传递不了值引用的问题
    thread t1(foo, ref(a));
    t1.join();

    // 2. 解决方法2，指针
    int *ptr = new int(1);
    thread t2(too, ptr);
    //在线程刚执行完毕后就马上释放内存，打印出的结果就会不确定
    delete ptr;

    t2.join();

    //3. 类函数指针
    A act;
    thread t3(&A::hello, &act);
    t3.join();

    //4. 智能指针

    shared_ptr<A> b = make_shared<A>();
    //指针本身就是地址，无需取地址
    thread t4(&A::hello, b);
    t4.join();
    return 0;
}