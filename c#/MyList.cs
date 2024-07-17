using System;
using System.Collections;
using System.Collections.Generic;

// 自定义的List
namespace _Mylist
{
    class Mylist<T>
    {
        private T[] data = new T[0];
        
        private int count = 0; // 元素个数

        public int Capacity 
        { 
            get
            {
                return data.Length;
            }
        }

        public Mylist()
        {
            data = new T[4];
        }

        public Mylist(int capacity)
        {
            data = new T[capacity];
        }

        public void Add(T item)
        {
            // 添加元素之前,先判断元素是否已满,需要扩容

            if(data.Length == count)
            {
                T[] temp = new T[count * 2];
                Array.Copy(data, temp, count);
                data = temp;
            }
            data[count++] = item;
        }

        public int Count
        {
            get
            {
                return count;
            }
        }

        // 索引器
        public T this[int index]
        {
            get
            {
                if(index < 0 || index > count - 1)
                {
                    throw new ArgumentOutOfRangeException("索引参数超出范围了");
                }
                return data[index];
            }
            set
            {
                if(index < 0 || index > count - 1)
                {
                    throw new ArgumentOutOfRangeException("索引参数超出范围了");
                }
                data[index] = value;
            }
        }

        //插入数据
        public void Insert(int index, T item)
        {
            if(index < 0 || index > count - 1)
            {
                throw new ArgumentOutOfRangeException("索引参数超出范围了");
            }
            // 判断容量
            if(data.Length == count)
            {
                T[] temp = new T[count * 2];
                Array.Copy(data, temp, count);
                data = temp;
            }
            // 从后向前遍历依次插入
            for(int i = count - 1;i > index - 1;i--)
            {
                data[i + 1] = data[i];
            }
            data[index] = item;
            count++;
        }

        // 删除数据
        public void RemoveAt(int index)
        {
            if(index < 0 || index > count - 1)
            {
                throw new ArgumentOutOfRangeException("索引参数超出范围了");
            }
            for(int i = index; i < count - 1; i++)
            {
                data[i] = data[i + 1];
            }
            count--;
        }

        // 查找某个元素的索引位置
        public int IndexOf(T item)
        {
            int index = -1;
            for(int i = 0; i < count; i++)
            {
                if(item.Equals(data[i]))
                {
                    index = i;
                    break;
                }
            }
            return index;
        }

        // 排序
        public void Sort()
        {
            Array.Sort(data, 0, count);
        }
        public void ShowList()
        {
            for(int i = 0;i < count; i++)
            {
                Console.Write(data[i] + " ");
            }
            Console.WriteLine();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Mylist<int> li = new();
            Console.WriteLine(li.Count);
            Console.WriteLine(li.Capacity);
            li.Add(1);
            li.Add(2);
            li.Add(3);
            li.Add(4);
            li.Add(5);
            li.Insert(3,600);
            li.RemoveAt(2);
            li.ShowList();
            li.Sort();
            li.ShowList();
        }
    }
}
