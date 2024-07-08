using System;

namespace Drived
{
    class Program
    {
        static void Main(string[] args)
        {
            // 类的虚函数等等
            Boss boss1 = new Boss(100,10000,20);
            boss1.Print();

            // 父类对象可以通过子类去创建
            Enemy enemy = new Boss(100,10000,30); //本质上是子类对象
            // enemy.Skill(); //无法调用，因为变量还是Enemy对象
            enemy.Move(); //因为是虚方法，所以在调用时会调用子类的方法
        }
    }
}
