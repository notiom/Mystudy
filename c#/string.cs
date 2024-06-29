// 一些方法的使用
// 1.str compare 与 + 拼接
using System;

namespace StringApplication
{
   class StringProg
   {
      static void Main(string[] args)
      {
         string str1 = "This is test";
         string str2 = "This is text";

         if (String.Compare(str1, str2) == 0)
         {
            Console.WriteLine(str1 + " and " + str2 +  " are equal.");
         }
         else
         {
            Console.WriteLine(str1 + " and " + str2 + " are not equal.");
         }
         Console.ReadKey() ;
      }
   }
}

// 2.str的Contains使用
using System;

namespace StringApplication
{
   class StringProg
   {
      static void Main(string[] args)
      {
         string str = "This is test";
         if (str.Contains("test"))
         {
            Console.WriteLine("The sequence 'test' was found.");
         }
         Console.ReadKey() ;
      }
   }
}

// 3.Substring的用法，取子字符串
using System; 
namespace StringApplication 
{
        class StringProg 
        { 
                static void Main(string[] args) 
                { 
                        string str = "Last night I dreamt of San Pedro"; 
                        Console.WriteLine(str); 
                        string substr = str.Substring(23); 
                        Console.WriteLine(substr); 
                        Console.ReadKey() ; 
                } 
        } 
}

// 4.字符串数组拼接，第一个参数为分隔符，第二个参数为数组
using System;

namespace StringApplication
{
   class StringProg
   {
      static void Main(string[] args)
      {
         string[] starray = new string[]{"Down the way nights are dark",
         "And the sun shines daily on the mountain top",
         "I took a trip on a sailing ship",
         "And when I reached Jamaica",
         "I made a stop"};

         string str = String.Join("\n", starray);
         Console.WriteLine(str);
         Console.ReadKey() ;
      }
   }
}
