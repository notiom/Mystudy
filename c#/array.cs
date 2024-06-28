// int [] marks = new int[5]  { 99,  98, 92, 97, 95}; // 初始化数组

using System;
namespace ArrayApplication
{
    class MyArray
    {
        static void Main(string[] args)
        {
            int [] n = new int[10];
            for(int i = 0;i < 10;i++)
            {
                n[i] = i + 100;
            }

            foreach (int j in n)
            {
                Console.WriteLine("Element[{0}] = {1}",j - 100,j);
            }
            Console.ReadKey();
        }
    }
}

// 多维数组初始化 
/* 
int [,] a = new int [3,4] {
 {0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
 {4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
 {8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
}; 
*/

// 二维数组
using System;

namespace ArrayApplication
{
    class MyArray
    {
        static void Main(string[] args)
        {
            /* 一个带有 5 行 2 列的数组 */
            int[,] a = new int[5, 2] {{0,0}, {1,2}, {2,4}, {3,6}, {4,8} };

            int i, j;

            /* 输出数组中每个元素的值 */
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 2; j++)
                {
                    Console.WriteLine("a[{0},{1}] = {2}", i, j, a[i,j]);
                }
            }
           Console.ReadKey();
        }
    }
}

// 参数数组，在传参时可以传入一组元素数组
using System;

namespace ArrayApplication
{
   class ParamArray
   {
      public int AddElements(params int[] arr)
      {
         int sum = 0;
         foreach (int i in arr)
         {
            sum += i;
         }
         return sum;
      }
   }
      
   class TestClass
   {
      static void Main(string[] args)
      {
         ParamArray app = new ParamArray();
         int sum = app.AddElements(512, 720, 250, 567, 889);
         Console.WriteLine("总和是： {0}", sum);
         Console.ReadKey();
      }
   }
}
