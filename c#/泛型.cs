using System;
using System.Collections;
using System.Collections.Generic;

namespace 泛型
{
    class classA<T>
    {
        private T a;
        private T b;

        public classA(T a, T b)
        {
            this.a = a;
            this.b = b;
        }

        public T getSum()
        {
            dynamic num1 = a;
            dynamic num2 = b;
            dynamic res = num1 + num2;
            return (T)res;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            classA<int> a = new(2,8);
            Console.WriteLine(a.getSum());
        }
    }
}
