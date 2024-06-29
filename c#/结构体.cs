using System;

// 结构声明
struct MyStruct
{
    public int X;
    public int Y;

    // 结构不能有无参数的构造函数
    // public MyStruct()
    // {
    // }

    // 有参数的构造函数
    public MyStruct(int x, int y)
    {
        X = x;
        Y = y;
    }

    // 结构不能继承
    // struct MyDerivedStruct : MyBaseStruct
    // {
    // }
}

// 类声明
class MyClass
{
    public int X;
    public int Y;

    // 类可以有无参数的构造函数
    public MyClass()
    {
    }

    // 有参数的构造函数
    public MyClass(int x, int y)
    {
        X = x;
        Y = y;
    }

    // 类支持继承
    // class MyDerivedClass : MyBaseClass
    // {
    // }
}

class Program
{
    static void Main()
    {
        // 结构是值类型，分配在栈上
        MyStruct structInstance1 = new MyStruct(1, 2);
        MyStruct structInstance2 = structInstance1; // 复制整个结构

        // 类是引用类型，分配在堆上
        MyClass classInstance1 = new MyClass(3, 4);
        MyClass classInstance2 = classInstance1; // 复制引用，指向同一个对象

        // 修改结构实例不影响其他实例
        structInstance1.X = 5;
        Console.WriteLine($"Struct: {structInstance1.X}, {structInstance2.X}");

        // 修改类实例会影响其他实例
        classInstance1.X = 6;
        Console.WriteLine($"Class: {classInstance1.X}, {classInstance2.X}");
    }
}
