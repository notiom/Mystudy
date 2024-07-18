using System;
using System.Collections;
using System.Collections.Generic;
using System.Threading;

namespace 多线程
{
    class MyThread
    {
        static void Main(string[] args)
        {
            // 线程 使用委托
            ThreadStart start = new ThreadStart(ChildThreadMethod);

            Thread thread = new Thread(start);

            thread.Start();

            Console.WriteLine("Main Thread running...");

            Thread.Sleep(500);

        }

        private static void ChildThreadMethod()
        {
            Console.WriteLine("Child Thread running...");
        }
    }
}
