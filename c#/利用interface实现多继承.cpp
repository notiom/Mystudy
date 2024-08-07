using System;

namespace InheritanceApplication
{
    class Shape
    {
        public void SetWidth(int w)
        {
            Width = w;
        }

        public void SetHeight(int h)
        {
            height = h;
        }
        protected int Width;
        protected int height;
    }

    // 基类，定义接口
    public interface PaintCost
    {
        int GetCost(int area);
    }

    class Rectangle : Shape , PaintCost
    {
        public int GetArea()
        {
            return Width * height;
        }
        
        public int GetCost(int area)
        {
            return area * 70;
        }
    }

    class RectangleTester
    {
        static void Main(string[] args)
        {
            Rectangle Rect = new Rectangle();
            Rect.SetWidth(5);
            Rect.SetHeight(10);
            int area = Rect.GetArea();

            //打印对象的面积
            Console.WriteLine($"总面积: {area}");
            Console.WriteLine($"油漆总成本: {Rect.GetCost(area)}");
            Console.ReadKey();
        }
    }
}

// interface接口的继承
// 其中一个interface继承另一个interface，之后在另一个类中实现
using System;

interface IParentInterface
{
    void ParentInterfaceMethod();
}

interface IMyInterface : IParentInterface
{
    void MethodToImplement();
}

class InterfaceImplementer : IMyInterface
{
    static void Main()
    {
        InterfaceImplementer iImp = new InterfaceImplementer();
        iImp.MethodToImplement();
        iImp.ParentInterfaceMethod();
    }

    public void MethodToImplement()
    {
        Console.WriteLine("MethodToImplement() called.");
    }

    public void ParentInterfaceMethod()
    {
        Console.WriteLine("ParentInterfaceMethod() called.");
    }
}
