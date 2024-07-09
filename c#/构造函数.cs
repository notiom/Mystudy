using System;

class BaseClass
{
    private int hp;
    private int speed;

    public BaseClass(int hp, int speed)
    {
        this.hp = hp;
        this.speed = speed;
    }
    public BaseClass()
    {
        Console.WriteLine("构造函数:BaseClass constructor");
    }
}

class DerivedClass : BaseClass
{
    private int attack; //字类特有的属性
    public DerivedClass():base() // 调用父类的构造函数,默认也会调用父类的构造函数
    {
        Console.WriteLine("构造函数:DerivedClass constructor");
    }

    public DerivedClass(int hp,int speed,int attack):base(hp,speed) //将hp和speed传递给base中
    {
        this.attack = attack;
    }
}

class Program
{
    static void Main(string[] args)
    {
        DerivedClass derivedClass = new();
    }
}
