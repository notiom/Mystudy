using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace _stringbuilder
{
    class MyStringBuilder
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder("www.baidu.com");
            // 增
            sb.Append("123456");
            sb.Insert(4,"6666");
            // 删
            sb.Remove(4,2);
            // 改
            sb.Replace("66","77");
            Console.WriteLine(sb);
        }
    }
}
