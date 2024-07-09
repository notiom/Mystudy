// 抽象类和密封类
// 抽象类中并没有函数实现，也不可以创建实例
using System;

namespace Abstract
{
    abstract class Example
    {
        // 抽象类无法创建实例
        private int hp;
        private int speed;
        public abstract void Move();
    }

    // 密封类不能被继承，密封方法不能被重写
    sealed class SealedExample
    {
        // 不能被继承
    }
    class Boss : Example
    {
        public sealed override void Move()
        {
            // 该方法不能再次被重写
            Console.WriteLine("Boss");
        }

        static void Main(string[] args)
        {
            Boss boss = new();
            boss.Move(); // 子类可以调用
        }
    }
}
