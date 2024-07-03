// sortedlist是按照某种规则排序过的字典
// 可以使用重写比较函数
using System;
using System.Collections;

namespace CollectionsApplication
{
    class CustomComparer : IComparer
    {
        public int Compare(object x, object y)
        {
            // 假设键是字符串类型，可以根据需要自定义比较逻辑
            string key1 = x as string;
            string key2 = y as string;
    
            // 比较逻辑：按键的长度排序，如果长度相同则按字典顺序排序
            int lengthComparison = key1.Length.CompareTo(key2.Length);
            if (lengthComparison == 0)
            {
                // 左小于右，则返回负数
                return key1.CompareTo(key2);
            }
            return lengthComparison;
        }
    }
   class Program
   {
      static void Main(string[] args)
      {
         SortedList sl = new SortedList();

         sl.Add("001", "Zara Ali");
         sl.Add("002", "Abida Rehman");
         sl.Add("003", "Joe Holzner");
         sl.Add("004", "Mausam Benazir Nur");
         sl.Add("005", "M. Amlan");
         sl.Add("006", "M. Arif");
         sl.Add("007", "Ritesh Saikia");

         if (sl.ContainsValue("Nuha Ali"))
         {
            Console.WriteLine("This student name is already in the list");
         }
         else
         {
            sl.Add("008", "Nuha Ali");
         }

         // 获取键的集合 
         ICollection key = sl.Keys;

         foreach (string k in key)
         {
            Console.WriteLine(k + ": " + sl[k]);
         }
      }
   }
}
